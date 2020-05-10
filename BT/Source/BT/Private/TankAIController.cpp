// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
 
}

void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    AimAtPlayer();
}

    void ATankAIController::AimAtPlayer()
    {
        auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
        if (PlayerTank)
        {
            auto ControlledTank = Cast<ATank>(GetPawn());
            if (ControlledTank)
            {
                MoveToActor(PlayerTank, AcceptanceRadius); //TODO check radius is in cm 

                ControlledTank->AimAt(PlayerTank->GetActorLocation());
                ControlledTank->Fire(); //TODO dont fire every frame
            }

        }
    }



