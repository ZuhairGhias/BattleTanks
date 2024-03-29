// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
//#include "TankMovementComponent.h"


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

void ATank::Initialize(UTankBarrel* BarrelToSet) {

	Barrel = BarrelToSet;

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

	Super::SetupPlayerInputComponent(PlayerInputComponent);

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
	

	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTime;

	if (Barrel && isReloaded) {
		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Barrel->GetSocketLocation(FName("Projectile")), Barrel->GetSocketRotation(FName("Projectile")), FActorSpawnParameters());
		Projectile->Launch(ProjectileSpeed);
		LastFireTime = FPlatformTime::Seconds();
		UE_LOG(LogTemp, Warning, TEXT("Fire!"));
	}

	


}