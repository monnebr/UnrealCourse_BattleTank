// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankPlayerController.h"
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

	auto PlayerTank = GetPlayerTank();
	if (PlayerTank) {
		FString tankName = PlayerTank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("TankAIController found player tank %s"), *tankName);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController cannot find player tank!"));
	}

}

ATank* ATankAIController::GetPlayerTank() const
{
	APlayerController* playerController = GetWorld()->GetFirstPlayerController();
	if (!playerController) {
		UE_LOG(LogTemp, Error, TEXT("TankAIController could not find player controller!"));
		return nullptr;
	}
	APawn* playerTank = playerController->GetPawn();
	if (!playerTank) {
		UE_LOG(LogTemp, Error, TEXT("TankAIController could not find player tank!"));
		return nullptr;
	}
	return Cast<ATank>(playerTank);
}


void ATankAIController::Tick( float DeltaTime )
{
    Super::Tick(DeltaTime);
    
    if(GetPlayerTank()) {
        // TODO MOve toward the player
    
        // Aim towards the player
        GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
    
        // Fire if ready
    
        
    }
}
