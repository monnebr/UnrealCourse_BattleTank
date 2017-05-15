
#pragma once


#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimingComponent;
class UTankBarrel;
class UTankTurret;
class AProjectile;

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
	
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = Control)
	void Fire();


protected:
    UTankAimingComponent* TankAimingComponent = nullptr;
    
private:

    ATank();
    
    virtual void BeginPlay() override;
     
    virtual void SetupPlayerComponent(class UInputComponent* InputComponent);
    
    UPROPERTY(EditDefaultsOnly, Category = Firing)
    float LaunchSpeed = 4000; // Sensible starting value of 100 m/s
    
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeInSeconds = 3;

	// Local barrel reference for spawning a projectile
	UTankBarrel* Barrel = nullptr;

	double LastFireTime = 0;
};

