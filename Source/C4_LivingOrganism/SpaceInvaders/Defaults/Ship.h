// Copyright Pedro E. Perez 2023 - All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "KismetCastingUtils.h"
#include "GameFramework/Pawn.h"
#include "Ship.generated.h"

class UFloatingPawnMovement;
class ABullet;

UCLASS()
class C4_LIVINGORGANISM_API AShip : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TObjectPtr<UFloatingPawnMovement> FloatingMovementComponent;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TSubclassOf<ABullet> BulletClassToSpawn;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UFUNCTION()
	void MoveForward(const float value);

	UFUNCTION()
	void MoveRight(const float value);

	UFUNCTION()
	void SpawnBullet();
	
};
