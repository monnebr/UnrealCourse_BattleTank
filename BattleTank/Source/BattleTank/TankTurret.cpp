// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"


void UTankTurret::Rotate(float RelativeSpeed)
{
	// Move the barrel the right amount this frame
	// Given a max elevation speed and the frame rate
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	
	UE_LOG(LogTemp, Warning, TEXT("Rel Speed: %f, RotationChange: %f, Rotation: %f"), RelativeSpeed, RotationChange, Rotation);

	SetRelativeRotation(FRotator(0, Rotation, 0));
}