// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"


void UTankBarrel::Elevate(float ElevationRate) {


	auto ElevationChange = ElevationRate * MaxElevationRate * GetWorld()->DeltaTimeSeconds;
	auto NewElevation = FMath::Clamp(RelativeRotation.Pitch + ElevationChange, Minelevation, MaxElevation);

	SetRelativeRotation(FRotator(NewElevation, 0, 0));
}

