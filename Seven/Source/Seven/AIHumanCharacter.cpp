// Fill out your copyright notice in the Description page of Project Settings.

#include "AIHumanCharacter.h"
#include "Weapon.h"
#include "PlayerHumanCharacter.h"
#include "Engine/World.h"

AAIHumanCharacter::AAIHumanCharacter()
{
	previous_health = currentHealth;
	originalpos = GetActorLocation();

}
void AAIHumanCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AAIHumanCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	AttackPlayer();
	removePlayer();
	setPlayerHuds();
	
}
void AAIHumanCharacter::removePlayer()
{
	if (currentHealth <= 0)
	{
		APlayerHumanCharacter *player = Cast<APlayerHumanCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
		if (MyWeapon)
		{
			UE_LOG(LogTemp,Warning,TEXT("weapon is valid "))
			MyWeapon->ispossessed = false;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("weapon is not valid "))
		}
		if (player)
		{
			player->gainXP(this);
			Destroy();
		}
		

	}
}
void AAIHumanCharacter::AttackPlayer()
{
	bool isReloaded = (FPlatformTime::Seconds() - lastAttackedTime) > delayTimeInSeconds;
	if (isReloaded)
	{
		UE_LOG(LogTemp, Warning, TEXT("distance %f "), playerDistance)
			lastAttackedTime = FPlatformTime::Seconds();
	}
	
		if (!MyWeapon) return;
		
	if (playerDistance > 4000.f)
	{
		PlayerIsInSight = false;
		isAngry = false;

	}
	if (playerDistance < 200)
	{
		//if (isMontageplaying) return;
		/*if (!isMontageplaying)
			animInstance->Montage_Play(attackMontage[0]);*/
		
	}


	if (PlayerIsInSight == true)
		isAngry = true;

	
}

void AAIHumanCharacter::setPlayerHuds()
{
	health = currentHealth / maxHealth;
	stamina = currentStamina / maxStamina;
	mana = currentMana / maxMana;

	
}




