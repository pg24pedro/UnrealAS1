// Copyright Pedro E. Perez 2023 - All rights reserved


#include "Spawner.h"

#include "C4_LivingOrganism/Alien.h"


// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawningInterval = 1.5f;

}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();

	SpawnEnemy();

	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle,this,&ASpawner::SpawnEnemy,FMath::FRandRange(2.5f, 5.0f), true);
	
}

void ASpawner::SpawnEnemy()
{
	if(AlienBP != nullptr)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = GetInstigator();
		
		FVector SpawnLocation = GetActorLocation();
		FRotator SpawnRotation = GetActorRotation();

		// Spawn the enemy.
		GetWorld()->SpawnActor<AAlien>(AlienBP, SpawnLocation, SpawnRotation, SpawnParams);
		
	}
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


