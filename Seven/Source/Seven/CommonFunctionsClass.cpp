// Fill out your copyright notice in the Description page of Project Settings.

#include "CommonFunctionsClass.h"
#include "HumanCharacter.h"

CommonFunctionsClass::CommonFunctionsClass()
{
}

CommonFunctionsClass::~CommonFunctionsClass()
{
}

void CommonFunctionsClass::getrelativeDirection(AHumanCharacter* player, AHumanCharacter* AI_)
{
	FVector character_direction = player->GetActorForwardVector();
	character_direction.Normalize();

	FVector AI_direction = AI_->GetActorForwardVector();
	AI_direction.Normalize();

	float dotprod = FVector::DotProduct(character_direction, AI_direction);
	FVector crossprod = FVector::CrossProduct(character_direction, AI_direction);


	if (dotprod > 0.7 && dotprod <= 1)
	{
		AI_->reaction_back = true;
		AI_->reaction_front = false;
		AI_->reaction_left = false;
		AI_->reaction_right = false;

	}

	else if (dotprod > -1.0f && dotprod < -0.7f)
	{
		AI_->reaction_back = false;
		AI_->reaction_front = true;
		AI_->reaction_left = false;
		AI_->reaction_right = false;

	}

	else if (crossprod.Z > 0.7 && crossprod.Z <= 1)
	{
		AI_->reaction_back = false;
		AI_->reaction_front = false;
		AI_->reaction_left = false;
		AI_->reaction_right = true;

	}

	else if (crossprod.Z < 0.7 && crossprod.Z >= -1)
	{
		AI_->reaction_back = false;
		AI_->reaction_front = false;
		AI_->reaction_left = true;
		AI_->reaction_right = false;

	}
	
}
