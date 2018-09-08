// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurren.h"

void UTankTurren::Rotate(float RelativeSpeed)
{
	//UE_LOG(LogTemp, Warning, TEXT("Turrent Set for %s"), *GetOwner()->GetName());

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	
	float RotationChange = RelativeSpeed * DegreesPerSec * GetWorld()->GetDeltaSeconds();
	float TurrentRotation = RelativeRotation.Yaw + RotationChange;
	
	SetRelativeRotation(FRotator(0,TurrentRotation,0));
}



