// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"	//�̰ſ� ���� ��� �ʿ��� ����� ����Ǿ� �ִ�. �ٵ� �ʹ� ������ �翬�� ��������.
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class TESTUNREALPROJECT_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)	//�ν����� �� ���� ���� ���÷���
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category=BattleStat)
	int32 Hp;

	UPROPERTY(EditAnywhere, Category=BattleStat)
	int32 Mp;

	UPROPERTY(EditAnyWhere, Category = BattleStat)
	float RotateSpeed = 30.f;
};
