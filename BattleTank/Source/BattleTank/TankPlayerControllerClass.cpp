// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerControllerClass.h"

void ATankPlayerControllerClass::BeginPlay()
{
	Super::BeginPlay();
	
	ATank* ControlledTank = getPlayerControlledTank();

	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s in player controll"), *ControlledTank->GetName());
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Player In Controll"));

}

void ATankPlayerControllerClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ATank* ATankPlayerControllerClass::getPlayerControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerControllerClass::AimTowardsCrosshair()
{
	if (!getPlayerControlledTank())
		return;

	FVector HitLocation;


}

bool ATankPlayerControllerClass::GetSightRayHitLocation(FVector& OutHitLocation) const
{

}



