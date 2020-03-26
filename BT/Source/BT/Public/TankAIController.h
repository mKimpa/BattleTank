// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BT_API ATankAIController : public AAIController
{
	GENERATED_BODY()

	private:
	virtual void BeginPlay() override;

	public:
	ATank* GetControlledTank() const;
	
};