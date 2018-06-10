// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AllMyStructures.generated.h"


USTRUCT(BlueprintType)
struct FItem_details
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
		int itemIndex;

	UPROPERTY(BlueprintReadWrite)
		int itemCount;

	UPROPERTY(BlueprintReadWrite)
		FName itemName;

	UPROPERTY(BlueprintReadWrite)
		UTexture2D* icon;

	UPROPERTY(BlueprintReadWrite)
		FText description;

	UPROPERTY(BlueprintReadWrite)
		bool isConsumable ;

	UPROPERTY(BlueprintReadWrite)
		float Usage;

	UPROPERTY(BlueprintReadWrite)
		FName WeaponSocketName;

	UPROPERTY(BlueprintReadWrite)
		class AWeapon* weaponToSpawn;

	FItem_details()
	{
		itemIndex = -1;
		itemCount = 1;
		itemName = "None";
		icon = nullptr;
		description = FText();
		isConsumable = false;
		Usage = 0.0f;
		WeaponSocketName = FName("None");
		weaponToSpawn = nullptr;

	}

	
};

UENUM(BlueprintType)
enum class _Directions : uint8
{

	left		UMETA(DisplayName = "left"),
	right		UMETA(DisplayName = "right"),
	forward		UMETA(DisplayName = "forward"),
	backward	UMETA(DisplayName = "backward"),
	invalid     UMETA(DisplayName = "invalid")


};



