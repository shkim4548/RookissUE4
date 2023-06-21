// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

UMyGameInstance::UMyGameInstance()
{
	//경로는 데이터 시트에셋의 경로를 가져온다.
	static ConstructorHelpers::FObjectFinder<UDataTable> DATA(TEXT("DataTable'/Game/Data/StatTable.StatTable'"));
	if (DATA.Succeeded())
		MyStats = DATA.Object;
}

void UMyGameInstance::Init()
{
	Super::Init();
	UE_LOG(LogTemp, Warning, TEXT("MyGameInstance %d"), GetStatData(1)->Attack);
}

FMyCharacterData* UMyGameInstance::GetStatData(int32 Level)
{
	//데이터 테이블에서 원하는 행을 찾는다.
	return MyStats->FindRow<FMyCharacterData>(*FString::FromInt(Level), TEXT(""));
}