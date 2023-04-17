// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/LevelSelectorWidget.h"
#include "DeveloperSettings/EnabledLevelsDeveloperSettings.h"


void ULevelSelectorWidget::UpdateMaps()
{
	for (FSoftObjectPath Path : GetDefault<UEnabledLevelsDeveloperSettings>()->MapsToOpen)
	{
		MapsToOpen.Add(Path);
	}
}