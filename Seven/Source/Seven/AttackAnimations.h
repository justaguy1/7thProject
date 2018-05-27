// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "AttackAnimations.generated.h"

/**
 * 
 */
UCLASS()
class SEVEN_API UAttackAnimations : public UBTTaskNode
{
	GENERATED_BODY()

		virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8 *NodeMemory) override;

	
	
protected:
	UPROPERTY(EditAnywhere, Category = "Blackboard")
		struct FBlackboardKeySelector canSeePlayerKey;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
		struct FBlackboardKeySelector PlayerKey;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
		struct FBlackboardKeySelector comboResetKey;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
		struct FBlackboardKeySelector comboCountKey;

	
	
	
};
