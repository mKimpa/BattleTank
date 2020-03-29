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
    AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
    if (!GetControlledTank()) { return; }

    FVector HitLocation; // Out parameter
    if (GetSightRayHitLocation(HitLocation))
    {
        GetControlledTank()->AimAt(HitLocation);
    }
    
    

    // Получить место на которое указывает прицел
    // Если мы попадаем на что-то
        // Поворачиваем ствол в этом направлении

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
    // Находим положение прицел ана экране
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);
    auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

    // Проецируем это положение в мировые координаты
    FVector LookDirection;
    if (GetLookDirection(ScreenLocation, LookDirection))
    {
        GetLookVectorHitLocation(LookDirection, HitLocation);
        return true;
    }
    HitLocation = FVector(0);
    return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
    FVector CameraWorldLocation; // нам не нужен
    return DeprojectScreenPositionToWorld(
        ScreenLocation.X,
        ScreenLocation.Y,
        CameraWorldLocation,
        LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
    FHitResult OutHit;
    auto StartLocation = PlayerCameraManager->GetCameraLocation();
    auto EndLocation = LookDirection * ShootingDistance;
    if (GetWorld()->LineTraceSingleByChannel(
        OutHit,
        StartLocation,
        EndLocation,
        ECollisionChannel::ECC_Visibility))
    {
        HitLocation = OutHit.Location;
        return true;
    }
    return false;
}