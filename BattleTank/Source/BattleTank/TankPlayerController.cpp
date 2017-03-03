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
	// Find the crosshair position
	int32 VieportSizeX, ViewportSizeY;
	GetViewportSize(VieportSizeX, ViewportSizeY);
	auto screenLocation = ScreenLocation(VieportSizeX, ViewportSizeY);

	UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *screenLocation.ToString());

	// De-project the screen position of the crosshair to a world direction

	// line trace along the direction and see what we hit


	HitLocation = FVector(1.0);
	return false;
}

FVector2D ATankPlayerController::ScreenLocation(int32 ViewportWidth, int32 ViewportHeight) const
{
	FVector2D ret;

	ret.X = ViewportWidth * CrossHairXLocation;
	ret.Y = ViewportHeight * CrossHairYLocation;

	return ret;
}
