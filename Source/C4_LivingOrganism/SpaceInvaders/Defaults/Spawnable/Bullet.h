// Copyright Pedro E. Perez 2023 - All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "C4_LivingOrganism/DamageInterface.h"
#include "C4_LivingOrganism/DamageOther.h"
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

	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	float DamageAmount = 1.0f;

protected:
	// Called when the game starts or when spawned

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TObjectPtr<UProjectileMovementComponent> ProjectileMovementComp;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> BulletMesh;

	UFUNCTION()
	void OverlapWithAlien(AActor* myBullet, AActor* theAlien);

	/*UFUNCTION()
	virtual void MakeDamage_Implementation( AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit) override;*/
	

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
};
