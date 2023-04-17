// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/HealingItem.h"
#include "Characters/JoyWayBaseCharacter.h"

void UHealingItem::Use(AJoyWayBaseCharacter* JoyWayBaseCharacter)
{
	if (IsValid(JoyWayBaseCharacter))
	{
		JoyWayBaseCharacter->Heal(Health);
		JoyWayBaseCharacter->InventoryComponent->RemoveItem(this);
	}
}