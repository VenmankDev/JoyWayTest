// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/Shotgun.h"

void AShotgun::OnReloadTimer()
{
	CurrentAmmo++;
	WeaponAmmoChanged.Broadcast(CurrentAmmo, MaxAmmo);
	if (IsFiring)
	{
		StartFireTimer();
		IsReloading = false;
		return;
	}

	if (CurrentAmmo != MaxAmmo)
	{
		GetWorld()->GetTimerManager().SetTimer(ReloadTimer, this, &AShotgun::OnReloadTimer, ReloadDelay);
	}
	else
	{
		IsReloading = false;
	}
}

void AShotgun::Fire()
{
	Super::Fire();
	for (int i = 0; i < ShotgunPelletCount; i++)
	{
		SingleShot();
	}
}

void AShotgun::StartFire()
{
	IsFiring = true;
	if (CurrentAmmo)
	{
		if (GetWorld()->GetTimerManager().IsTimerActive(ReloadTimer))
		{
			IsReloading = false;
			GetWorld()->GetTimerManager().ClearTimer(ReloadTimer);
		}
		StartFireTimer();
	}
}