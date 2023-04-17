// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/SingleLevelButton.h"
#include "GameModes/JoyWayBaseGameMode.h"

void USingleLevelButton::LoadNewLevel()
{
	AJoyWayBaseGameMode* TempGameMode = Cast<AJoyWayBaseGameMode>(GetWorld()->GetAuthGameMode());
	if (TempGameMode)
	{
		TempGameMode->LoadNewMap(MapToOpen);
	}
}