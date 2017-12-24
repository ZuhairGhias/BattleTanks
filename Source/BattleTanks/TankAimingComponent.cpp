// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet) {

	Barrel = BarrelToSet;

}

void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet) {

	Turret = TurretToSet;

}
void UTankAimingComponent::AimAt(FVector HitLocation, float ProjectileSpeed) {

	if (!Barrel || !Turret) { return; }
	
	FVector OUTLaunchVelocity;
	//FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	if (UGameplayStatics::SuggestProjectileVelocity(
	
		this,
		OUTLaunchVelocity,
		StartLocation,
		HitLocation,
		ProjectileSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace,
		FCollisionResponseParams::DefaultResponseParam,
		TArray<AActor*>(),
		false
	)) {
	
		auto AimDirection = OUTLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
		MoveTurretTowards(AimDirection);
		//UE_LOG(LogTemp, Warning, TEXT("%f: Aim Solution Found"), GetWorld()->GetTimeSeconds());

	}
	else {
		//UE_LOG(LogTemp, Warning, TEXT("%f: No Aim Solution Found"), GetWorld()->GetTimeSeconds());
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) {

	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto BarrelDeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(BarrelDeltaRotator.Pitch);

}

void UTankAimingComponent::MoveTurretTowards(FVector AimDirection) {

	auto TurretRotator = Turret->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto TurretDeltaRotator = AimAsRotator - TurretRotator;

	// TODO Fix the way this rotates
	//UE_LOG(LogTemp, Warning, TEXT("Rotate: %f"), TurretDeltaRotator.Yaw);


	

	if (FMath::Abs(TurretDeltaRotator.Yaw) < 180)

	{

		Turret->Rotate(TurretDeltaRotator.Yaw);

	}
	
	else // Avoid going the long-way round

	{

		Turret->Rotate(-TurretDeltaRotator.Yaw);

	}


}