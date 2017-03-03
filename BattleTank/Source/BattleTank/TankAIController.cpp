// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (ControlledTank) {
		FString tankName = ControlledTank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("TankAIController controls  %s"), *tankName);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController do not control a tank!"));
	}
}
