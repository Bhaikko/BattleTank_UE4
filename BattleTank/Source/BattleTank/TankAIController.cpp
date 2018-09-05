// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* AIControlledTank = ControlledTank();
	ATank* Found = GetPlayerTank();
	if (Found)
		UE_LOG(LogTemp, Warning, TEXT("%s is looking at %s"), *AIControlledTank->GetName(), *Found->GetName());

}

ATank* ATankAIController::ControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	AActor* Tank = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>(Tank);
}

