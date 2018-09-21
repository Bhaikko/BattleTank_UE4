// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankBarrel.h"
#include "TankTurren.h"
#include "Projectile.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "TankAimingComponent.generated.h"


UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked,
	OutOfAmmo
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	void AimAt(FVector);
	bool IsBarrelMoving();

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialse(UTankBarrel* BarrelToSet, UTankTurren* TurrentToSet);

	void MoveBarrel(FVector);
	UTankBarrel* Barrel = NULL;
	UTankTurren* Turrent = NULL;
	
	UFUNCTION(BlueprintCallable, Category = Setup)
		void Fire();

	EFiringState GetFiringState() const;

	UFUNCTION(BlueprintCallable, Category = "Firing")
		int32 GetAmmo() const;
private:
	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 40000;   //In m/s

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	

	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditAnywhere, Category = Firing)
		float ReloadTime = 3;
	UPROPERTY(EditAnywhere, Category = Firing)
		double LastTimeFired = 0;
	UPROPERTY(EditAnywhere, Category = Firing)
		int32 RoundsLeft = 3;

	FVector AimDirection;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringState FiringState = EFiringState::Reloading;

	


	
};
