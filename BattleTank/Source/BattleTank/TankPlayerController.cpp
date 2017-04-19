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
        GetControlledTank()->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & HitLocation) const
{
	// Find the crosshair position
	int32 VieportSizeX, ViewportSizeY;
	GetViewportSize(VieportSizeX, ViewportSizeY);
	auto screenLocation = ScreenLocation(VieportSizeX, ViewportSizeY);

	// De-project the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(screenLocation, LookDirection))
	{
		// UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *LookDirection.ToString());

		// line trace along the direction and see what we hit (up to some maximum range)
		if (GetLookVectorHitLocation(LookDirection, HitLocation)) {
			// UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString());
			return true;
		}
	}
	return false;
}

FVector2D ATankPlayerController::ScreenLocation(int32 ViewportWidth, int32 ViewportHeight) const
{
	FVector2D ret;

	ret.X = ViewportWidth * CrossHairXLocation;
	ret.Y = ViewportHeight * CrossHairYLocation;

	return ret;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	FVector TraceStart;
	FVector TraceEnd;

	TraceStart = PlayerCameraManager->GetCameraLocation();
	TraceEnd = TraceStart + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		TraceStart,
		TraceEnd,
		ECollisionChannel::ECC_Visibility )) 
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}
