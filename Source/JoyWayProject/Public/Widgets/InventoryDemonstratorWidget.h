// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryDemonstratorWidget.generated.h"

class UInventoryComponent;
/**
 * 
 */
UCLASS()
class JOYWAYPROJECT_API UInventoryDemonstratorWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly)
	UInventoryComponent* CurrentInventory;

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void UpdateInventory();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetInventory(UInventoryComponent* NewInventory);
	void SetInventory_Implementation(UInventoryComponent* NewInventory);
};
