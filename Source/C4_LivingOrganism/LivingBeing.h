// Copyright Pedro E. Perez 2023 - All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DamageInterface.h"
#include "DamageOther.h"
#include "LivingBeing.generated.h"

class UStaticMeshComponent;
class UArrowComponent;


UCLASS(Abstract,HideDropdown)
class C4_LIVINGORGANISM_API ALivingBeing : public AActor,public IDamageInterface
{
	GENERATED_BODY()
	
public:	
	
	// Sets default values for this actor's properties
	virtual void Tick(float DeltaTime) override;
	ALivingBeing();

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	float Health = 10.0f;


protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float movementSpeed = 5.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> Body;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UArrowComponent> Nose;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void TakeDamage_Implementation(const float& damageAmount) override;
	

private:
	
	virtual void MoveOrganism();

};
