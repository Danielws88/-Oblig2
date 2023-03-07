
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Target.generated.h"

class UBoxComponent;

UCLASS()
class OBLIG2_API ATarget : public AActor
{
	GENERATED_BODY()

public:
	ATarget();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UBoxComponent* Collider {nullptr};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* StaticMesh;


	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex,
			bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void DestroyTarget();



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variables")
		float MovementSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variables")
		float RotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variables")
		float XKillPosition;

	//SOURCE
	//Thorset, A.(2023,february 23rd). TA2Feb23. Github. https://github.com/Aleksthor/TA2Feb23
};
