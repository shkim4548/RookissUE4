// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyCharacter.h"

AMyGameModeBase::AMyGameModeBase()
{
	DefaultPawnClass = AMyCharacter::StaticClass();	//�����ڿ��� Ŭ������ ����ƽ Ŭ������ ��ӹ޾ƿ´�. �𸮾� �Լ�
}