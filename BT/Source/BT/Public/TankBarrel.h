// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BT_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 - max down speed  |  1 - max up speed
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = "Setup")
	float MaxDegreesPerSecond = 20;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float MaxElevationDegrees = 20;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float MinElevationDegrees = 0;
};
