// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankTrack.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;
/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
		
public:
	UFUNCTION(BlueprintCallable, Category = Input)
		void IntendMoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void IntendTurnRight(float Throw);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void TrackReferences(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

private:
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;

	float Speed = 40000;
	
	
};
