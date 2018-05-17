// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerHumanCharacter.h"
#include "AIHumanCharacter.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"



APlayerHumanCharacter::APlayerHumanCharacter()
{
	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

												// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	current_xp = 0.f;
	required_XP = 1000;
	xp = current_xp / required_XP;

	
}
void APlayerHumanCharacter::BeginPlay()
{
	Super::BeginPlay();
	OwnerisPlayer = true;
}

void APlayerHumanCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	setPlayerHuds(); // it related to hud
	setPlayerXP(); // it is only related to hud
	


	
	
}
void APlayerHumanCharacter::SetupPlayerInputComponent(UInputComponent * PlayerInputComponent)
{
	check(PlayerInputComponent);
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("AttackL", IE_Pressed, this, &APlayerHumanCharacter::AttackL);
	PlayerInputComponent->BindAction("AttackR", IE_Pressed, this, &APlayerHumanCharacter::AttackR);



}

AAIHumanCharacter * APlayerHumanCharacter::checkForAllEnemy()
{



	for (TActorIterator<AAIHumanCharacter> enemyToFind(GetWorld()); enemyToFind; ++enemyToFind)
	{

		return *enemyToFind;
		
	}
	return nullptr;
}

void APlayerHumanCharacter::TargetEnemy()
{
	AAIHumanCharacter *tempEnemy = enemy;
	distance = 1000;
	if (enemy)
		enemy->targeted = false;
	TArray<AAIHumanCharacter*> foundActor;
	
	// used to find all actors of class AAIHumanCharacter
	for (TActorIterator<AAIHumanCharacter> enemyToFind(GetWorld()); enemyToFind; ++enemyToFind)
	{
		
		enemyToFind->targeted = false;
		float tempDistance =FVector::Distance(enemyToFind->GetActorLocation(), GetActorLocation());
		if (tempDistance < distance)
		{
			distance = tempDistance;
			enemy = *enemyToFind;
			target = enemy;
		}
		UE_LOG(LogTemp, Warning, TEXT("distance is : %f"), distance);
	}
	
	
	if (!enemy) return;
		if(tempEnemy ==enemy)
		{
			enemy->targeted = false;
			enemy = nullptr;
			tempEnemy = nullptr;
			target = nullptr;
		//	UE_LOG(LogTemp, Warning, TEXT("enemy target false"));
		}
		else
		{
			/*FString name = enemy->GetName();
			UE_LOG(LogTemp, Warning, TEXT("name is %s"),*name);*/
			enemy->targeted = true;
		}
		
}

void APlayerHumanCharacter::setPlayerHuds()
{
	health = currentHealth / maxHealth;
	stamina = currentStamina / maxStamina;
	mana = currentMana / maxMana;

}

void APlayerHumanCharacter::setPlayerXP()
{
	
	xp = current_xp / required_XP;
	if (current_xp >= required_XP)
	{
		playerlevel++;
		currentHealth = maxHealth;
		currentMana = maxMana;
		remainingSkillPoint = playerlevel - usedSkillPoint;
		current_xp = (int)current_xp % (int)required_XP;
		required_XP = required_XP + xp_required_rate*required_XP / 100;
	}

}

void APlayerHumanCharacter::gainXP(AAIHumanCharacter * enemy)
{
	current_xp = current_xp + enemy->AI_XP;
	canAttackAgain = false;
}

void APlayerHumanCharacter::AttackL()
{
	if (!MyWeapon) return;
	if (!animInstance)
	{
		UE_LOG(LogTemp, Warning, TEXT("Some shit happened"));
		return;
	}
	if (!IsInAir && canAttackAgain)
		animInstance->Montage_Play(attackMontage[0]);
	
}

void APlayerHumanCharacter::AttackR()
{

	if (!animInstance)
	{
		UE_LOG(LogTemp, Warning, TEXT("Some shit happened"));
		return;
	}

	//if (!IsInAir)
	//	animInstance->Montage_Play(attackMontage[1]);
	throwProjectiles();

	item_Details[0].itemCount = 10;
}

