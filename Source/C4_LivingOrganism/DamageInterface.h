// Copyright Pedro E. Perez 2023 - All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DamageInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(Blueprintable)
class UDamageInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class C4_LIVINGORGANISM_API IDamageInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	void TakeDamage(const float& damageAmount);
	
};
