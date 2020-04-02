// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"


UTankBarrel::UTankBarrel()
{
	PrimaryComponentTick.bCanEverTick = false;
	auto Mesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Meshes/tank_fbx_Barrel'"));
	if (Mesh.Object)
	{
		SetStaticMesh(Mesh.Object);
		SetRelativeLocation(FVector(0));
	}
}

void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, 0, 20);
	SetRelativeRotation(FRotator(Elevation, 0, 0));

}
