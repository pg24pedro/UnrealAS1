// Copyright Pedro E. Perez 2023 - All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "LivingBeing.h"
#include "Alien.generated.h"

/**
 * 
 */
UCLASS()
class C4_LIVINGORGANISM_API AAlien : public ALivingBeing
{
	GENERATED_BODY()


public:

	AAlien(const FObjectInitializer& ObjectInitializer);
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	float DamageAmount = 1.0f;

protected:

	UFUNCTION()
	void DoDamage(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
	
};
