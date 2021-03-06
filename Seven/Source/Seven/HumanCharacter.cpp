// Fill out your copyright notice in the Description page of Project Settings.

#include "HumanCharacter.h"
#include "Runtime/Engine/Classes/GameFramework/CharacterMovementComponent.h"
#include "Weapon.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "MyProjectiles.h"


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

void AHumanCharacter::BeginPlay()
{
	Super::BeginPlay();
}
void AHumanCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
		
	if (isReactionAnimationPlaying())
	{
		canWalk = true;
	}
	else
	{
		canWalk = !isMontageplaying;  // TO DO
	}
	

	if (canWalk)
		GetCharacterMovement()->JumpZVelocity = 600;
	else
		GetCharacterMovement()->JumpZVelocity = 0.f;

	if (MyWeapon == nullptr) return;
	MyWeapon->canApplyDamage = canApplyDamage;
	
}



void AHumanCharacter::applyWeaponDamage(AWeapon * weapon, AHumanCharacter *player_c, AHumanCharacter *enemy_c)
{
	if (!weapon) return;
	if (!player_c) return;
	if (!enemy_c)return;

	if (weapon->canApplyDamage == true)
	{

			//weapon->setDamage(currentHealth,player_c,enemy_c);
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
	target = player_c;
			

}

bool AHumanCharacter::isReactionAnimationPlaying()
{
	if (reaction_back == true || reaction_front == true || reaction_left == true || reaction_right == true)
		return true;

	return false;
}

void AHumanCharacter::applyProjectileDamage(float damage)
{
	currentHealth = currentHealth - damage;
	animInstance->Montage_Play(reactMontage[1], 1.3f);

}






void AHumanCharacter::throwProjectiles()
{
	
	if (!projectileBlueprint)
	{
		UE_LOG(LogTemp,Warning,TEXT("no projectile identified"))
			return;
	}
	FVector spawnlocation = GetMesh()->GetSocketLocation(FName("Head")) + GetActorForwardVector() * 100;
	auto projectiles =GetWorld()->SpawnActor<AMyProjectiles>
		(
			projectileBlueprint,
			spawnlocation,
			GetMesh()->GetRightVector().Rotation()
		);
	
	if (target == nullptr)
	{
		projectiles->launchProjectile(ProjectilelaunchSpeed);
		UE_LOG(LogTemp, Warning, TEXT("no target called"));
	}
	else
	{
		FString name = target->GetName();
		UE_LOG(LogTemp, Warning, TEXT("name is %s"), *name);
		projectiles->launchProjectile(ProjectilelaunchSpeed, OwnerisPlayer, target);
	}
	
}



