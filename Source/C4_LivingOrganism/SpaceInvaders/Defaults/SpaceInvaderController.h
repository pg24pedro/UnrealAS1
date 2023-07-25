// Copyright Pedro E. Perez 2023 - All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "SpaceInvaderController.generated.h"

UCLASS()
class C4_LIVINGORGANISM_API ASpaceInvaderController : public APlayerController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpaceInvaderController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void LookVertical(const float value);

	UFUNCTION()
	void LookHorizontal(const float value);

	UFUNCTION()
	void SpawnPlayer();
};
