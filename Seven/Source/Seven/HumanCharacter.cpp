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
	canWalk = !isMontageplaying;

	if (canWalk)
		GetCharacterMovement()->JumpZVelocity = 600;
	else
		GetCharacterMovement()->JumpZVelocity = 0.f;

	if (MyWeapon == nullptr) return;
	MyWeapon->canApplyDamage = canApplyDamage;
	
}

void AHumanCharacter::swapL()
{
	

}

void AHumanCharacter::applyWeaponDamage(AWeapon * weapon)
{
	float previousHealth = currentHealth;
	if (!weapon) return;

	weapon->noOfHitregistered++;
	if (weapon->noOfHitregistered == 1)
	{
	
	weapon->setDamage(currentHealth);

	UE_LOG(LogTemp, Warning, TEXT("current health : %f"), currentHealth);
	if (previousHealth != currentHealth && isMontageplaying == false && weapon->canApplyDamage == true)
		animInstance->Montage_Play(reactMontage[0], 1.3f);
	}
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


