// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDs/JoyWayBaseHUD.h"
#include "Widgets/UserMainWidget.h"

void AJoyWayBaseHUD::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = false;
	MainWiget = Cast<UUserMainWidget>(CreateWidget(GetOwningPlayerController(), MainWidgetClass));
	MainWiget->AddToPlayerScreen();
}

void AJoyWayBaseHUD::UpdateHP(int CurrentHP, int MaxHP)
{
	if (IsValid(MainWiget))
	{
		MainWiget->UpdateHP(CurrentHP, MaxHP);
	}
}

void AJoyWayBaseHUD::UpdateAmmo(int CurrentAmmo, int MaxAmmo)
{
	if (IsValid(MainWiget))
	{
		MainWiget->UpdateAmmo(CurrentAmmo, MaxAmmo);
	}
}