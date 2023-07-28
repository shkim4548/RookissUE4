// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecorator_CanAttack.h"
#include "MyAIController.h"
#include "MyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTDecorator_CanAttack::UBTDecorator_CanAttack()
{
	NodeName = TEXT("CanAttack");
}

bool UBTDecorator_CanAttack::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	// 오버라이딩 함수는 부모 함수에 필요한 작업이 있을 수 있으니 자료를 넘긴다.
	bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	auto CurrentPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (CurrentPawn == nullptr)
		return false;
	
	// 결국 공격범위에 플레이어가 있느냐라는 정보를 꺼내려는 것이니
	auto Target = Cast<AMyCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName(TEXT("Target"))));
	if (Target == nullptr)
		return false;

	// 현재 폰과 타겟의 거리를 측정한다. 200 범위 안에 들어오는지 체크한다.
	return bResult = Target->GetDistanceTo(CurrentPawn) <= 200.f;
}
