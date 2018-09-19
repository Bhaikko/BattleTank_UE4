// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();

}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AActor* AITank = GetPawn();
	AActor* PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	//UE_LOG(LogTemp, Warning, TEXT("Radius %f"), AcceptanceRadius);
	MoveToActor(PlayerTank, AcceptanceRadius);
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	if(AimingComponent->GetFiringState()==EFiringState::Locked)
		AimingComponent->Fire();
	
}





