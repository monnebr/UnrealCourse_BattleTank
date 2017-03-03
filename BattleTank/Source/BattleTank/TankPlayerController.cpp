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

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );

	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
//	UE_LOG(LogTemp, Warning, TEXT("AimTowardsCrosshair"));
	if (!GetControlledTank()) { return; }

	FVector HitLocation;  //Out parameter

	// Get world location of aimed by crosshair
	if (GetSightRayHitLocation(HitLocation)) 
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & HitLocation) const
{
	
	return false;
}
