// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerHumanCharacter.h"
#include "AIHumanCharacter.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "EngineUtils.h"


void APlayerHumanCharacter::BeginPlay()
{
	Super::BeginPlay();
	OwnerisPlayer = true;
}

void APlayerHumanCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	setPlayerHuds();
	
}

AAIHumanCharacter * APlayerHumanCharacter::checkForAllEnemy()
{
	TArray<AAIHumanCharacter*> foundActor;


	for (TActorIterator<AAIHumanCharacter> enemyToFind(GetWorld()); enemyToFind; ++enemyToFind)
	{

		return *enemyToFind;
		
	}
	return nullptr;
}

void APlayerHumanCharacter::TargetEnemy()
{
	AAIHumanCharacter *tempEnemy = enemy;
	distance = 1000;
	if (enemy)
		enemy->targeted = false;
	TArray<AAIHumanCharacter*> foundActor;
	
	
	for (TActorIterator<AAIHumanCharacter> enemyToFind(GetWorld()); enemyToFind; ++enemyToFind)
	{
		
		enemyToFind->targeted = false;
		float tempDistance =FVector::Distance(enemyToFind->GetActorLocation(), GetActorLocation());
		if (tempDistance < distance)
		{
			distance = tempDistance;
			enemy = *enemyToFind;
		}
		UE_LOG(LogTemp, Warning, TEXT("distance is : %f"), distance);
	}
	
	
	if (!enemy) return;
		if(tempEnemy ==enemy)
		{
			enemy->targeted = false;
			enemy = nullptr;
			tempEnemy = nullptr;
			UE_LOG(LogTemp, Warning, TEXT("enemy target false"));
		}
		else
		{
			FString name = enemy->GetName();
			UE_LOG(LogTemp, Warning, TEXT("name is %s"),*name);
			enemy->targeted = true;
		}
		
}

void APlayerHumanCharacter::setPlayerHuds()
{
	health = currentHealth / maxHealth;
	stamina = currentStamina / maxStamina;
	mana = currentMana / maxMana;

}

