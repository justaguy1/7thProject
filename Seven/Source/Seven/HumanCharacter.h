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
	

	void throwProjectiles();

	

	
	
	

	UPROPERTY(BlueprintReadWrite)
		bool IsInAir  = false;

	
	

	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapons")
		AWeapon *MyWeapon =nullptr;



	UPROPERTY(BlueprintReadWrite)
		bool reaction_left = false;
	UPROPERTY(BlueprintReadWrite)
		bool reaction_front = false;
	UPROPERTY(BlueprintReadWrite)
		bool reaction_back = false;
	UPROPERTY(BlueprintReadWrite)
		bool reaction_right = false;
	UPROPERTY(BlueprintReadWrite)
		bool isAttackMontagePlaying = false;
	

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
	void applyWeaponDamage(AWeapon *weapon,AHumanCharacter *player_c,AHumanCharacter *enemy_c);

	UPROPERTY(BlueprintReadWrite)
		bool canApplyDamage = false;

	UPROPERTY(BlueprintReadWrite)
		bool canPlayAnotherAnimation = false;

		bool isReactionAnimationPlaying();

	UPROPERTY(BlueprintReadWrite) // returns if enemy is hostile to player
			bool isAngry = false;

	UPROPERTY(BlueprintReadWrite)
		FVector selfForwardDirection;
	
	UPROPERTY(BlueprintReadWrite)
	FVector opponentForwardDirection;

	UPROPERTY(BlueprintReadWrite)
		bool OwnerisPlayer = false;

	UPROPERTY(BlueprintReadWrite)
		AHumanCharacter* target = nullptr;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		TSubclassOf<class AMyProjectiles> projectileBlueprint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ProjectilelaunchSpeed = 1500;

	UFUNCTION(BlueprintCallable)
		void applyProjectileDamage(float damage);

	public:
		UPROPERTY(BlueprintReadWrite)
			TArray <  UAnimMontage*> attackMontage;

		UPROPERTY(BlueprintReadWrite)
			TArray <  UAnimMontage*> reactMontage;
	
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			bool isAttackAnimationPlaying = false;
};
