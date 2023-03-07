

#include "Bullet.h"
#include "Components/SphereComponent.h"
#include "Target.h"

ABullet::ABullet()
{
	PrimaryActorTick.bCanEverTick = true;

	Collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	SetRootComponent(Collider);
	Collider->InitSphereRadius(10.f);
	Collider->OnComponentBeginOverlap.AddDynamic(this, &ABullet::OnOverlap);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(GetRootComponent());
	StaticMesh->SetRelativeScale3D(FVector(0.2f, 0.2f, 0.2f));

	MovementSpeed = 2000.f;
	TimeLived = 0.f;
	LifeSpan = 10.f;
}

void ABullet::BeginPlay()
{
	Super::BeginPlay();

}

void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	NewLocation += GetActorForwardVector() * MovementSpeed * DeltaTime;
	SetActorLocation(NewLocation);


	TimeLived += DeltaTime;
	if (TimeLived > LifeSpan)
	{
		DestroyBullet();
	}
}

void ABullet::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA<ATarget>())
	{
		Cast<ATarget>(OtherActor)->DestroyTarget();
		DestroyBullet();
	}
}

void ABullet::DestroyBullet()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	this->Destroy();
}

//SOURCE
//Thorset, A.(2023,february 23rd). TA2Feb23. Github. https://github.com/Aleksthor/TA2Feb23