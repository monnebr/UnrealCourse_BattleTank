// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 left, +1 right
	void Rotate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 25; // sensible default

	//UPROPERTY(EditAnywhere, Category = Setup)
	//float MaxRotationDegrees = 180; // sensible default

	//UPROPERTY(EditAnywhere, Category = Setup)
	//float MinRotationDegrees = -180; // sensible default

	
};
