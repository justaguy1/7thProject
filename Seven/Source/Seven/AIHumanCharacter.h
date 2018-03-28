// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HumanCharacter.h"
#include "AIHumanCharacter.generated.h"

/**
 * 
 */
UCLASS()
class SEVEN_API AAIHumanCharacter : public AHumanCharacter
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	void setPlayerHuds();
public:

	AAIHumanCharacter();

	UPROPERTY(BlueprintReadWrite)
		bool targeted = false;

	
	UPROPERTY(BlueprintReadWrite) // distance between player and enemy
		float playerDistance = 2000.f;
	UPROPERTY(BlueprintReadWrite)
		float previous_health;
	UPROPERTY(BlueprintReadWrite)// position where actor was first placed in world
		FVector originalpos;
	UPROPERTY(BlueprintReadWrite)
		bool PlayerIsInSight = false;

	virtual void Tick(float DeltaTime) override;

	void AttackPlayer();
	
	void removePlayer();

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	float AI_XP = 100.f;

	UPROPERTY(BlueprintReadWrite)
		float delayTimeInSeconds = 3.f;
		double lastAttackedTime=0;

		bool isWithinPlayerRadius = false;
	
};
