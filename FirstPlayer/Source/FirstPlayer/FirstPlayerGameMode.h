// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FirstPlayerGameMode.generated.h"

UCLASS(minimalapi)
class AFirstPlayerGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AFirstPlayerGameMode();	// 크로스 헤어를 그려주는 UI를 실행시킴

	// 사용할 UI들을 가지고 있도록 한다.
public:
	UPROPERTY()
	TSubclassOf<UUserWidget> HUD_Class;	// 어떤 클래스를 띄우고 있냐?

	UPROPERTY()
	UUserWidget* CurrentWidget;	// 띄우고 있는 클래스의 주소를 가져온다.
};



