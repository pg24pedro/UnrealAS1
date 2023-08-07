// Copyright Pedro E. Perez 2023 - All rights reserved


#include "Alien.h"

#include "Barrel.h"
#include "Human.h"
#include "SpaceInvaders/Defaults/Ship.h"

AAlien::AAlien(const FObjectInitializer& ObjectInitializer)
{
	Health = 3;
}


/*void AAlien::DoDamage(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{		
	/#1#/Checks if the hiting actor is a living being or not
	TObjectPtr<AHuman> livingBeingToHit = Cast<AHuman>(OtherActor);

	//Hits the actor and reduces the health of it
	if(IsValid(livingBeingToHit))
	{
		livingBeingToHit->TakeDamage(DamageAmount);
	}

	TObjectPtr<ABarrel> barrelToHit = Cast<ABarrel>(OtherActor);

	//Hits the actor and reduces the health of it
	if(IsValid(barrelToHit))
	{
		barrelToHit->TakeDamage(DamageAmount);
	}#1#

	if(OtherActor->Implements<UDamageInterface>())
	{
		IDamageInterface::Execute_TakeDamage(OtherActor,DamageAmount);
	}
}*/


void AAlien::BeginPlay()
{
	Super::BeginPlay();

	//who listens->Which Function listen to it
	OnActorHit.AddDynamic(this, &ThisClass::MakeDamage_Implementation);
}

void AAlien::MakeDamage_Implementation(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse,
	const FHitResult& Hit)
{
	TObjectPtr<AHuman> livingBeingToHit = Cast<AHuman>(OtherActor);

	//Hits the actor and reduces the health of it
	if(IsValid(livingBeingToHit))
	{
		livingBeingToHit->Execute_TakeDamage(livingBeingToHit,DamageAmount);
	}

	TObjectPtr<ABarrel> barrelToHit = Cast<ABarrel>(OtherActor);

	//Hits the actor and reduces the health of it
	if(IsValid(barrelToHit))
	{
		barrelToHit->Execute_TakeDamage(barrelToHit,DamageAmount);
	}

	TObjectPtr<AShip> playersShip = Cast<AShip>(OtherActor);

	//Hits the actor and reduces the health of it
	if(IsValid(playersShip))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Player Hit from alien"));
		playersShip->Execute_TakeDamage(playersShip,DamageAmount);
		
	}
	/*IDamageOther::MakeDamage_Implementation(SelfActor, OtherActor, NormalImpulse, Hit);
	if(OtherActor->Implements<UDamageInterface>())
	{
		IDamageInterface::Execute_TakeDamage(OtherActor,DamageAmount);
	}*/
}
