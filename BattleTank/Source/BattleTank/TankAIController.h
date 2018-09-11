// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
public:

	void BeginPlay() override;
	void Tick(float) override;
	
private:
	UPROPERTY(EditDefaultsOnly)
		float AcceptanceRadius = 30;
};
