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
	// �������̵� �Լ��� �θ� �Լ��� �ʿ��� �۾��� ���� �� ������ �ڷḦ �ѱ��.
	bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	auto CurrentPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (CurrentPawn == nullptr)
		return false;
	
	// �ᱹ ���ݹ����� �÷��̾ �ִ��Ķ�� ������ �������� ���̴�
	auto Target = Cast<AMyCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName(TEXT("Target"))));
	if (Target == nullptr)
		return false;

	// ���� ���� Ÿ���� �Ÿ��� �����Ѵ�. 200 ���� �ȿ� �������� üũ�Ѵ�.
	return bResult = Target->GetDistanceTo(CurrentPawn) <= 200.f;
}
