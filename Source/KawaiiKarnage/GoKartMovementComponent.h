// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/World.h"
#include "GameFrameWork/GameState.h"
#include "GoKartMovementComponent.generated.h"

USTRUCT()
struct FGoKartMove
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	float Throttle;

	UPROPERTY()
	float SteeringThrow;

	UPROPERTY()
	float DeltaTime;

	UPROPERTY()
	float Time;

	bool IsValid() const
	{
		return FMath::Abs(Throttle) <= 1 && FMath::Abs(SteeringThrow) <= 1;
	}

};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class KAWAIIKARNAGE_API UGoKartMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGoKartMovementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	// Called every frame
	void SimulateMove(const FGoKartMove& Move);
	

	FVector GetVelocity() { return Velocity; };
	void SetVelocity(FVector Val) { Velocity = Val; };
	void SetThrottle(float Val) { Throttle = Val; };
	void SetSteeringThrow(float Val) { SteeringThrow = Val; };
	FGoKartMove GetLastMove() { return LastMove; };


private:
	
	FGoKartMove CreateMove(float DeltaTime);
	FVector GetAirResistance();
	FVector GetRollingResistance();
	void ApplyRotation(float DeltaTime, float SteeringThrow);
	void UpdateLocationFromVelocity(float DeltaTime);

	// Mass of the car (kg)
	UPROPERTY(EditAnywhere)
	float Mass = 1000;

	//force applied to car when throttle is fully down (n)
	UPROPERTY(EditAnywhere)
	float MaxDrivingForce = 10000;

	//Minimum Radius of the car turning circle at full lock (m)
	UPROPERTY(EditAnywhere)
	float MinimumTurningRadius = 10;


	// Higher means more drag
	UPROPERTY(EditAnywhere)
	float DragCoEfficient = 2.5;

	// Resistance while car is rolling, normal car values are between 0.01 and 0.015
	UPROPERTY(EditAnywhere)
	float RollingResistanceCoEfficient = 0.015;

	UPROPERTY(EditAnywhere)
	FVector Velocity;


	float Throttle;
	float SteeringThrow;
	FGoKartMove LastMove;

	


};
