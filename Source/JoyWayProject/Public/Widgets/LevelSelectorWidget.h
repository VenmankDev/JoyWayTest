// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LevelSelectorWidget.generated.h"

/**
 * 
 */
UCLASS()
class JOYWAYPROJECT_API ULevelSelectorWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadwrite, meta = (AllowedClasses = "World"))
	TArray<FSoftObjectPath> MapsToOpen;
	UFUNCTION(BlueprintCallable)
	void UpdateMaps();
};
