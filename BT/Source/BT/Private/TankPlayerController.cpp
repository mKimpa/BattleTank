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
        UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString());
        // ������������� � HitLocation
    }
    
    

    // �������� ����� �� ������� ��������� ������
    // ���� �� �������� �� ���-��
        // ������������ ����� � ���� �����������

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
    // ������� ��������� ������ ��� ������
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);
    auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

    // ���������� ��� ��������� � ������� ����������
    FVector LookDirection;
    if (GetLookDirection(ScreenLocation, LookDirection))
    {
        GetLookVectorHitLocation(LookDirection, HitLocation);
        return true;
    }
    return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
    FVector CameraWorldLocation; // ��� �� �����
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