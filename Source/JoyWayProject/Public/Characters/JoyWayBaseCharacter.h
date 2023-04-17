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

public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	AJoyWayBaseWeapon* JoyWayBaseWeapon;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UInventoryComponent* InventoryComponent;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UCameraComponent* CameraComponent;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UWidgetInteractionComponent* WidgetInteractionComponent;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	int HP;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	int MaxHP = 100;

	FOnCharacterHPChanged CharacterHPChanged;

	FOnWeaponAmmoChanged CharacterAmmoChanged;
	FDelegateHandle AmmoDelegateHandler;
public:
	AJoyWayBaseCharacter();
	virtual void Tick(float DeltaTime) override;

	virtual void ApplyDamage_Implementation(int Value) override;

	//Movement
	void MoveForward(float Value);
	void MoveRight(float Value);

	//Weapon
	void StartFire();
	void StopFire();
	void Reload();
	void EquipWeapon(AJoyWayBaseWeapon* NewWeapon);
	void OnAmmoChanged(int CurrentAmmo, int MaxAmmo);

	void Equip();

	void GetHP(int& OutHP, int& OutMaxHP);
	void GetAmmo(int& OutCurrentAmmo, int& OutMaxAmmo);
	void Heal(int AdditionalHP);
	void Die();

	void UseItem(class UBaseItem* Item);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	AActor* LastSelectedItem;
};
