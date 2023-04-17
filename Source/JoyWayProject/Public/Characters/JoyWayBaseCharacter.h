// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/JoyWayDamageble.h"
#include "Weapons/JoyWayBaseWeapon.h"
#include "JoyWayBaseCharacter.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnCharacterDie)

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnCharacterHPChanged, int, int)

class AJoyWayBaseWeapon;
class UInventoryComponent;
class UCameraComponent;
class IPickableItem;
class UWidgetInteractionComponent;

UCLASS(Blueprintable, BlueprintType)
class JOYWAYPROJECT_API AJoyWayBaseCharacter : public ACharacter, public IJoyWayDamageble
{
	GENERATED_BODY()
public:
	FOnCharacterDie CharacterDieDelegate;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UInventoryComponent* InventoryComponent;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UCameraComponent* CameraComponent;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UWidgetInteractionComponent* WidgetInteractionComponent;

	FOnCharacterHPChanged CharacterHPChanged;
	FOnWeaponAmmoChanged CharacterAmmoChanged;

protected:
	UPROPERTY(BlueprintReadOnly)
	AJoyWayBaseWeapon* JoyWayBaseWeapon;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	int HP;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	int MaxHP = 100;
	AActor* LastSelectedItem;

private:
	FDelegateHandle AmmoDelegateHandler;

public:
	AJoyWayBaseCharacter();

	void StartFire();
	void StopFire();
	void Reload();
	void Equip();
	void EquipWeapon(AJoyWayBaseWeapon* NewWeapon);

	void MoveForward(float Value);
	void MoveRight(float Value);


	void GetHP(int& OutHP, int& OutMaxHP);
	void GetAmmo(int& OutCurrentAmmo, int& OutMaxAmmo);
	void Heal(int AdditionalHP);

	void UseItem(class UBaseItem* Item);

	virtual void Tick(float DeltaTime) override;
protected:
	virtual void ApplyDamage_Implementation(int Value) override;

	void OnAmmoChanged(int CurrentAmmo, int MaxAmmo);

	void Die();

	virtual void BeginPlay() override;
};
