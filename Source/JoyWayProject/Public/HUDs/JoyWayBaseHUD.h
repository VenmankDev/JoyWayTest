// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "JoyWayBaseHUD.generated.h"

class UUserMainWidget;

UCLASS()
class JOYWAYPROJECT_API AJoyWayBaseHUD : public AHUD
{
	GENERATED_BODY()

public:
	void UpdateHP(int CurrentHP, int MaxHP);
	void UpdateAmmo(int CurrentAmmo, int MaxAmmo);

protected:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserMainWidget> MainWidgetClass;

protected:
	void BeginPlay() override;
	UUserMainWidget* MainWiget;
};
