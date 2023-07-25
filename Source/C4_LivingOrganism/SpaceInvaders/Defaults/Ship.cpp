// Copyright Pedro E. Perez 2023 - All rights reserved


#include "Ship.h"

#include "MovieSceneSequenceID.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Spawnable/Bullet.h"


// Sets default values
AShip::AShip()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FloatingMovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating Component"));
	FloatingMovementComponent->SetUpdatedComponent(RootComponent);

	FloatingMovementComponent->Acceleration=500.0f;
	FloatingMovementComponent->Deceleration=300.0f;

	FloatingMovementComponent->MaxSpeed=700.0f;

	FloatingMovementComponent->bConstrainToPlane=true;
	FloatingMovementComponent->SetPlaneConstraintAxisSetting(EPlaneConstraintAxisSetting::Z);
	
}

// Called when the game starts or when spawned
void AShip::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if(!IsValid(PlayerInputComponent))
	{
		return;
	}

	PlayerInputComponent->BindAxis("ForwardMovement",this,&ThisClass::MoveForward);
	PlayerInputComponent->BindAxis("RightMovement",this,&ThisClass::MoveRight);

	PlayerInputComponent->BindAction("Shoot", IE_Pressed,this,&ThisClass::SpawnBullet);
}

void AShip::MoveForward(const float value)
{
	AddMovementInput(GetActorForwardVector(),value,true);
}

void AShip::MoveRight(const float value)
{
	AddMovementInput(GetActorRightVector(),value,true);
}

void AShip::SpawnBullet()
{
	const TObjectPtr<UWorld> world = GetWorld();
	if(!IsValid(world))
	{
		return;
	}

	if(!IsValid(BulletClassToSpawn))
	{
		return;
	}

	const FVector SpawnLocation = (GetActorLocation() + FVector{50.0f,0.0f,0.0f});
	world->SpawnActor<ABullet>(BulletClassToSpawn, SpawnLocation,FRotator::ZeroRotator);

	
}

