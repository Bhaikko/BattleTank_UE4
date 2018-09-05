// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerControllerClass.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerControllerClass : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	ATank* getPlayerControlledTank() const; //Created An Object Of Class Tank
	
	void AimTowardsCrosshair();
	
	bool GetSightRayHitLocation(FVector&) const;
	

	
	
	
	
};
