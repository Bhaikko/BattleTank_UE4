// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"

void UTankMovementComponent::TrackReferences(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}


void UTankMovementComponent::IntendMoveForward(float Throw)
{
	LeftTrack->Throttle(Throw);
	RightTrack->Throttle(Throw);

}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	LeftTrack->Throttle(Throw);
	RightTrack->Throttle(-Throw);

}

