// Fill out your copyright notice in the Description page of Project Settings.

#include "AttackAnimations.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIHumanCharacter.h"
#include "EnemyAIController.h"
#include "MyStaticLibrary.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectGlobals.h"

EBTNodeResult::Type UAttackAnimations::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	

	auto AIController = OwnerComp.GetAIOwner();   
	auto controlledPawn = AIController->GetPawn();
	AAIHumanCharacter* AIcharacter = Cast<AAIHumanCharacter>(controlledPawn);

	/*******       key used to get value from blackboard             *****/
	bool canSee = BlackboardComp->GetValueAsBool(canSeePlayerKey.SelectedKeyName);
	UObject* PlayerCharacter = BlackboardComp->GetValueAsObject(PlayerKey.SelectedKeyName);

	int combocount = BlackboardComp->GetValueAsInt(comboCountKey.SelectedKeyName);
	bool comboreset = BlackboardComp->GetValueAsBool(comboResetKey.SelectedKeyName);
	
	
	_Directions direction = UMyStaticLibrary::getrelativeDirection(AIcharacter,Cast<AActor>(PlayerCharacter));
	if (direction == _Directions::backward)
		canSee = false;
	else
		canSee = true;


	UAnimInstance* animInstance = AIcharacter->animInstance;
	if (!animInstance)
	{
		UE_LOG(LogTemp, Warning, TEXT("AnimInstance Fail!!!"));
		return EBTNodeResult::Failed;
	}

	if (canSee == true)
	{
		
		
		
		if (comboreset == true)
		{
			
			float randVal = FMath::RandRange(0, 6);
				if(randVal < 3)
					BlackboardComp->SetValueAsInt(comboCountKey.SelectedKeyName, 0);
				else
					BlackboardComp->SetValueAsInt(comboCountKey.SelectedKeyName, 4);
				
			
		}
			

		if (AIcharacter->isAttackAnimationPlaying == false)
		{
			UE_LOG(LogTemp, Warning, TEXT("combocount : %d"),combocount);
			animInstance->Montage_Play(AIcharacter->attackMontage[combocount]);
			if (combocount == 3)
			{
				BlackboardComp->SetValueAsBool(comboResetKey.SelectedKeyName, true);
			}
			else
			{
				BlackboardComp->SetValueAsBool(comboResetKey.SelectedKeyName, false);
			}
		}
			
		if (combocount == 4)
		{
			BlackboardComp->SetValueAsInt(comboCountKey.SelectedKeyName, 3);
			
		}
		else if (combocount < 3)
		{
			BlackboardComp->SetValueAsInt(comboCountKey.SelectedKeyName, ++combocount);
			
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("not visible"));
		if (AIcharacter->isAttackAnimationPlaying == false)
			animInstance->Montage_Play(AIcharacter->attackMontage[2]);
	}

	

	
	UE_LOG(LogTemp, Warning, TEXT("combo count : %d"), combocount);
	return EBTNodeResult::Succeeded;
}

	




