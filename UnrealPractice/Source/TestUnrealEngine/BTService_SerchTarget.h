// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_SerchTarget.generated.h"

/**
 * 
 */
UCLASS()
class TESTUNREALENGINE_API UBTService_SerchTarget : public UBTService
{
	GENERATED_BODY()
public:
	UBTService_SerchTarget();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
