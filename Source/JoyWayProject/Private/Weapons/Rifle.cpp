// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/Rifle.h"

void ARifle::OnReloadTimer()
{
	IsReloading = false;
	CurrentAmmo = MaxAmmo;
	WeaponAmmoChanged.Broadcast(CurrentAmmo, MaxAmmo);
	if (IsFiring)
	{
		StartFireTimer();
	}

}

void ARifle::Fire()
{
	Super::Fire();
	SingleShot();
}
