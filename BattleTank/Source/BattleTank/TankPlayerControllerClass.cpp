// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerControllerClass.h"

void ATankPlayerControllerClass::BeginPlay()
{

	Super::BeginPlay();
	AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (AimingComponent)
		FoundAimingComponent(AimingComponent);
}

void ATankPlayerControllerClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	AimTowardsCrosshair();

}

void ATankPlayerControllerClass::AimTowardsCrosshair()
{
	if (!GetPawn())
		return;
	;
	FVector HitLocation;
	bool bHit = GetSightRayHitLocation(HitLocation);
	if (bHit)
	{
		AimingComponent->AimAt(HitLocation);
	}
}

bool ATankPlayerControllerClass::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	int32 ViewportXSize, ViewportYSize;
	GetViewportSize(ViewportXSize, ViewportYSize);
	FVector2D ScreenLocation(ViewportXSize * CrossHairXLocation, ViewportYSize * CrossHairYLocation);

	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))	
		return GetLookVectorHitLocation(LookDirection, OutHitLocation);
	return false;
}

bool ATankPlayerControllerClass::GetLookDirection(FVector2D ScreenLocation,FVector &WorldDirection) const 
{
	FVector CameraWorldLocation;//To Discard
	DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, WorldDirection);
	return true;
}

bool ATankPlayerControllerClass::GetLookVectorHitLocation(FVector LookDirection,FVector& HitLocation) const
{
	FHitResult HitResult;
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + (LookDirection * LineTraceRange);
	
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(GetOwner());
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility,Params))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0,0,0);
	return false;

}




