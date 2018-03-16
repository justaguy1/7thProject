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
	virtual void BeginPlay() override;
	

	UPROPERTY(BlueprintReadWrite)
	class AAIHumanCharacter* enemy =nullptr;

	UFUNCTION(BlueprintCallable)
	void TargetEnemy();

	float distance=1000.f;
	
	
public:
	APlayerHumanCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent * PlayerInputComponent) override ;
	class AAIHumanCharacter* checkForAllEnemy();
	void setPlayerHuds();
protected:
	float required_XP;
	float current_xp;
	float xp_required_rate=15.f;
	int usedSkillPoint = 1;
	
	void setPlayerXP();
public :
	UPROPERTY(BlueprintReadWrite)
	float xp;
	UPROPERTY(BlueprintReadWrite)
	int playerlevel = 1;
	UPROPERTY(BlueprintReadWrite)
	int remainingSkillPoint = 0;
	void gainXP(class AAIHumanCharacter* enemy);
	
};
