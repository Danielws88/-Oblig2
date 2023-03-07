
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPlayer.generated.h"

class USpringArmComponent;
class UCameraComponent;
class ABullet;
struct FInputActionValue;

UCLASS()
class OBLIG2_API AMyPlayer : public APawn
{
	GENERATED_BODY()

public:
	AMyPlayer();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere)
		USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
		UCameraComponent* Camera;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variables")
		TSubclassOf<ABullet> Bullet_BP;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variables")
		int Ammo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variables")
		int MaxAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variables")
		float MovementSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variables")
		int Lives;


	void HitByTarget();

private:

	float XInput;
	float YInput;
	float Yaw;
	float Pitch;


private:

	void Forward(const FInputActionValue& input);
	void Right(const FInputActionValue& input);

	void Shoot(const FInputActionValue& input);
	void Reload(const FInputActionValue& input);

	void MouseX(const FInputActionValue& input);
	void MouseY(const FInputActionValue& input);

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InputSystem)
		class UInputMappingContext* MappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InputSystem)
		class UInputAction* ForwardInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InputSystem)
		class UInputAction* RightInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InputSystem)
		class UInputAction* ShootInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InputSystem)
		class UInputAction* ReloadInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InputSystem)
		class UInputAction* MouseXInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InputSystem)
		class UInputAction* MouseYInput;

	//SOURCE
	//Thorset, A.(2023,february 23rd). TA2Feb23. Github. https://github.com/Aleksthor/TA2Feb23
};
