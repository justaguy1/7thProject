// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"


UENUM(BlueprintType)		
enum class WeaponType : uint8
{
		
		lightWeapon		UMETA(DisplayName = "lightWeapon"),
		middleWeapon	UMETA(DisplayName = "middleWeapon"),
		heavyWeapon		UMETA(DisplayName = "heavyWeapon"),
		throwableWeapon UMETA(DisplayName ="throwableWeapon"),
		magicWeapon		UMETA(DisplayName = "magicWeapon")
	
};

UCLASS()
class SEVEN_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
		float weaponDamage = 15.f;

	UFUNCTION(BlueprintCallable)
		void setDamage(float &currentHealth,class AHumanCharacter *player, AHumanCharacter *enemy);

	UPROPERTY(BlueprintReadWrite)
		bool canApplyDamage = false;

	// unused currently
	UPROPERTY(BlueprintReadWrite)
		int noOfHitregistered = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		WeaponType weaponType;
	UPROPERTY(BlueprintReadWrite)
		bool ispossessed = false;

	UPROPERTY(BlueprintReadWrite)
		AHumanCharacter* MyOwner;

	UPROPERTY(BlueprintReadWrite)
		TArray<AActor*> OverlappedActors;
	

};
