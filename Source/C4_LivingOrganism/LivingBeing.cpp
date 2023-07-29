// Copyright Pedro E. Perez 2023 - All rights reserved

#include "LivingBeing.h"
#include "Components/ArrowComponent.h"
#include "Components/StaticMeshComponent.h"

#include "Components/BoxComponent.h"
#include "GenericPlatform/GenericPlatformCrashContext.h"

// Sets default values

class UBoxComponent;

ALivingBeing::ALivingBeing()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	Nose = CreateDefaultSubobject<UArrowComponent>(TEXT("MyNoseArrowComponent"));

	Nose->SetupAttachment(Body);
	SetRootComponent(Body);

	InitialLifeSpan = 0.0f;

	Body->SetSimulatePhysics(true);
	Body->SetConstraintMode(EDOFMode::XYPlane);
	Body->SetNotifyRigidBodyCollision(true);
	
}

// Called when the game starts or when spawned
void ALivingBeing::BeginPlay()
{
	Super::BeginPlay();
	
}

void ALivingBeing::TakeDamage_Implementation(const float& damageAmount)
{
	IDamageInterface::TakeDamage_Implementation(damageAmount);

	Health-=damageAmount;

	if(FMath::IsNearlyZero(Health))
	{
		Destroy();	
	}
}





// Called every frame
void ALivingBeing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveOrganism();

}

void ALivingBeing::MoveOrganism()
{
	const FVector velocity = Nose->GetForwardVector() * movementSpeed * Body->GetMass();
	Body->AddForce(velocity,NAME_None,true );
}

