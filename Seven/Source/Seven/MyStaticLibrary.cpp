// Fill out your copyright notice in the Description page of Project Settings.

#include "MyStaticLibrary.h"


_Directions UMyStaticLibrary::getrelativeDirection(AActor * player, AActor * AI_)
{
	FVector character_direction = player->GetActorForwardVector();
	character_direction.Normalize();
	
	FVector AI_direction = AI_->GetActorForwardVector();
	AI_direction.Normalize();

	float dotprod = FVector::DotProduct(character_direction, AI_direction);
	FVector crossprod = FVector::CrossProduct(character_direction, AI_direction);


	if (dotprod > 0.7 && dotprod <= 1)
	{
		return _Directions::backward;
	}

	else if (dotprod > -1.0f && dotprod < -0.7f)
	{
		return _Directions::forward;
	}

	else if (crossprod.Z > 0.7 && crossprod.Z <= 1)
	{
		return _Directions::right;
	}

	else if (crossprod.Z < 0.7 && crossprod.Z >= -1)
	{
		return _Directions::left;
	}

	return _Directions::invalid;
}

float  UMyStaticLibrary::_ApplyDamage(float health, float damageToApply)
{
	float damage = damageToApply / 100 * 70;
	damage = FMath::RandRange(damage, damageToApply);
	health -= damage;
	return health;
	
}
