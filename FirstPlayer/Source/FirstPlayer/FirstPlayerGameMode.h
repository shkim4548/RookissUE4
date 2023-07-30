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
	AFirstPlayerGameMode();	// ũ�ν� �� �׷��ִ� UI�� �����Ŵ

	// ����� UI���� ������ �ֵ��� �Ѵ�.
public:
	UPROPERTY()
	TSubclassOf<UUserWidget> HUD_Class;	// � Ŭ������ ���� �ֳ�?

	UPROPERTY()
	UUserWidget* CurrentWidget;	// ���� �ִ� Ŭ������ �ּҸ� �����´�.
};



