// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * Responsible for driving the tank tracks
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendMoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Input")
		void IntendTurnRight(float Throw);
	
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;

	UFUNCTION(BlueprintCallable, Category = "Input")
		void Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

	void RequestDirectMove(const FVector& MoveVelocity, bool bforceMaxSpeed) override;
	
};
