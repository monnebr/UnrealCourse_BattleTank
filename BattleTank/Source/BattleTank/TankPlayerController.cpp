// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (ControlledTank) {
		FString tankName = ControlledTank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("ATankPlayerController control %s"), *tankName);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("ATankPlayerController do not control a tank!"));
	}
}
