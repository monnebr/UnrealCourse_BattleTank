#pragma once

#include "GameFramework/Pawn.h"
#include "TankAimingComponent.h"
#include "Tank.generated.h"


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
    void SetBarrelReference(UStaticMeshComponent* BarrelToSet);
    
protected:
    UTankAimingComponent* TankAimingComponent = nullptr;
    
private:

    ATank();
    
    virtual void BeginPlay() override;
    
    virtual void Tick( float DeltaSeconds ) override;
    
    virtual void SetupPlayerComponent(class UInputComponent* InputComponent);
    
};

