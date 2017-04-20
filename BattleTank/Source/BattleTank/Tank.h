
#pragma once


#include "GameFramework/Pawn.h"
#include "TankAimingComponent.h"
#include "Tank.generated.h"


class UTankBarrel;

/**
*
*/
UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
    void AimAt(FVector HitLocation);
    
    UFUNCTION(BlueprintCallable, Category = Setup)
    void SetBarrelReference(UTankBarrel* BarrelToSet);
    
protected:
    UTankAimingComponent* TankAimingComponent = nullptr;
    
private:

    ATank();
    
    virtual void BeginPlay() override;
    
    virtual void Tick( float DeltaSeconds ) override;
    
    virtual void SetupPlayerComponent(class UInputComponent* InputComponent);
    
    UPROPERTY(EditAnywhere, Category = Firing)
    float LaunchSpeed = 100000; // Sensible starting value of 100 m/s
    
    
};

