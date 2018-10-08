// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PhysicalSphere.generated.h"

UCLASS()
class GMPHOMEWORK1_API APhysicalSphere : public AActor
{
	GENERATED_BODY()
	const float pie = 3.141592f; // 파이
	const float gravityAccelation = -980.665f; // 중력 가속도
	const float initPosX = -400.0; // 초기 X 위치
	const float halfSphereHeight = 50.0f; // 구체의 높이의 절반
	float vectorX, vectorY; // 속도
	float positionX, positionY; // 위치
	float initPosY, initVecX, initVecY; // 초기 위치 및 속도
	// Position을 갱신한다.
	void RefreshPosition();
	// Position을 되돌린다.
	void ResetPosition();
	// 떨어 졌는가?
	bool isDropped();
	
public:	
	// Sets default values for this actor's properties
	APhysicalSphere();
	// 새로운 속도, 각도를 넣는다.
	UFUNCTION(BlueprintCallable, Category = MyMath)
	void SetNewValue(float angle, float initVec, float posY);

	UPROPERTY(EditAnywhere, Category = MyMath)
		AActor* platform;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
