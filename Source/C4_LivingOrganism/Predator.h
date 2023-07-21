// Copyright Pedro E. Perez 2023 - All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "LivingBeing.h"
#include "Predator.generated.h"

/**
 * 
 */
UCLASS()
class C4_LIVINGORGANISM_API APredator : public ALivingBeing, public IDamageOther
{
	GENERATED_BODY()
	
public:
	
	APredator(const FObjectInitializer& ObjectInitializer);
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	float DamageAmount = 1.0f;

protected:

	UFUNCTION()
	virtual void MakeDamage_Implementation(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit) override;
	
};
