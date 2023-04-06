// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"	//이거에 거의 모든 필요한 헤더가 선언되어 있다. 근데 너무 많으면 당연히 느려진다.
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
	UPROPERTY(VisibleAnywhere)	//인스펙터 상에 띄우기 위한 리플렉션
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category=BattleStat)
	int32 Hp;

	UPROPERTY(EditAnywhere, Category=BattleStat)
	int32 Mp;

	UPROPERTY(EditAnyWhere, Category = BattleStat)
	float RotateSpeed = 30.f;
};
