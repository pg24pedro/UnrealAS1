// Copyright Pedro E. Perez 2023 - All rights reserved


#include "Barrel.h"

// Sets default values
ABarrel::ABarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABarrel::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABarrel::TakeDamage_Implementation(const float& damageAmount)
{
	IDamageInterface::TakeDamage_Implementation(damageAmount);
	if(--NumberOfHitsRequired <= 0)
	{
		Destroy();
	}
}

// Called every frame
void ABarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


