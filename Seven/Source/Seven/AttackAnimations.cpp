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

	if(!canSee)
	AIController->SetFocus(Cast<AActor>(PlayerCharacter));


	UAnimInstance* animInstance = AIcharacter->animInstance;
	if (!animInstance)
	{
		UE_LOG(LogTemp, Warning, TEXT("AnimInstance Fail!!!"));
		return EBTNodeResult::Failed;
	}

	if (canSee == true)
	{
		
		if (combocount == 2)
		{
			BlackboardComp->SetValueAsInt(comboCountKey.SelectedKeyName, 0);
			return EBTNodeResult::Succeeded;

		}
		else if (combocount < 2)
		{
			BlackboardComp->SetValueAsInt(comboCountKey.SelectedKeyName, ++combocount);

		}
		
		if (comboreset == true)
		{	
			BlackboardComp->SetValueAsInt(comboCountKey.SelectedKeyName, 0);
		}
			
		
		if (AIcharacter->isAttackAnimationPlaying == false)
		{
			UE_LOG(LogTemp, Warning, TEXT("combocount : %d"),combocount);
			animInstance->Montage_Play(AIcharacter->attackMontage[combocount]);
		/*	if (combocount == AIcharacter->attackMontage.Max())
			{
				BlackboardComp->SetValueAsBool(comboResetKey.SelectedKeyName, true);
			}
			else
			{
				BlackboardComp->SetValueAsBool(comboResetKey.SelectedKeyName, false);
			}*/

			
		}
			
		
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("not visible"));
		
	}

	

	
	UE_LOG(LogTemp, Warning, TEXT("combo count : %d"), combocount);
	return EBTNodeResult::Succeeded;
}

	




