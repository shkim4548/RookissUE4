// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

AMyAIController::AMyAIController()
{

}

void AMyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AMyAIController::RandomMove, 3.f, true);	// 주기적으로 실행하길 원하는 함수
}

void AMyAIController::OnUnPossess()
{
	Super::OnUnPossess();
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
}

void AMyAIController::RandomMove()
{
	auto CurrentPawn = GetPawn();
	
	// 언리얼 네브 매쉬의 사용
	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
	if (NavSystem)
		return;

	FNavLocation RandomLocation;
	if (NavSystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 500.f, RandomLocation))
	{
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, RandomLocation);
	}
}
