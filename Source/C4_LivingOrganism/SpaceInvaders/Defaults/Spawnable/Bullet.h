// Copyright Pedro E. Perez 2023 - All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

class UProjectileMovementComponent;
class UStaticMeshComponent;

UCLASS(Abstract,HideDropdown)
class C4_LIVINGORGANISM_API ABullet : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TObjectPtr<UProjectileMovementComponent> ProjectileMovementComp;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> BulletMesh;

	

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
