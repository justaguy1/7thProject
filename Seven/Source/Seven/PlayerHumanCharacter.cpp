// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerHumanCharacter.h"
#include "AIHumanCharacter.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "EngineUtils.h"


void APlayerHumanCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerHumanCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	setAttackHitDirection();
}

void APlayerHumanCharacter::setAttackHitDirection()
{
	if (!enemy) return;
	FVector character_direction = GetActorForwardVector();
	character_direction.Normalize();

	FVector enemy_direction = enemy->GetActorForwardVector();
	enemy_direction.Normalize();

	float dotprod = FVector::DotProduct(character_direction, enemy_direction);
	FVector crossprod = FVector::CrossProduct(character_direction, enemy_direction);

	
	if(dotprod>0.7 && dotprod <=1)
	{
		enemy->reaction_back = true;
		enemy->reaction_front = false;
		enemy->reaction_left = false;
		enemy->reaction_right = false;
		UE_LOG(LogTemp, Warning, TEXT("back"))
	}
		
	else if(dotprod > -1.0f && dotprod < -0.7f)
	{
		enemy->reaction_back = false;
		enemy->reaction_front = true;
		enemy->reaction_left = false;
		enemy->reaction_right = false;
		UE_LOG(LogTemp, Warning, TEXT("front"))
	}

	else if(crossprod.Z>0.7 && crossprod.Z<=1)
	{
		enemy->reaction_back = false;
		enemy->reaction_front = false;
		enemy->reaction_left = false;
		enemy->reaction_right = true;
		UE_LOG(LogTemp, Warning, TEXT("right "))
	}

	else if (crossprod.Z < 0.7 && crossprod.Z >= -1)
	{
		enemy->reaction_back = false;
		enemy->reaction_front = false;
		enemy->reaction_left =true;
		enemy->reaction_right = false;
		UE_LOG(LogTemp, Warning, TEXT("left"))
	}
	
}

void APlayerHumanCharacter::TargetEnemy()
{
	AAIHumanCharacter *tempEnemy = enemy;
	distance = 1000;
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
		
		//setAttackHitDirection();
}

