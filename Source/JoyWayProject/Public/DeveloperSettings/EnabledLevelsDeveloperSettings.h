// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "EnabledLevelsDeveloperSettings.generated.h"

/**
 * 
 */
UCLASS(config = Game, defaultconfig)
class JOYWAYPROJECT_API UEnabledLevelsDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()
public:
	UPROPERTY(config, EditAnywhere, meta = (AllowedClasses = "World"))
	TArray<FSoftObjectPath> MapsToOpen;
};
