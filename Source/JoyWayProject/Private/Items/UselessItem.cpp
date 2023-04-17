// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/UselessItem.h"
#include "Characters/JoyWayBaseCharacter.h"

void UUselessItem::Use(AJoyWayBaseCharacter* JoyWayBaseCharacter)
{
	if (IsValid(JoyWayBaseCharacter))
	{
		JoyWayBaseCharacter->InventoryComponent->RemoveItem(this);
	}
}