// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AllMyStructures.h"
#include "MyStaticLibrary.generated.h"

/**
 * 
 */
UCLASS()
class SEVEN_API UMyStaticLibrary : public UObject
{
	GENERATED_BODY()
public:
		UFUNCTION(BlueprintCallable)
		static _Directions getrelativeDirection(AActor* player, AActor* AI_);

		UFUNCTION(BlueprintCallable)
		static float _ApplyDamage(float health, float damageToApply);
	
	
};
