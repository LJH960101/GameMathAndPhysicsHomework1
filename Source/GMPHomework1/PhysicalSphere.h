// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PhysicalSphere.generated.h"

UCLASS()
class GMPHOMEWORK1_API APhysicalSphere : public AActor
{
	GENERATED_BODY()
	const float pie = 3.141592f; // ����
	const float gravityAccelation = -980.665f; // �߷� ���ӵ�
	const float initPosX = -400.0; // �ʱ� X ��ġ
	const float halfSphereHeight = 50.0f; // ��ü�� ������ ����
	float vectorX, vectorY; // �ӵ�
	float positionX, positionY; // ��ġ
	float initPosY, initVecX, initVecY; // �ʱ� ��ġ �� �ӵ�
	// Position�� �����Ѵ�.
	void RefreshPosition();
	// Position�� �ǵ�����.
	void ResetPosition();
	// ���� ���°�?
	bool isDropped();
	
public:	
	// Sets default values for this actor's properties
	APhysicalSphere();
	// ���ο� �ӵ�, ������ �ִ´�.
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
