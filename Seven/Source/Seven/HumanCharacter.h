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
	
	
protected:
	/* setting up all inputs*/
	virtual void SetupPlayerInputComponent(UInputComponent * PlayerInputComponent) override;

	/*called when left mouseButton Clicked*/
	void AttackL();

	/*called when right mouse button clicked*/
	void AttackR();

	

	UPROPERTY(BlueprintReadWrite)
		TArray < class UAnimMontage*> attackMontage;

	UPROPERTY(BlueprintReadWrite)
		TArray < class UAnimMontage*> reactMontage;

	

	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	

};
