// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UserMainWidget.generated.h"

/**
 * 
 */
UCLASS()
class JOYWAYPROJECT_API UUserMainWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void UpdateHP(int CurrentHP, int MaxHP);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void UpdateAmmo(int CurrentAmmo, int MaxAmmo); 
};
