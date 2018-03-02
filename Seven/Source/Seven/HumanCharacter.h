// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SevenCharacter.h"
#include "HumanCharacter.generated.h"

/**
 * 
 */
UCLASS()
class SEVEN_API AHumanCharacter : public ASevenCharacter
{
	GENERATED_BODY()

public:
	AHumanCharacter();
	
protected:
	/* setting up all inputs*/
	virtual void SetupPlayerInputComponent(UInputComponent * PlayerInputComponent) override;

	/*called when left mouseButton Clicked*/
	void AttackL();

	/*called when right mouse button clicked*/
	void AttackR();

	
	
	UPROPERTY(BlueprintReadWrite)
		TArray <  UAnimMontage*> attackMontage;

	UPROPERTY(BlueprintReadWrite)
		TArray <  UAnimMontage*> reactMontage;

	UPROPERTY(BlueprintReadWrite)
		bool IsInAir  = false;

	APlayerController* controller;
	

	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapons")
		TArray< class AWeapon *> weaponR;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapons")
		TArray<class AWeapon *> weaponL;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapons")
		AWeapon *MyWeapon =nullptr;

	void swapL();

protected:
	UPROPERTY(BlueprintReadWrite, Category = "Player")
		float maxHealth = NULL;

	UPROPERTY(BlueprintReadWrite, Category = "Player")
		float currentHealth = NULL;

	UPROPERTY(BlueprintReadWrite, Category = "Player")
		float health = NULL;

	UPROPERTY(BlueprintReadWrite, Category = "Player")
		float maxStamina = NULL;
	UPROPERTY(BlueprintReadWrite, Category = "Player")
		float currentStamina = NULL;
	UPROPERTY(BlueprintReadWrite, Category = "Player")
		float stamina = NULL;
	UPROPERTY(BlueprintReadWrite, Category = "Player")
		float  maxMana = NULL;
	UPROPERTY(BlueprintReadWrite, Category = "Player")
		float currentMana = NULL;
	UPROPERTY(BlueprintReadWrite, Category = "Player")
		float mana = NULL;


	UFUNCTION(BlueprintCallable)
	void applyWeaponDamage(AWeapon *weapon);

};
