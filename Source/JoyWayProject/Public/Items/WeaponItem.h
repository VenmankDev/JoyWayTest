// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/BaseItem.h"
#include "WeaponItem.generated.h"


class AJoyWayBaseWeapon;
/**
 * 
 */
UCLASS()
class JOYWAYPROJECT_API UWeaponItem : public UBaseItem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int CurrentAmmo = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<AJoyWayBaseWeapon> WeaponClass;

protected:
	virtual void Use(class AJoyWayBaseCharacter* JoyWayBaseCharacter);
};
