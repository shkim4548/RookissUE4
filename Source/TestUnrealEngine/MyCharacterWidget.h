// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyCharacterWidget.generated.h"

/**
 * 
 */
UCLASS()
class TESTUNREALENGINE_API UMyCharacterWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void BindHp(class UMyStatComponent* StatComp);

	void UpdateHp();

private:
	TWeakObjectPtr<class UMyStatComponent> CurrentStatComp;	// weakptr로 선언
	//class UMyStatComponent* CurrentStatComp;

	UPROPERTY(meta = (bindWidget))
	class UProgressBar* PB_HpBar;	// meta = bindwidget 옵션으로 블루프린트 UI로 바로 이어준다.
};
