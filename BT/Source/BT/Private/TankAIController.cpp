// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
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
        auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
        auto ControlledTank = GetPawn();
        if (!ensure(PlayerTank && ControlledTank)) { return; }
        {
            MoveToActor(PlayerTank, AcceptanceRadius); //TODO check radius is in cm 
            auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
            AimingComponent->AimAt(PlayerTank->GetActorLocation());

            //if aiming or locked
            if (AimingComponent->GetFiringState() == EFiringState::Locked)
            {
                AimingComponent->Fire();
            }
        }
    }

    void ATankAIController::SetPawn(APawn* InPawn)
    {
        Super::SetPawn(InPawn);
        if (InPawn)
        {
            auto PossesedTank = Cast<ATank>(InPawn);
            if (!ensure(PossesedTank)) { return;}
            PossesedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossesedTankDeath);
        }
    }

    void ATankAIController::OnPossesedTankDeath()
    {
        UE_LOG(LogTemp, Warning, TEXT("Recieved!"))
    }



