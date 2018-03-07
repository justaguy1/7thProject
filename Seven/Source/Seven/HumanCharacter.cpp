// Fill out your copyright notice in the Description page of Project Settings.

#include "HumanCharacter.h"
#include "Runtime/Engine/Classes/GameFramework/CharacterMovementComponent.h"
#include "Weapon.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"

AHumanCharacter::AHumanCharacter()
{
	currentHealth = 100;
	maxHealth = 100;
	health = currentHealth / maxHealth;

	currentStamina = 100;
	maxStamina = 100;
	stamina = currentStamina / maxStamina;

	currentMana = 100;
	maxMana = 100;
	mana = currentMana / maxMana;

	selfForwardDirection = FVector(0, 0, 0);
	opponentForwardDirection = selfForwardDirection;

	
}
void AHumanCharacter::SetupPlayerInputComponent(UInputComponent * PlayerInputComponent)
{
	check(PlayerInputComponent);
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("AttackL", IE_Pressed, this, &AHumanCharacter::AttackL);
	PlayerInputComponent->BindAction("AttackR", IE_Pressed, this, &AHumanCharacter::AttackR);
	PlayerInputComponent->BindAction("SwapWeaponL", IE_Pressed, this, &AHumanCharacter::swapL);

	
}
void AHumanCharacter::BeginPlay()
{
	Super::BeginPlay();
}
void AHumanCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (animInstance != nullptr)
		isMontageplaying = animInstance->IsAnyMontagePlaying();
		
	if (isReactionAnimationPlaying())
	{
		canWalk = true;
	}
	else
	{
		canWalk = !isMontageplaying;
	}
	

	if (canWalk)
		GetCharacterMovement()->JumpZVelocity = 600;
	else
		GetCharacterMovement()->JumpZVelocity = 0.f;

	if (MyWeapon == nullptr) return;
	MyWeapon->canApplyDamage = canApplyDamage;


	//UE_LOG(LogTemp, Warning, TEXT("hit registered %f"), MyWeapon->noOfHitregistered);
	
}

void AHumanCharacter::swapL()
{


}


void AHumanCharacter::applyWeaponDamage(AWeapon * weapon, AHumanCharacter *player_c, AHumanCharacter *enemy_c)
{
	if (!weapon) return;
	if (!player_c) return;
	if (!enemy_c)return;

	UE_LOG(LogTemp, Warning, TEXT("current health : %f"), currentHealth);


	if (weapon->canApplyDamage == true)
	{

			weapon->setDamage(currentHealth,player_c,enemy_c);
			UE_LOG(LogTemp,Warning,TEXT("called"))
			enemy_c->isAngry = true;
		if (reaction_right == true)
			animInstance->Montage_Play(reactMontage[1], 1.3f);
		else if (reaction_left == true)
			animInstance->Montage_Play(reactMontage[0], 1.3f);
		else if (reaction_front == true)
			animInstance->Montage_Play(reactMontage[0], 1.3f);
		else if (reaction_back == true)
			animInstance->Montage_Play(reactMontage[1], 1.3f);

	
		
	}

	if (currentHealth <= 0)
		Destroy(true);
}

bool AHumanCharacter::isReactionAnimationPlaying()
{
	if (reaction_back == true || reaction_front == true || reaction_left == true || reaction_right == true)
		return true;

	return false;
}




void AHumanCharacter::AttackL()
{
	UE_LOG(LogTemp, Warning, TEXT("Attack left"));
	if (!animInstance)
	{
		UE_LOG(LogTemp, Warning, TEXT("Some shit happened"));
		return;
	}
	if(!IsInAir)
	animInstance->Montage_Play(attackMontage[0]);
	
	
	
}

void AHumanCharacter::AttackR()
{
	UE_LOG(LogTemp, Warning, TEXT("Attack Right"));
	if (!animInstance)
	{
		UE_LOG(LogTemp, Warning, TEXT("Some shit happened"));
		return;
	}

	if (!IsInAir)
	animInstance->Montage_Play(attackMontage[1]);
}



