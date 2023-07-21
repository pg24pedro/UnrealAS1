// Copyright Pedro E. Perez 2023 - All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DamageOther.generated.h"

// This class does not need to be modified.
UINTERFACE(Blueprintable)
class UDamageOther : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class C4_LIVINGORGANISM_API IDamageOther
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	void MakeDamage(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
};
