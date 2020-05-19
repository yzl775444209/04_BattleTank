// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ATankPlayerController();

	UPROPERTY(EditAnywhere)
		float CrossChairLoactionX = 0.5;
	UPROPERTY(EditAnywhere)
		float CrossChairLoactionY = 0.333333;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:

	//获得控制的Tank
	class ATank* GetControlTank();
	void AimTowardCrosshair();
	bool GetSightRayHitLocation(FVector& HitLocation);
};
