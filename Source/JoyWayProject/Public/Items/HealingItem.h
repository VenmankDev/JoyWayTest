// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/BaseItem.h"
#include "HealingItem.generated.h"

/**
 * 
 */
UCLASS()
class JOYWAYPROJECT_API UHealingItem : public UBaseItem
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly)
	int Health = 0;

protected:
	virtual void Use(class AJoyWayBaseCharacter* JoyWayBaseCharacter);
};
