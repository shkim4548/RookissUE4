// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyCharacter.h"

AMyGameModeBase::AMyGameModeBase()
{
	//DefaultPawnClass = AMyCharacter::StaticClass();	//생성자에서 클래스를 스태틱 클래스로 상속받아온다. 언리얼 함수
	static ConstructorHelpers::FClassFinder<ACharacter> BP_Char(TEXT("Blueprint'/Game/BluePrints/BP_MyCharacter.BP_MyCharacter_C'"));

	if (BP_Char.Succeeded())
	{
		DefaultPawnClass = BP_Char.Class;
	}
}