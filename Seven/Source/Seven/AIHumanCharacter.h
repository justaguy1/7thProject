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
	
public:
	UFUNCTION(BlueprintCallable)
		virtual void targetMe();

	UPROPERTY(BlueprintReadWrite)
		bool targeted = false;
	
	
};
