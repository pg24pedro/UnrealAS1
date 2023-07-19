// Copyright Pedro E. Perez 2023 - All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "LivingBeing.h"
#include "Human.generated.h"

/**
 * 
 */
UCLASS()
class C4_LIVINGORGANISM_API AHuman : public ALivingBeing
{
	GENERATED_BODY()

public:

	AHuman(const FObjectInitializer& ObjectInitializer);
	
};
