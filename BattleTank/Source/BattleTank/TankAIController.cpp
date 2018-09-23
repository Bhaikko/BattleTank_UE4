// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();

}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		ATank* PossessedTank = Cast<ATank>(InPawn);
		if (!PossessedTank)
			return;

		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);
		

	}
}

void ATankAIController::OnPossessedTankDeath()
{
	APawn* AITank = GetPawn();
	if (AITank)
		AITank->DetachFromControllerPendingDestroy();
	else
		return;
}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AActor* AITank = GetPawn();
	AActor* PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerTank)
		return;
	MoveToActor(PlayerTank, AcceptanceRadius);
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	if(AimingComponent->GetFiringState()==EFiringState::Locked)
		AimingComponent->Fire();
	
}





