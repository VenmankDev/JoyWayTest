// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SingleLevelButton.generated.h"

/**
 * 
 */
UCLASS()
class JOYWAYPROJECT_API USingleLevelButton : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite,  meta = (ExposeOnSpawn))
	FSoftObjectPath MapToOpen;

public:
	UFUNCTION(BlueprintCallable)
	void LoadNewLevel();
};
