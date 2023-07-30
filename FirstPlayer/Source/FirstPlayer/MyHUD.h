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
	class UTextBlock* AmmoText;	// �� �ؽ�Ʈ�� �ν��ؼ� �ڵ����� UI�� Ŭ������ ���ε� ���ش�.

	// int32 AmmoCount;	// �ΰ��� �����Ϳ� UI�� ���� ���� ���ÿ�
};
