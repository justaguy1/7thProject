// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HumanCharacter.h"
#include "PlayerHumanCharacter.generated.h"

/**
 * 
 */
UCLASS()
class SEVEN_API APlayerHumanCharacter : public AHumanCharacter
{
	GENERATED_BODY()
	
protected:

	virtual	void setAttackHitDirection() override;

	UPROPERTY(BlueprintReadWrite)
	class AAIHumanCharacter* enemy =nullptr;

	UFUNCTION(BlueprintCallable)
	void TargetEnemy();

	float distance=1000.f;
	
	
	
};
