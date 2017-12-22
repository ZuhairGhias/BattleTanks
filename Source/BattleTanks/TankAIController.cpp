// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay() {

	Super::BeginPlay();

	ATank* PlayerTank = GetPlayerTank();
	if (PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("Found Player Tank: %s"), *PlayerTank->GetName());
	}

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ATank* PlayerTank = GetPlayerTank();
	if (PlayerTank) {
		GetControlledTank()->AimAt(PlayerTank->GetActorLocation());
	}
	


}

ATank* ATankAIController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());

}

ATank* ATankAIController::GetPlayerTank() const {

	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}


