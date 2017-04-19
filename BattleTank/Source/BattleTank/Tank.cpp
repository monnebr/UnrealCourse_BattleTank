#include "BattleTank.h"
#include "Tank.h"


ATank::ATank()
{
 
    TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

void ATank::BeginPlay()
{
    
}

void ATank::Tick( float DeltaSeconds )
{
    
}

void ATank::SetupPlayerComponent(class UInputComponent* InputComponent)
{
    
}

void ATank::AimAt(FVector HitLocation)
{
    TankAimingComponent->AimAt(HitLocation);
}

void ATank::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
    TankAimingComponent->SetBarrelReference(BarrelToSet);
}
