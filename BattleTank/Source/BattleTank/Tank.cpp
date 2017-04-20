#include "BattleTank.h"
#include "Tank.h"


ATank::ATank()
{
 
    TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

void ATank::BeginPlay()
{
    Super::BeginPlay();
    
}

void ATank::Tick( float DeltaSeconds )
{
    Super::Tick(DeltaSeconds);
}

void ATank::SetupPlayerComponent(class UInputComponent* InputComponent)
{
    
}

void ATank::AimAt(FVector HitLocation)
{
    TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
    UE_LOG(LogTemp, Warning, TEXT("Barrell Set in tank %s"), *GetName());
    
    TankAimingComponent->SetBarrelReference(BarrelToSet);
}
