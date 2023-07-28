// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_SerchTarget.h"
#include "MyAIController.h"
#include "MyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"	// �̰� ���̵���� ���� �Ҷ� ���

UBTService_SerchTarget::UBTService_SerchTarget()
{
	NodeName = TEXT("SearchTarget");	// BT�� ��� ����
	Interval = 1.0f;	// �ð� ���� ����
}

void UBTService_SerchTarget::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	// Ÿ���� �ڵ� �󿡼� �����Ѵ�.
	auto CurrentPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (CurrentPawn == nullptr)
		return;

	UWorld* World = CurrentPawn->GetWorld();	// �� ��ü�� ������ �����´�
	FVector Center = CurrentPawn->GetActorLocation();	// �� ��ġ�� �����´�.
	float SearchRadius = 500.f;

	if (World == nullptr)
		return;

	// ����Ƽ�� overlap Sphere�� ����ϴ� ����, ���ڰ� ������ ���Ƽ� ������.
	TArray<FOverlapResult> OverlapResults;
	FCollisionQueryParams QueryParams(NAME_None, false, CurrentPawn);
	bool bResult = World->OverlapMultiByChannel(
		OverlapResults,
		Center,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,	// �츮�� �߰��� ������ 2ä���̹Ƿ� 2�� ���
		FCollisionShape::MakeSphere(SearchRadius),
		QueryParams
	);

	// ������ ã�� ���
	if (bResult)
	{
		for (auto& OverlapResult : OverlapResults)
		{
			AMyCharacter* MyCharacter = Cast<AMyCharacter>(OverlapResult.GetActor());
			// ������ ���Ͷ� �÷��̾��� ��Ʈ�ѷ��� ���� ������, �÷��̾� ���θ� �ѹ� �� üũ�Ѵ�.
			if (MyCharacter && MyCharacter->GetController()->IsPlayerController()) 
			{
				OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Target")), MyCharacter);
				DrawDebugSphere(World, Center, SearchRadius, 16, FColor::Green, false, 0.2f);
				return;
			}
		}
		DrawDebugSphere(World, Center, SearchRadius, 16, FColor::Red, false, 0.2f);
	}
	// ������ ã�� ���Ѱ��
	else
	{
		// AI�� ���õ� ��� ������ �����ͼ� Target�� nullptr�� �о������.
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Target")), nullptr);
		DrawDebugSphere(World, Center, SearchRadius, 16, FColor::Red, false, 0.2f);
	}
}