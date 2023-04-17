// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/JoyWayBaseWeapon.h"
#include "Shotgun.generated.h"

/**
 * 
 */
UCLASS()
class JOYWAYPROJECT_API AShotgun : public AJoyWayBaseWeapon
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ShotgunPelletCount = 0;

protected:
	virtual void StartFire();
	virtual void OnReloadTimer();
	virtual void Fire();
};
