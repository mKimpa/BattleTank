// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

UTankTurret::UTankTurret()
{
	PrimaryComponentTick.bCanEverTick = false;
	auto Mesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Meshes/tank_fbx_Turret'"));
	if (Mesh.Object)
	{
		SetStaticMesh(Mesh.Object);
		SetRelativeLocation(FVector(0));
	}
}


void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;;
	auto NewRotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, NewRotation, 0));
}