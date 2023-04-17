// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "JoyWayDamageble.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UJoyWayDamageble : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class JOYWAYPROJECT_API IJoyWayDamageble
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void ApplyDamage(int Value);

public:
};
