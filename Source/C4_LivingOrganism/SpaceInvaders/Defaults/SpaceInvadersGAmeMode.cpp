// Copyright Pedro E. Perez 2023 - All rights reserved


#include "C4_LivingOrganism/SpaceInvaders/Defaults/SpaceInvadersGAmeMode.h"
#include "Ship.h"
#include "SpaceInvaderController.h"


// Sets default values
ASpaceInvadersGAmeMode::ASpaceInvadersGAmeMode()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bStartPlayersAsSpectators = true;
	DefaultPawnClass = AShip::StaticClass();
	PlayerControllerClass = ASpaceInvaderController::StaticClass();
}

// Called when the game starts or when spawned
void ASpaceInvadersGAmeMode::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpaceInvadersGAmeMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

