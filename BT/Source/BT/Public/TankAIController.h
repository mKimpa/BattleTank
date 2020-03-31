// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "GameFramework/Actor.h"
#include "TankAIController.generated.h"

// Forward declarations
class ATank;

/**
 * 
 */
UCLASS()
class BT_API ATankAIController : public AAIController
{
	GENERATED_BODY()

	private:
	virtual void BeginPlay() override;
	virtual void Tick(float Deltatime) override;

	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;
	void AimAtPlayer();
};
