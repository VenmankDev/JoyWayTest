// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/JoyWayBaseWeapon.h"
#include "DrawDebugHelpers.h"
#include "Items/WeaponItem.h"
#include "Interfaces/JoyWayDamageble.h"

// Sets default values
AJoyWayBaseWeapon::AJoyWayBaseWeapon()
{
	PrimaryActorTick.bCanEverTick = false;
	RootPoint = CreateDefaultSubobject<USceneComponent>(TEXT("RootPoint"));
	SetRootComponent(RootPoint);

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(RootPoint);
}

void AJoyWayBaseWeapon::StartFire()
{
	IsFiring = true;
	if (!IsReloading)
	{
		StartFireTimer();
	}
}

void AJoyWayBaseWeapon::StartFireTimer()
{
	if (!IsReadyToFire)
	{
		return;
	}
	

	if (CurrentAmmo > 0)
	{
		Fire();
		IsReadyToFire = false;
		GetWorld()->GetTimerManager().SetTimer(FireTimer, this, &AJoyWayBaseWeapon::OnFireTimer, FireDelay);
	}
	else
	{
		IsFiring = false;
	}
}

void AJoyWayBaseWeapon::Fire()
{
	CurrentAmmo--;
	WeaponAmmoChanged.Broadcast(CurrentAmmo, MaxAmmo);
}

void AJoyWayBaseWeapon::GetAmmo(int& OutCurrentAmmo, int& OutMaxAmmo)
{
	OutCurrentAmmo = CurrentAmmo;
	OutMaxAmmo = MaxAmmo;
}

void AJoyWayBaseWeapon::StopFire()
{
	IsFiring = false;
}

void AJoyWayBaseWeapon::OnFireTimer()
{
	IsReadyToFire = true;
	if (IsFiring)
	{
		StartFireTimer();
	}
}

void AJoyWayBaseWeapon::StartReloading()
{
	if (IsReloading || CurrentAmmo == MaxAmmo || IsFiring)
	{
		return;
	}
	IsReloading = true;
	GetWorld()->GetTimerManager().SetTimer(ReloadTimer, this, &AJoyWayBaseWeapon::OnReloadTimer, ReloadDelay);
}

void AJoyWayBaseWeapon::OnReloadTimer()
{
	
}

void AJoyWayBaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	CurrentAmmo = MaxAmmo;
}

void AJoyWayBaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AJoyWayBaseWeapon::SingleShot()
{
	FMath::VRandCone(GetActorForwardVector(), HalfAngleSpreadInRadians);
	FHitResult HitResult;
	GetWorld()->LineTraceSingleByObjectType(HitResult, WeaponMesh->GetSocketLocation(MuzzleSocketName), WeaponMesh->GetSocketLocation(MuzzleSocketName) +
		FMath::VRandCone(GetActorForwardVector(), HalfAngleSpreadInRadians) * ShootDistance, FCollisionObjectQueryParams());

	IJoyWayDamageble* DamagebleActor = Cast<IJoyWayDamageble>(HitResult.GetActor());

	DrawDebugLine(GetWorld(), WeaponMesh->GetSocketLocation(MuzzleSocketName), WeaponMesh->GetSocketLocation(MuzzleSocketName) +
		FMath::VRandCone(GetActorForwardVector(), HalfAngleSpreadInRadians) * ShootDistance, FColor::Cyan, false, 0.2f);
	if (HitResult.bBlockingHit)
	{
		DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 5.f, 32, FColor::Red,false, 0.5f);
	}

	if (HitResult.bBlockingHit && HitResult.Actor->GetClass()->ImplementsInterface(UJoyWayDamageble::StaticClass()))
	{
		IJoyWayDamageble::Execute_ApplyDamage(HitResult.Actor.Get(), Damage);
	}
}


UBaseItem* AJoyWayBaseWeapon::Pick_Implementation()
{
	return WeaponItem;
}

void AJoyWayBaseWeapon::DestroyItem_Implementation()
{
	Destroy();
}


