// Copyright Pedro E. Perez 2023 - All rights reserved


#include "Predator.h"

#include "Alien.h"

APredator::APredator(const FObjectInitializer& ObjectInitializer)
{
	Health = 5.0f;
}

void APredator::BeginPlay()
{
	Super::BeginPlay();
	OnActorHit.AddDynamic(this, &ThisClass::MakeDamage_Implementation);
}

void APredator::MakeDamage_Implementation(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse,
                                          const FHitResult& Hit)
{
	IDamageOther::MakeDamage_Implementation(SelfActor, OtherActor, NormalImpulse, Hit);

	TObjectPtr<AAlien> AlienToHit = Cast<AAlien>(OtherActor);

	//Hits the actor and reduces the health of it
	if(IsValid(AlienToHit))
	{
		AlienToHit->Execute_TakeDamage(AlienToHit,DamageAmount);
	}
}
