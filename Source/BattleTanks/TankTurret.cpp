// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

void UTankTurret::Rotate(float RotationRate) {

	float RotationChange = RotationRate * MaxRotationRate * GetWorld()->DeltaTimeSeconds;
	auto newRotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, newRotation, 0));

}


