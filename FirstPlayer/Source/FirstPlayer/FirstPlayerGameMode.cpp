// Copyright Epic Games, Inc. All Rights Reserved.

#include "FirstPlayerGameMode.h"
#include "FirstPlayerHUD.h"
#include "FirstPlayerCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "MyHUD.h"


AFirstPlayerGameMode::AFirstPlayerGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFirstPlayerHUD::StaticClass();

	// 게임이 실행될 때, UI를 묻지도 따지지도 말고 띄워라
	// 블루 프린트 클래스이므로 마지막에 _C를 붙여준다.
	static ConstructorHelpers::FClassFinder<UMyHUD> UI_HUD(TEXT("WidgetBlueprint'/Game/WBP_HUD.WBP_HUD_C'"));	
	if (UI_HUD.Succeeded())
	{
		HUD_Class = UI_HUD.Class;
		CurrentWidget = CreateWidget(GetWorld(), HUD_Class);
		if (CurrentWidget)
		{
			CurrentWidget->AddToViewport();	// 위젯을 실제로 화면에 띄워라, 인자를 주면 순서대로 띄울 수도 있다
			//CurrentWidget->RemoveFromViewport();	// 지우기도 가능
		}
	}
}
