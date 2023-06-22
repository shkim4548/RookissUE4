// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterWidget.h"
#include "MyStatComponent.h"
#include "Components/ProgressBar.h"

void UMyCharacterWidget::BindHp(class UMyStatComponent* StatComp)
{
	//PB_HpBar = Cast<UProgressBar>(GameWidgetFromName(TEXT("PB_HpBar")));	// UI를 수동으로 바인딩
	CurrentStatComp = StatComp;
	StatComp->OnHpChanged.AddUObject(this, &UMyCharacterWidget::UpdateHp);	// 내부적으로 정의된 함수를 연동할 때 AdduObject를 사용한다.
}

//여기서 알아서 갱신이 된다.
void UMyCharacterWidget::UpdateHp()
{
	if(CurrentStatComp.IsValid())
		PB_HpBar->SetPercent(CurrentStatComp->GetHpRatio());
}
