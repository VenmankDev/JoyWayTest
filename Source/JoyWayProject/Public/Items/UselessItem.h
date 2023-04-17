// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/BaseItem.h"
#include "UselessItem.generated.h"

/**
 * 
 */
UCLASS()
class JOYWAYPROJECT_API UUselessItem : public UBaseItem
{
	GENERATED_BODY()

protected:
	virtual void Use(class AJoyWayBaseCharacter* JoyWayBaseCharacter);
};
