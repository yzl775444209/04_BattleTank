// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"


ATankAIController::ATankAIController()
{
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}


ATank * ATankAIController::GetControlTank()
{
	return Cast<ATank>(GetPawn());
}
