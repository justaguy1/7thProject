// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerHumanCharacter.h"
#include "AIHumanCharacter.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "EngineUtils.h"

void APlayerHumanCharacter::setAttackHitDirection()
{

}

void APlayerHumanCharacter::TargetEnemy()
{
	AAIHumanCharacter *tempEnemy = enemy;
	distance = 2000;
	if (enemy)
		enemy->targeted = false;
	TArray<AAIHumanCharacter*> foundActor;
	int i = 0;
	
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
