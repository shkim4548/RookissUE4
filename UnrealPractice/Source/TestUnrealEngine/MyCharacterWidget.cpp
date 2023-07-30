// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterWidget.h"
#include "MyStatComponent.h"
#include "Components/ProgressBar.h"

void UMyCharacterWidget::BindHp(class UMyStatComponent* StatComp)
{
	//PB_HpBar = Cast<UProgressBar>(GameWidgetFromName(TEXT("PB_HpBar")));	// UI�� �������� ���ε�
	CurrentStatComp = StatComp;
	StatComp->OnHpChanged.AddUObject(this, &UMyCharacterWidget::UpdateHp);	// ���������� ���ǵ� �Լ��� ������ �� AdduObject�� ����Ѵ�.
}

//���⼭ �˾Ƽ� ������ �ȴ�.
void UMyCharacterWidget::UpdateHp()
{
	if(CurrentStatComp.IsValid())
		PB_HpBar->SetPercent(CurrentStatComp->GetHpRatio());
}
