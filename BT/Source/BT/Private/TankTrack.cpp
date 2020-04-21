// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
	auto Mesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Meshes/tank_fbx_Track'"));
	if (Mesh.Object)
	{
		SetStaticMesh(Mesh.Object);
		SetRelativeLocation(FVector(0));
	}
}
	void UTankTrack::SetThrottle(float Throttle)
	{
		auto Name = GetName();
		UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f"), *Name, Throttle);

		//TODO Clamp Throttle
	}