// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Engine/World.h"
#include "TankAIController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	

private:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
	ATank* PlayerTank = nullptr;
	ATank* ControlledTank = nullptr;

	float AcceptanceRadius = 3000.f;
};
