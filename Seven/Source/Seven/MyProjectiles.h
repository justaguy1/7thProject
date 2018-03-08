// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyProjectiles.generated.h"

UCLASS()
class SEVEN_API AMyProjectiles : public AActor
{
	GENERATED_BODY()
	
	
public:	
	// Sets default values for this actor's properties
	AMyProjectiles();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite)
		bool canSpawnProjectile = false;
	
	UFUNCTION(BlueprintCallable)
		void launchProjectile(float projectileLaunchSpeed,bool isPlayer, class AHumanCharacter *target);
	
		void launchProjectile(float projectileLaunchSpeed);

		UPROPERTY(EditAnywhere,BlueprintReadWrite,Category =ProjectileProperty)
			float projectileDamage = 50;

protected:
	UPROPERTY(EditAnywhere)
		class UProjectileMovementComponent * projectileMovement=nullptr;
};
