// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DamageDemonstratorWidget.generated.h"

/**
 * 
 */
UCLASS()
class JOYWAYPROJECT_API UDamageDemonstratorWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void UpdateDamage(float NewDamage);
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void ShowDamage(float Value);

private:
	void OnClearTimer();

public:
	float CurrentSumDamage = 0.f;

	FTimerHandle ClearTimer;
};
