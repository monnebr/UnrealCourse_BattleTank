#include "BattleTank.h"
#include "Tank.h"


ATank::ATank()
{
    
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
    auto OurTankName = GetName();
    
    UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s"), *OurTankName, *HitLocation.ToString());

}
