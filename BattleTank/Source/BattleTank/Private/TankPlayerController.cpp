// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "Components/InputComponent.h"
#include "Tank.h"
ATankPlayerController::ATankPlayerController()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}


void ATankPlayerController::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("eeeeeeeeeeeeeeeeee"));
	ATank * tank = this->GetControlTank();
	if (tank) {
		UE_LOG(LogTemp, Warning, TEXT("BeginPlay %s"), *this->GetControlTank()->GetName());
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardCrosshair();
	UE_LOG(LogTemp, Warning, TEXT("Player contorller ticking"));

}




ATank* ATankPlayerController::GetControlTank()
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardCrosshair()
{
	if (!GetControlTank()) { return; }
	FVector HitLocation;
	GetSightRayHitLocation(HitLocation);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *HitLocation.ToString());
}
//获得视线看到的点
bool ATankPlayerController::GetSightRayHitLocation(FVector & HitLocation)
{
	int32 ViewportSizeX, ViewPortSizeY;
	//获取屏幕分辨率
	GetViewportSize(ViewportSizeX, ViewPortSizeY);
	//转换准星的位置
	auto ScreenLoaction = FVector2D(CrossChairLoactionX*ViewportSizeX, CrossChairLoactionY*ViewPortSizeY);
	FVector WorldLoaction;
	FVector WorldDirection;
	//转换屏幕坐标到世界坐标
	bool bSucess = DeprojectScreenPositionToWorld(ScreenLoaction.X, ScreenLoaction.Y, WorldLoaction, WorldDirection);
	return bSucess;
}
