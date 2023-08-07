// Copyright Pedro E. Perez 2023 - All rights reserved


#include "Bullet.h"

#include "Projects.h"
#include "C4_LivingOrganism/Alien.h"
#include "C4_LivingOrganism/SpaceInvaders/Defaults/Ship.h"
#include "GameFramework/ProjectileMovementComponent.h"


// Sets default values
ABullet::ABullet()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	ProjectileMovementComp->SetUpdatedComponent(RootComponent);

	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bullet Mesh Component"));
	SetRootComponent(BulletMesh);

	ProjectileMovementComp->InitialSpeed = 500.0f;
	ProjectileMovementComp->MaxSpeed = 800.0f;

	ProjectileMovementComp->ProjectileGravityScale = 0.0f;
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this,&ThisClass::OverlapWithAlien);
	//OnActorHit.AddDynamic(this, &ThisClass::MakeDamage_Implementation);
	

	
}

void ABullet::OverlapWithAlien(AActor* myBullet, AActor* theAlien)
{
	TObjectPtr<AAlien> AlienToHit = Cast<AAlien>(theAlien);

	if(IsValid(AlienToHit))
	{
		AlienToHit->Execute_TakeDamage(AlienToHit,DamageAmount);

		AShip* PlayerShip = GetWorld()->GetFirstPlayerController()->GetPawn<AShip>();

		if(PlayerShip)
		{
			PlayerShip->PlayerScore += 10;
		}
		
	}

}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

/*void ABullet::MakeDamage_Implementation( AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse,
	const FHitResult& Hit)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Alien Shot"));

	IDamageOther::MakeDamage_Implementation(SelfActor, OtherActor, NormalImpulse, Hit);
	TObjectPtr<AAlien> AlienToHIt = Cast<AAlien>(OtherActor);

	if(IsValid(AlienToHIt))
	{
		AlienToHIt->Execute_TakeDamage(AlienToHIt,DamageAmount);
	}

}*/

