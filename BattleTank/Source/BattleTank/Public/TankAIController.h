// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
public:
	ATankAIController();

protected:
	virtual void BeginPlay() override;
public:

	//获得控制的Tank
	class ATank* GetControlTank();
};
