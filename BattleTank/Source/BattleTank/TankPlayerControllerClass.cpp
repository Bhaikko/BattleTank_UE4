// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerControllerClass.h"

void ATankPlayerControllerClass::BeginPlay()
{
	Super::BeginPlay();
	
	ATank* ControlledTank = getPlayerControlledTank();

	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s in player controll"), *ControlledTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player In Controll"));
	}

}



ATank* ATankPlayerControllerClass::getPlayerControlledTank() const
{
	return Cast<ATank>(GetPawn());
}




