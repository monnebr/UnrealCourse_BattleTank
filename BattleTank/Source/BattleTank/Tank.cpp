#include "BattleTank.h"
#include "Tank.h"


ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;

    TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

void ATank::BeginPlay()
{
    Super::BeginPlay();
    
}

void ATank::SetupPlayerComponent(class UInputComponent* InputComponent)
{
    
}

void ATank::AimAt(FVector HitLocation)
{
    TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
    UE_LOG(LogTemp, Warning, TEXT("Barrell Set in tank %s"), *GetName());
    
    TankAimingComponent->SetBarrelReference(BarrelToSet);
}
