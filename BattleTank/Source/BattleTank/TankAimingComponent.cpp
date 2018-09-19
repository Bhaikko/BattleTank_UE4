// Fill out your copyright notice in the Description page of Project Settings.
 // Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"



// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}
void UTankAimingComponent::BeginPlay()
{
	LastTimeFired = GetWorld()->GetTimeSeconds();
}
void UTankAimingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	if (RoundsLeft == 0)
		FiringState = EFiringState::OutOfAmmo;
	else if ((GetWorld()->GetTimeSeconds() - LastTimeFired) < ReloadTime)  //Reloaded
	{
		FiringState = EFiringState::Reloading;
	}
	else if (IsBarrelMoving())
	{
		FiringState = EFiringState::Aiming;
	}
	else
		FiringState = EFiringState::Locked;

	

}

void UTankAimingComponent::AimAt(FVector Location)
{
	if (!Barrel||!Turrent)
		return;

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	float Time = GetWorld()->GetTimeSeconds();
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, Location, LaunchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace);
	if (bHaveAimSolution)
	{
		AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrel(AimDirection);
	}
}
void UTankAimingComponent::Initialse(UTankBarrel* BarrelToSet, UTankTurren* TurrentToSet)
{
	Barrel = BarrelToSet;
	Turrent = TurrentToSet;
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{

	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator DeltaRotation = AimAsRotator - BarrelRotator;

	Barrel->Elevate(DeltaRotation.Pitch);
	if (FMath::Abs(DeltaRotation.Yaw) >= 180)
		Turrent->Rotate(-DeltaRotation.Yaw);
	else
		Turrent->Rotate(DeltaRotation.Yaw);
	
}

void UTankAimingComponent::Fire()
{
	
	if (FiringState==EFiringState::Locked || FiringState == EFiringState::Aiming)
	{
		FVector BarrelSocketLocation = Barrel->GetSocketLocation(FName("Projectile"));
		FRotator BarrelSocketRotation = Barrel->GetSocketRotation(FName("Projectile"));
		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, BarrelSocketLocation, BarrelSocketRotation);
		Projectile->Launch(LaunchSpeed);	
		LastTimeFired = GetWorld()->GetTimeSeconds();
		RoundsLeft--;
	}
	else
		return;

}

bool UTankAimingComponent::IsBarrelMoving()
{
	return !Barrel->GetForwardVector().FVector::Equals(AimDirection, 0.01);
}

EFiringState UTankAimingComponent::GetFiringState() const
{
	return FiringState;
}

int UTankAimingComponent::GetAmmo() const
{
	return RoundsLeft;
}