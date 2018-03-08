// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProjectiles.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AMyProjectiles::AMyProjectiles()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	canSpawnProjectile = false;
	projectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("projectile movement"));
	projectileMovement->bAutoActivate = false;

}

// Called when the game starts or when spawned
void AMyProjectiles::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void AMyProjectiles::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

<<<<<<< HEAD
void AMyProjectiles::launchProjectile(float projectileLaunchSpeed, bool isPlayer,AHumanCharacter *target)
{
	if (projectileMovement == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("failed projectile movement"));
		return;
	}
	FRotator Rot = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), target->GetActorLocation());
	SetActorRotation(Rot);

	FVector launch = FVector::ForwardVector*projectileLaunchSpeed;

	projectileMovement->SetVelocityInLocalSpace(launch);

	
	
	
	
	

	projectileMovement->Activate();

}

=======
>>>>>>> parent of 45928c8... projectile causes damage ( still unfinished )
void AMyProjectiles::launchProjectile(float projectileLaunchSpeed)
{
	if (projectileMovement == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("failed projectile movement"));
		return;
	}

	FVector launch = FVector::ForwardVector*projectileLaunchSpeed;
	projectileMovement->SetVelocityInLocalSpace(launch);


	projectileMovement->Activate();
	UE_LOG(LogTemp, Warning, TEXT("launched wit speed %s"), *launch.ToString());
}

