// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BT_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

	private:

	virtual void BeginPlay() override;
	ATank* GetControlledTank() const;

	//Поворачивает ствол пока выстрел не попадет в точку прицеливания
	void AimTowardsCrosshair();

	public:
	
	virtual void Tick(float DeltaTime) override;
	
};
