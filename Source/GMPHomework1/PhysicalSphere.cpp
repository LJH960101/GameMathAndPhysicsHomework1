// Fill out your copyright notice in the Description page of Project Settings.

#include "PhysicalSphere.h"

// Position�� �����Ѵ�.
void APhysicalSphere::RefreshPosition()
{
	// �𸮾� 3D���� ������ Z�̱⿡ Z���ٰ� Y�� �ִ´�.
	SetActorLocation(FVector(positionX, 0.0f, positionY));
}

// Position�� �ǵ�����.
void APhysicalSphere::ResetPosition()
{
	// �ʱ� �ӵ��� �ٽ� �����Ѵ�.
	vectorX = initVecX;
	vectorY = initVecY;
	// ��ġ�� �ٽ� �����Ѵ�.
	positionX = initPosX;
	positionY = initPosY + halfSphereHeight; // ���� ������ ���� ����.
	platform->SetActorLocation(FVector(initPosX, 0.0f, initPosY));
	RefreshPosition();
}

// ���� ���°�?
bool APhysicalSphere::isDropped()
{
	// ���� 0�̹Ƿ� ���̰� ���� ���� ��ŭ �ִ��� ���� �Ѵ�.
	return GetActorLocation().Z < halfSphereHeight;
}

// Sets default values
APhysicalSphere::APhysicalSphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// ���ο� �ӵ�, ������ �ִ´�.
void APhysicalSphere::SetNewValue(float angle, float initVec, float posY)
{
	// Degree�� Rad�� �ٲ�.
	float rad = angle * pie / 180.0f;

	// �ӵ��� ����Ѵ�.
	initVecX = FMath::Cos(rad) * initVec;
	initVecY = FMath::Sin(rad) * initVec;

	initPosY = posY;

	ResetPosition();
}

// Called when the game starts or when spawned
void APhysicalSphere::BeginPlay()
{
	Super::BeginPlay();
	// �ʱ� ������ ����
	SetNewValue(60.0f, 1000.0f, 500.0f);
	ResetPosition();
}

// Called every frame
void APhysicalSphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Y �ӵ��� �߷°��ӵ��� �����ش�.
	vectorY += gravityAccelation * DeltaTime;
	// X, Y�� �ӵ���ŭ �����ش�.
	positionX += vectorX * DeltaTime;
	positionY += vectorY * DeltaTime;

	// ���� ��Ҵٸ� ��ġ �ʱ�ȭ
	if (isDropped()) ResetPosition();
	else RefreshPosition();
}

