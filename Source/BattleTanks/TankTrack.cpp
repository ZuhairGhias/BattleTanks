// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle) {

	// UE_LOG(LogTemp, Warning, TEXT("%s %f throttle"), *GetName(), Throttle);

	auto ForceApplied = Throttle * MaxDrivingForce * GetForwardVector();
	auto ForceLocation = GetComponentLocation();

	auto TankRoot =Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

}


