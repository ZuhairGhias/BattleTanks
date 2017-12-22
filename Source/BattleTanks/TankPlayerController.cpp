// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {

	Super::BeginPlay();
	

}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();

}

ATank* ATankPlayerController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());

}

void ATankPlayerController::AimTowardsCrosshair() {

	if (!GetControlledTank()) { return; }
	

	FVector HitLocation;

	if (GetSightRayHitLocation(HitLocation)) {
	
		
		GetControlledTank()->AimAt(HitLocation);
	
	}
	else {
		//UE_LOG(LogTemp, Warning, TEXT("No Hit!"));
	}

	

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const{

	//Find crosshair location on screen
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	auto CrossHairLocation = FVector2D(ViewPortSizeX*CrossHairLocationX, ViewPortSizeY*CrossHairLocationY);


	FVector LookDirection;
	if (GetLookDirection(CrossHairLocation, LookDirection)) {
		GetLookVectorHitLocation(LookDirection, HitLocation);
		return true;
	}



	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const{

	//Deproject crosshair to worldspace
	FVector CameraLocation;

	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraLocation, LookDirection);

}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const {
	
	FHitResult HitResult;

	auto LineStart = PlayerCameraManager->GetCameraLocation();
	auto LineEnd = LineStart + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		LineStart,
		LineEnd,
		ECollisionChannel::ECC_Visibility
	)) {
		HitLocation = HitResult.Location;
		return true;
	}
	return false;
}
