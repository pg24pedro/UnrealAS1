// Copyright Pedro E. Perez 2023 - All rights reserved


#include "SpaceInvaderController.h"

#include "Ship.h"
#include "SpaceInvadersGAmeMode.h"


// Sets default values
ASpaceInvaderController::ASpaceInvaderController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASpaceInvaderController::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpaceInvaderController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("LookVertical",this,&ThisClass::LookVertical);
	InputComponent->BindAxis("LookHorizontal",this,&ThisClass::LookHorizontal);

	InputComponent->BindAction("Spawn",IE_Pressed,this, &ThisClass::SpawnPlayer);

	
}

// Called every frame
void ASpaceInvaderController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASpaceInvaderController::LookVertical(const float value)
{
	AddPitchInput(value);
}

void ASpaceInvaderController::LookHorizontal(const float value)
{
	AddYawInput(value);
}

void ASpaceInvaderController::SpawnPlayer()
{
	if(IsValid(GetPawn()))
	{
		return;
	}

	const TObjectPtr<UWorld> world = GetWorld();

	if(!IsValid(world))
	{
		return;
	}

	//SPAWN PARAMETERS, CAN SET A LOT OF THINGS, WE ARE ONLY SETTING THE COLLISION
	FActorSpawnParameters PawnSpawnParameters;
	PawnSpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	TObjectPtr<ASpaceInvadersGAmeMode> GAmeMode = world->GetAuthGameMode<ASpaceInvadersGAmeMode>();
	if(!IsValid(GAmeMode))
	{
		return;
	}

	TSubclassOf<APawn> spawnPawnClass = GAmeMode->DefaultPawnClass;
	if(!IsValid(spawnPawnClass))
	{
		return;
	}
	
	TObjectPtr<APawn> spawnedPawn = world->SpawnActor<APawn>(spawnPawnClass,
		{0.0f,0.0f,0.0f},
		FRotator::ZeroRotator,
		PawnSpawnParameters);

	if(IsValid(spawnedPawn))
	{
		Possess(spawnedPawn);
	}
}

