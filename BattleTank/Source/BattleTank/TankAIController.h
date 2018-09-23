// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"
#include "TankAimingComponent.h"
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
	
	virtual void SetPawn(APawn* InPawn) override;

	
	
protected:
	UPROPERTY(EditAnywhere, Category = "Setup")
		float AcceptanceRadius = 8000;
private:
	UTankAimingComponent* AimingComponent = nullptr;

	UFUNCTION()
		void OnPossessedTankDeath();
};
