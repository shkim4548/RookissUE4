// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPLAYER_API UMyHUD : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* AmmoText;	// 이 텍스트를 인식해서 자동으로 UI와 클래스를 바인딩 해준다.

	// int32 AmmoCount;	// 인게임 데이터와 UI를 같이 두지 마시오
};
