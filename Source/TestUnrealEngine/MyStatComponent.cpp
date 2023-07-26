// Fill out your copyright notice in the Description page of Project Settings.


#include "MyStatComponent.h"
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UMyStatComponent::UMyStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;	// 매틱마다 작동하지 못하도록 한다.

	// ...
	bWantsInitializeComponent = true;	//컴포넌트 초기화 켜기

	Level = 1;
}


// Called when the game starts
void UMyStatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UMyStatComponent::InitializeComponent()
{
	Super::InitializeComponent();

	SetLevel(Level);
}

void UMyStatComponent::SetLevel(int32 NewLevel)
{
	//위의 gamestatic 헤더를 가져와야하는 이유, 레벨업시마다 데이터 매니저에서 찾아준다.
	auto MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (MyGameInstance)
	{
		auto StatData = MyGameInstance->GetStatData(NewLevel);
		if (StatData)
		{
			NewLevel = StatData->Level;
			SetHp(StatData->MaxHp);
			MaxHp = StatData->MaxHp;
			Attack = StatData->Attack;
		}
	}
}

void UMyStatComponent::SetHp(int32 NewHp)
{
	Hp = NewHp;
	if (Hp < 0)
		Hp = 0;

	OnHpChanged.Broadcast();	//전형적인 Listener Pattern, 델리게이트를 이용함
}

//데미지를 받았을 때 처리될 내용, 나중에 상대방에 대한 정보를 엄청나게 많이 받아야할 것
void UMyStatComponent::OnAttacked(float DamageAmount)
{
	int32 NewHp = Hp - DamageAmount;
	SetHp(NewHp);
	//UE_LOG(LogTemp, Warning, TEXT("OnAttacked %d"), Hp);
}

