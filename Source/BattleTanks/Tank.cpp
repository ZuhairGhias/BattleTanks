// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Protect points as added by constructor
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet) {

	TankAimingComponent->SetBarrelReference(BarrelToSet);

}

void ATank::SetTurretReference(UTankTurret* TurretToSet) {

	TankAimingComponent->SetTurretReference(TurretToSet);

}

void ATank::AimAt(FVector HitLocation) {

	if (TankAimingComponent) {
		//UE_LOG(LogTemp, Warning, TEXT("TankAimingComponent Found"));
		TankAimingComponent->AimAt(HitLocation, ProjectileSpeed);
	}
	else {
		//UE_LOG(LogTemp, Warning, TEXT("TankAimingComponent Not Found"));
	}
	

}

void ATank::Fire() {
	UE_LOG(LogTemp, Warning, TEXT("Fire!"));
}