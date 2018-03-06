// Fill out your copyright notice in the Description page of Project Settings.

#include "AIHumanCharacter.h"

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

	if (playerDistance > 2000.f)
	{
		PlayerIsInSight = false;
		isAngry = false;
		
	}
	if (playerDistance <200)
	{
		if (isMontageplaying) return;
		animInstance->Montage_Play(attackMontage[0]);
	}
		
	if (PlayerIsInSight == true)
		isAngry = true;

}




