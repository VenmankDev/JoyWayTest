// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/InventoryDemonstratorWidget.h"
#include "Components/InventoryComponent.h"

void UInventoryDemonstratorWidget::SetInventory_Implementation(UInventoryComponent* NewInventory)
{
	CurrentInventory = NewInventory;
	CurrentInventory->OnInvetoryUpdated.AddUObject(this, &UInventoryDemonstratorWidget::UpdateInventory);
	UpdateInventory();
}