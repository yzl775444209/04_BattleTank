// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "TankPlayerController.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("QuitBattle", IE_Pressed, this, &ATank::QuitGame);

}

void ATank::QuitGame()
{
	UE_LOG(LogTemp, Warning, TEXT("eeeeeeeeeeeeeeeeee"));
	//UKismetSystemLibrary::QuitGame(GetWorld(), this, EQuitPreference::Quit, false);
	UKismetSystemLibrary::QuitGame(GetWorld(), Cast<ATankPlayerController>( this->GetController()), EQuitPreference::Quit, false);
}