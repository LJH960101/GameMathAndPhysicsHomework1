// Fill out your copyright notice in the Description page of Project Settings.

#include "PhysicalSphere.h"

// Position을 갱신한다.
void APhysicalSphere::RefreshPosition()
{
	// 언리얼 3D에서 위쪽은 Z이기에 Z에다가 Y를 넣는다.
	SetActorLocation(FVector(positionX, 0.0f, positionY));
}

// Position을 되돌린다.
void APhysicalSphere::ResetPosition()
{
	// 초기 속도를 다시 설정한다.
	vectorX = initVecX;
	vectorY = initVecY;
	// 위치를 다시 설정한다.
	positionX = initPosX;
	positionY = initPosY + halfSphereHeight; // 공의 높이의 절반 위에.
	platform->SetActorLocation(FVector(initPosX, 0.0f, initPosY));
	RefreshPosition();
}

// 떨어 졌는가?
bool APhysicalSphere::isDropped()
{
	// 땅이 0이므로 높이가 공의 높이 만큼 있는지 조사 한다.
	return GetActorLocation().Z < halfSphereHeight;
}

// Sets default values
APhysicalSphere::APhysicalSphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// 새로운 속도, 각도를 넣는다.
void APhysicalSphere::SetNewValue(float angle, float initVec, float posY)
{
	// Degree를 Rad로 바꿈.
	float rad = angle * pie / 180.0f;

	// 속도를 계산한다.
	initVecX = FMath::Cos(rad) * initVec;
	initVecY = FMath::Sin(rad) * initVec;

	initPosY = posY;

	ResetPosition();
}

// Called when the game starts or when spawned
void APhysicalSphere::BeginPlay()
{
	Super::BeginPlay();
	// 초기 값으로 갱신
	SetNewValue(60.0f, 1000.0f, 500.0f);
	ResetPosition();
}

// Called every frame
void APhysicalSphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Y 속도에 중력가속도를 더해준다.
	vectorY += gravityAccelation * DeltaTime;
	// X, Y는 속도만큼 더해준다.
	positionX += vectorX * DeltaTime;
	positionY += vectorY * DeltaTime;

	// 땅에 닿았다면 위치 초기화
	if (isDropped()) ResetPosition();
	else RefreshPosition();
}

