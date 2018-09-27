// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}
void UTankTrack::BeginPlay()
{
	Super::BeginPlay();
}


void UTankTrack::Throttle(float Throttle)
{
	
	float CurrentThrottle = FMath::Clamp<float>(Throttle, -1, 1);
	Drive(CurrentThrottle);
}

void UTankTrack::Drive(float CurrentThrottle)
{
	
	float ForceApplied = CurrentThrottle*TrackMaxDrivingForce;
	TArray<ASpringWheel*> Wheels = GetWheels();
	float ForcePerWheel = ForceApplied / Wheels.Num();
	for (ASpringWheel* Wheel : Wheels)
	{
		Wheel->AddDrivingForce(ForcePerWheel);
	}

}


