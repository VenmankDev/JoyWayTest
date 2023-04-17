// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/JoyWayBaseWeapon.h"
#include "Rifle.generated.h"

/**
 * 
 */
UCLASS()
class JOYWAYPROJECT_API ARifle : public AJoyWayBaseWeapon
{
	GENERATED_BODY()

protected:
	virtual void OnReloadTimer();
	virtual void Fire();
};
