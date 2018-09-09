// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ATank* AITank = Cast<ATank>(GetPawn());
	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	AITank->AimAt(PlayerTank->GetActorLocation());
	AITank->Fire();
}





