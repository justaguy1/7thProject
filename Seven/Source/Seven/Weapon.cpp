// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon.h"
#include "Classes/Components/SphereComponent.h"
#include "Classes/Components/SkeletalMeshComponent.h"
#include "HumanCharacter.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (canApplyDamage == false)
		noOfHitregistered = 0;

}

void AWeapon::setDamage(float & currentHealth, AHumanCharacter * player, AHumanCharacter * enemy)
{
	

	if (!enemy) return;

	FVector character_direction = player->GetActorForwardVector();
	character_direction.Normalize();

	FVector enemy_direction = enemy->GetActorForwardVector();
	enemy_direction.Normalize();

	float dotprod = FVector::DotProduct(character_direction, enemy_direction);
	FVector crossprod = FVector::CrossProduct(character_direction, enemy_direction);


	if (dotprod > 0.7 && dotprod <= 1)
	{
		enemy->reaction_back = true;
		enemy->reaction_front = false;
		enemy->reaction_left = false;
		enemy->reaction_right = false;
		UE_LOG(LogTemp, Warning, TEXT("back"))
	}

	else if (dotprod > -1.0f && dotprod < -0.7f)
	{
		enemy->reaction_back = false;
		enemy->reaction_front = true;
		enemy->reaction_left = false;
		enemy->reaction_right = false;
		UE_LOG(LogTemp, Warning, TEXT("front"))
	}

	else if (crossprod.Z > 0.7 && crossprod.Z <= 1)
	{
		enemy->reaction_back = false;
		enemy->reaction_front = false;
		enemy->reaction_left = false;
		enemy->reaction_right = true;
		UE_LOG(LogTemp, Warning, TEXT("right "))
	}

	else if (crossprod.Z < 0.7 && crossprod.Z >= -1)
	{
		enemy->reaction_back = false;
		enemy->reaction_front = false;
		enemy->reaction_left = true;
		enemy->reaction_right = false;
		UE_LOG(LogTemp, Warning, TEXT("left"))
	}

	float damage = weaponDamage / 100 * 70;
	damage = FMath::RandRange(damage, weaponDamage);

	currentHealth -= damage;
}

void AWeapon::setWeaponRelatedDamage()
{
}

