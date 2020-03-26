// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
    auto ControlledTank = GetControlledTank();
    if (!ControlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Player start on %s"), *GetPawn()->GetName());
    }
}

void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    //AimTowardsCrosshair
    UE_LOG(LogTemp, Warning, TEXT("PlayerController: TICK!"));
}

void ATankPlayerController::AimTowardsCrosshair()
{
    if (!GetControlledTank()) { return;  }

    // ѕолучить место на которое указывает прицел
    // ≈сли мы попадаем на что-то
        // ѕоворачиваем ствол в этом направлении

}