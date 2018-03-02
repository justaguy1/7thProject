// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon.h"
#include "Classes/Components/SphereComponent.h"
#include "Classes/Components/SkeletalMeshComponent.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


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

}

void AWeapon::setDamage(float &currentHealth)
{
	
	float damage = weaponDamage / 100 * 70;
		damage= FMath::RandRange(damage, weaponDamage);
	
	currentHealth -= damage;
}

