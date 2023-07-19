// Copyright Pedro E. Perez 2023 - All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DamageInterface.h"
#include "Barrel.generated.h"

UCLASS()
class C4_LIVINGORGANISM_API ABarrel : public AActor, public IDamageInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABarrel();
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	int32 NumberOfHitsRequired = 3;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void TakeDamage_Implementation(const float& damageAmount) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	

};
