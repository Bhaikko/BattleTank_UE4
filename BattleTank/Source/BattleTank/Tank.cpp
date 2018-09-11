// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));	
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation,LaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelComponent(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::SetTurrentReference(UTankTurren * TurrenToSet)
{
	TankAimingComponent->SetTurrentComponent(TurrenToSet);
}

void ATank::Fire()
{
	bool bIsReloaded = (GetWorld()->GetTimeSeconds() - LastTimeFired) > ReloadTime;
	if (Barrel&&bIsReloaded)
	{
		FVector BarrelSocketLocation = Barrel->GetSocketLocation(FName("Projectile"));
		FRotator BarrelSocketRotation = Barrel->GetSocketRotation(FName("Projectile"));
		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, BarrelSocketLocation, BarrelSocketRotation);
		Projectile->Launch(LaunchSpeed);

		LastTimeFired = GetWorld()->GetTimeSeconds();
	}

}
