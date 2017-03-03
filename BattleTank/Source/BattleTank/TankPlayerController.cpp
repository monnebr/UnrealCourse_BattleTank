// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	// APlayerController::BeginPlay();
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("PlayerController BeginPlay() "));

	auto ControlledTank = GetControlledTank();
	if (ControlledTank) {
		FString tankName = ControlledTank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("Tank name is  %s"), *tankName);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("NO TANK!!!!"));
	}

}
