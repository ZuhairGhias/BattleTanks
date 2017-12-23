// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "TankBarrel.generated.h"

 // Holds barrels propertie's and Elevate method
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	// Rate is relative from 1 to -1
	void Elevate(float ElevatationRate);
	
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationRate = 20.f;
	
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevation = 45.f;

	UPROPERTY(EditAnywhere, Category = Setup)
		float Minelevation = -15.f;
};
