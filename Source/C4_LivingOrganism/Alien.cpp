// Copyright Pedro E. Perez 2023 - All rights reserved


#include "Alien.h"

AAlien::AAlien(const FObjectInitializer& ObjectInitializer)
{
	
}


void AAlien::DoDamage(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	/*//Checks if the hiting actor is a living being or not
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
	}*/

	if(OtherActor->Implements<UDamageInterface>())
	{
		IDamageInterface::Execute_TakeDamage(OtherActor,DamageAmount);
	}
}


void AAlien::BeginPlay()
{
	Super::BeginPlay();

	//who listens->Which Function listen to it
	OnActorHit.AddDynamic(this, &ThisClass::DoDamage);
}
