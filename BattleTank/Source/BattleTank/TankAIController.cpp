// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankPlayerController.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::Tick( float DeltaTime )
{
    Super::Tick(DeltaTime);

	// Obtain Player tank
	APlayerController* playerController = GetWorld()->GetFirstPlayerController();
	if (!playerController) {
		UE_LOG(LogTemp, Error, TEXT("TankAIController could not find player controller!"));
		return;
	}
	APawn* PlayerPawn = playerController->GetPawn();
	if (!PlayerPawn) {
		UE_LOG(LogTemp, Error, TEXT("TankAIController could not find player tank!"));
		return;
	}
	ATank *PlayerTank = Cast<ATank>(PlayerPawn);
    
    if(PlayerTank) {
		// Objtain Controlled Tank
		ATank *ControlledTank = Cast<ATank>(GetPawn());

        // TODO MOve toward the player
    
        // Aim towards the player
        ControlledTank->AimAt(PlayerTank->GetActorLocation());
    
        // Fire if ready
		ControlledTank->Fire();
        
    }
}
