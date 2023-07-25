// Copyright Pedro E. Perez 2023 - All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "SpaceInvadersGAmeMode.generated.h"

UCLASS()
class C4_LIVINGORGANISM_API ASpaceInvadersGAmeMode : public AGameMode
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpaceInvadersGAmeMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
