// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h "
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;

	virtual void Tick( float DeltaTime ) override;
	
private:
	// start the tank moving the barrel so that the shot would hit where the crosshair interset the shot
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation) const;
};
