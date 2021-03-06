// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float);
	
private:
	UPROPERTY(EditAnywhere, Category = SetUp)
		float MaxDegreesPerSec = 10;
	UPROPERTY(EditAnywhere, Category = SetUp)
		float MaxElevation = 40;
	UPROPERTY(EditAnywhere, Category = SetUp)
		float MinElevation = 0;

};
