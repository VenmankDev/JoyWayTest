// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/InventoryComponent.h"
#include "BaseItem.generated.h"


class UInventoryComponent;
class AJoyWayBaseCharacter;
/**
 * 
 */
UCLASS(Abstract, BlueprintType, Blueprintable, DefaultToInstanced, EditInlineNew)
class JOYWAYPROJECT_API UBaseItem : public UObject
{
	GENERATED_BODY()

public: 
	UBaseItem();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText ItemDisplayName;

	UFUNCTION(BlueprintCallable)
	virtual void Use(AJoyWayBaseCharacter* JoyWayBaseCharacter);
};
