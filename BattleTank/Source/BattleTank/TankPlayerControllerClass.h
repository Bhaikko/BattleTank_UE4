// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"
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
	void AimTowardsCrosshair();
	
private:
	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.333333;
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000;  //Units In Centimetres

	bool GetLookDirection(FVector2D ScreenLocation, FVector &WorldDirection) const;  //This Returned A unit Vector in the direction of crosshair

	bool GetLookVectorHitLocation(FVector,FVector&) const; 
	bool GetSightRayHitLocation(FVector&) const;
	
protected:
	UFUNCTION(BlueprintCallable,Category="Setup")
		ATank* getPlayerControlledTank() const; //Created An Object Of Class Tank

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimCompRef);  //Defination In TankPlayerBlueprint

	

	
	
};
