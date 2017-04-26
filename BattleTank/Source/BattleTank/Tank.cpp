#include "BattleTank.h"
#include "Tank.h"
#include "TankAimingComponent.h"


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
    TankAimingComponent->SetBarrelReference(BarrelToSet);
}

void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

void ATank::Fire()
{
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f: Fire!"), Time);
}
