// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward declarations

class UTankBarrel;
class AProjectile;

UCLASS()
class BT_API ATank : public APawn
{
	GENERATED_BODY()

private:

	// Sets default values for this pawn's properties
	ATank();

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 10000; // 50 m/s

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float REloadTimeSeconds = 3;

	float LastFireTime = 0;

	UTankBarrel* Barrel = nullptr; // TODO Remove 

public:	

	UFUNCTION(BlueprintCallable, Category = "Action")
	void Fire();
};
