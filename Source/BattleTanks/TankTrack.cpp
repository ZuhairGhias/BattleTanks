// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

UTankTrack::UTankTrack() {

	PrimaryComponentTick.bCanEverTick = true;

}

void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction){

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	auto Slippage = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	auto CorrectionAccel = -Slippage / DeltaTime * GetRightVector();

	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = TankRoot->GetMass() * CorrectionAccel / 2;
	TankRoot->AddForce(CorrectionForce);

}

void UTankTrack::SetThrottle(float Throttle) {

	// UE_LOG(LogTemp, Warning, TEXT("%s %f throttle"), *GetName(), Throttle);

	auto ForceApplied = Throttle * MaxDrivingForce * GetForwardVector();
	auto ForceLocation = GetComponentLocation();

	auto TankRoot =Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

}


