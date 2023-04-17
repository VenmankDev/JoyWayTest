// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/InventoryComponent.h"
#include "Items/BaseItem.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{

}



// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	
}




bool UInventoryComponent::AddItem(UBaseItem* Item)
{
	if (Items.Num() >= MaxCapacity || !IsValid(Item))
	{
		return false;
	}
	Items.Add(Item);
	OnInvetoryUpdated.Broadcast();
	return true;
}

bool UInventoryComponent::RemoveItem(UBaseItem* Item)
{
	if (IsValid(Item) && Items.Contains(Item))
	{
		Items.RemoveSingle(Item);
		OnInvetoryUpdated.Broadcast();
		return true;
	}
	return false;
}