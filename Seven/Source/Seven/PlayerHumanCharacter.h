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

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;
	
protected:
	virtual void BeginPlay() override;
	

	UPROPERTY(BlueprintReadWrite)
	class AAIHumanCharacter* enemy =nullptr;

	UFUNCTION(BlueprintCallable)
	void TargetEnemy();

	float distance=1000.f;
	
	

public:
	
	APlayerHumanCharacter();

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

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
