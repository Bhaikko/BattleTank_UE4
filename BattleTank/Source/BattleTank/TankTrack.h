// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

private:
	UTankTrack();
	virtual void BeginPlay() override;
	void SideFriction();

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	float CurrentThrottle = 0;

public:
	UFUNCTION(BlueprintCallable, Category = Input)
		void Throttle(float Throttle);

	void Drive();

	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 40000;// Assume 40 Tonne Tank and 1g acceleration
	
	
	
};
