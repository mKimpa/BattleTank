// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
    auto PlayerTank = GetPlayerTank();
    if (!PlayerTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank!"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("AIController found player tank: %s"), *PlayerTank->GetName());
    }
}

void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    AimAtPlayer();
}

    ATank* ATankAIController::GetPlayerTank() const
    {
        auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
        if (!PlayerPawn) { return nullptr; }
        return Cast<ATank>(PlayerPawn);
    }

    void ATankAIController::AimAtPlayer()
    {
        auto PlayerTank = GetPlayerTank();
        if (PlayerTank)
        {
            GetControlledTank()->AimAt(PlayerTank->GetActorLocation());
        }2
    }



