// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/WeaponItem.h"
#include "Weapons/JoyWayBaseWeapon.h"
#include "Characters/JoyWayBaseCharacter.h"

void UWeaponItem::Use(AJoyWayBaseCharacter* JoyWayBaseCharacter)
{
	if (IsValid(JoyWayBaseCharacter))
	{
		AJoyWayBaseWeapon* TempWeapon = (AJoyWayBaseWeapon*)GetWorld()->SpawnActor(WeaponClass, &JoyWayBaseCharacter->GetTransform());
		JoyWayBaseCharacter->InventoryComponent->RemoveItem(this);
		TempWeapon->CurrentAmmo = CurrentAmmo;
		JoyWayBaseCharacter->EquipWeapon(TempWeapon);
	}
}