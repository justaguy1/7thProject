// Fill out your copyright notice in the Description page of Project Settings.

#include "HumanCharacter.h"


void AHumanCharacter::SetupPlayerInputComponent(UInputComponent * PlayerInputComponent)
{
	check(PlayerInputComponent);
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("AttackL", IE_Pressed, this, &AHumanCharacter::AttackL);
	PlayerInputComponent->BindAction("AttackR", IE_Pressed, this, &AHumanCharacter::AttackR);
	
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

	
}

void AHumanCharacter::AttackL()
{
	UE_LOG(LogTemp, Warning, TEXT("Attack left"));
	if (!animInstance)
	{
		UE_LOG(LogTemp, Warning, TEXT("Some shit happened"));
		return;
	}
	
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

	animInstance->Montage_Play(attackMontage[1]);
}


