#pragma once

#include "GameFramework/Pawn.h"
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
    
private:

    ATank();
    
    virtual void BeginPlay() override;
    
    virtual void Tick( float DeltaSeconds ) override;
    
    virtual void SetupPlayerComponent(class UInputComponent* InputComponent);
    
};

