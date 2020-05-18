// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "Components/InputComponent.h"
#include "Tank.h"
ATankPlayerController::ATankPlayerController()
{

}


void ATankPlayerController::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("eeeeeeeeeeeeeeeeee"));
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay %s"),*this->GetControlTank()->GetName());

}




ATank* ATankPlayerController::GetControlTank()
{
	return Cast<ATank>(GetPawn());
}
