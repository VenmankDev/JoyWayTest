// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/PickableItem.h"
#include "JoyWayBaseWeapon.generated.h"


class UWeaponItem;

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnWeaponAmmoChanged, int, int)

UCLASS(Blueprintable)
class JOYWAYPROJECT_API AJoyWayBaseWeapon : public AActor, public IPickableItem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Instanced)
	UWeaponItem* WeaponItem;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* RootPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxAmmo = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrentAmmo = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ReloadDelay = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float FireDelay = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Damage = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName MuzzleSocketName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HalfAngleSpreadInRadians = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ShootDistance = 0.f;

	FOnWeaponAmmoChanged WeaponAmmoChanged;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UMaterialInterface* MaterialToSelect;
	UPROPERTY(BlueprintReadWrite)
	UMaterialInterface* MaterialToSave;

	virtual UBaseItem* Pick_Implementation() override;
	virtual void DestroyItem_Implementation() override;

protected:
	bool IsFiring = true;
	bool IsReadyToFire = true;
	bool IsReloading = false;

	FTimerHandle FireTimer;
	FTimerHandle ReloadTimer;

public:	
	AJoyWayBaseWeapon();

	virtual void Tick(float DeltaTime) override;

	virtual void StartFire();
	virtual void StopFire();

	virtual void StartReloading();
	void GetAmmo(int& OutCurrentAmmo, int& OutMaxAmmo);

protected:
	virtual void BeginPlay() override;
	virtual void StartFireTimer();
	virtual void Fire();
	virtual void OnFireTimer();

	virtual void OnReloadTimer();
	void SingleShot();
	
};
