// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Controller.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class TESTUNREALENGINE_API AMyAIController : public AController
{
	GENERATED_BODY()
public:
	AMyAIController();

	virtual void OnPossess(APawn* InPawn) override;	
	virtual void OnUnPossess() override;

private:
	void RandomMove();
	
private:
	FTimerHandle TimerHandle;
};
