// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_SerchTarget.h"
#include "MyAIController.h"
#include "MyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"	// 이거 레이드로잉 등을 할때 사용

UBTService_SerchTarget::UBTService_SerchTarget()
{
	NodeName = TEXT("SearchTarget");	// BT의 노드 설정
	Interval = 1.0f;	// 시간 간격 설정
}

void UBTService_SerchTarget::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	// 타겟을 코드 상에서 설정한다.
	auto CurrentPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (CurrentPawn == nullptr)
		return;

	UWorld* World = CurrentPawn->GetWorld();	// 씬 전체의 정보를 가져온다
	FVector Center = CurrentPawn->GetActorLocation();	// 내 위치를 가져온다.
	float SearchRadius = 500.f;

	if (World == nullptr)
		return;

	// 유니티의 overlap Sphere를 사용하는 과정, 인자가 굉장히 많아서 귀찮다.
	TArray<FOverlapResult> OverlapResults;
	FCollisionQueryParams QueryParams(NAME_None, false, CurrentPawn);
	bool bResult = World->OverlapMultiByChannel(
		OverlapResults,
		Center,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,	// 우리가 추가한 사항이 2채널이므로 2를 사용
		FCollisionShape::MakeSphere(SearchRadius),
		QueryParams
	);

	// 뭔가를 찾은 경우
	if (bResult)
	{
		for (auto& OverlapResult : OverlapResults)
		{
			AMyCharacter* MyCharacter = Cast<AMyCharacter>(OverlapResult.GetActor());
			// 지금은 몬스터랑 플레이어의 컨트롤러가 갖기 때문에, 플레이어 여부를 한번 더 체크한다.
			if (MyCharacter && MyCharacter->GetController()->IsPlayerController()) 
			{
				OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Target")), MyCharacter);
				DrawDebugSphere(World, Center, SearchRadius, 16, FColor::Green, false, 0.2f);
				return;
			}
		}
		DrawDebugSphere(World, Center, SearchRadius, 16, FColor::Red, false, 0.2f);
	}
	// 뭔가를 찾지 못한경우
	else
	{
		// AI와 관련된 모든 정보를 가져와서 Target을 nullptr로 밀어버린다.
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Target")), nullptr);
		DrawDebugSphere(World, Center, SearchRadius, 16, FColor::Red, false, 0.2f);
	}
}