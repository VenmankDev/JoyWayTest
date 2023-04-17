// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/JoyWayBaseCharacter.h"
#include "Components/InventoryComponent.h"
#include "Interfaces/PickableItem.h"
#include "Camera/CameraComponent.h"
#include "DrawDebugHelpers.h"
#include "Items/BaseItem.h"
#include "Components/WidgetInteractionComponent.h"
#include "Items/WeaponItem.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AJoyWayBaseCharacter::AJoyWayBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationPitch = true;
	JoyWayBaseWeapon = nullptr;
	bUseControllerRotationYaw = true;
	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("Inventory"));
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	WidgetInteractionComponent = CreateDefaultSubobject<UWidgetInteractionComponent>(TEXT("WidgetInteractionComponent"));
	CameraComponent->SetupAttachment(GetMesh());
	WidgetInteractionComponent->SetupAttachment(CameraComponent);
}

// Called when the game starts or when spawned
void AJoyWayBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	HP = MaxHP; 
	int OutCurrentAmmo; 
	int OutMaxAmmo;
	GetAmmo(OutCurrentAmmo, OutMaxAmmo);
	CharacterAmmoChanged.Broadcast(OutCurrentAmmo, OutMaxAmmo);
	CharacterHPChanged.Broadcast(HP, MaxHP);

}

// Called every frame
void AJoyWayBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult HitResult;

	FCollisionQueryParams Params = FCollisionQueryParams();
	Params.AddIgnoredActor(this);
	if (JoyWayBaseWeapon)
	{
		Params.AddIgnoredActor(JoyWayBaseWeapon);
	}

	GetWorld()->LineTraceSingleByChannel(HitResult, CameraComponent->GetComponentLocation(), CameraComponent->GetComponentLocation() +
		CameraComponent->GetForwardVector() * 500, ECC_WorldStatic, Params);

	if (!HitResult.bBlockingHit || !HitResult.Actor->GetClass()->ImplementsInterface(UPickableItem::StaticClass()))
	{
		if (LastSelectedItem)
		{
			IPickableItem::Execute_Unselect(LastSelectedItem);
		}
		LastSelectedItem = nullptr;
		return;
	}
	if (HitResult.Actor.Get() != LastSelectedItem)
	{
		IPickableItem::Execute_Select(HitResult.Actor.Get());
		if (LastSelectedItem)
		{
			IPickableItem::Execute_Unselect(LastSelectedItem);
		}
		LastSelectedItem = HitResult.Actor.Get();
		return;
	}
}

void AJoyWayBaseCharacter::ApplyDamage_Implementation(int Value)
{
	HP -= Value;
	if (HP <= 0)
	{
		Die();
	}
	else
	{
		CharacterHPChanged.Broadcast(HP, MaxHP);
	}
}

void AJoyWayBaseCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AJoyWayBaseCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AJoyWayBaseCharacter::StartFire()
{
	WidgetInteractionComponent->PressPointerKey(EKeys::LeftMouseButton); 
	if (WidgetInteractionComponent->IsOverFocusableWidget())
	{
		return;
	}
	if (IsValid(JoyWayBaseWeapon))
	{
		JoyWayBaseWeapon->StartFire();
	}
}

void AJoyWayBaseCharacter::StopFire()
{
	WidgetInteractionComponent->ReleasePointerKey(EKeys::LeftMouseButton);
	if (IsValid(JoyWayBaseWeapon))
	{
		JoyWayBaseWeapon->StopFire();
	}
}

void AJoyWayBaseCharacter::Reload()
{
	if (IsValid(JoyWayBaseWeapon))
	{
		JoyWayBaseWeapon->StartReloading();
	}
}
void AJoyWayBaseCharacter::EquipWeapon(AJoyWayBaseWeapon* NewWeapon)
{
	if (IsValid(NewWeapon))
	{
		NewWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), FName("GripPoint"));
		NewWeapon->SetActorEnableCollision(false);
		AJoyWayBaseWeapon* TempWeapon = JoyWayBaseWeapon;
		JoyWayBaseWeapon = NewWeapon;
		AmmoDelegateHandler = JoyWayBaseWeapon->WeaponAmmoChanged.AddUObject(this, &AJoyWayBaseCharacter::OnAmmoChanged);


		int OutCurrentAmmo;
		int OutMaxAmmo;
		GetAmmo(OutCurrentAmmo, OutMaxAmmo);


		if (TempWeapon)
		{
			UWeaponItem*  TempItem = Cast<UWeaponItem>(IPickableItem::Execute_Pick(TempWeapon));
			TempItem->CurrentAmmo = TempWeapon->CurrentAmmo;
			InventoryComponent->AddItem(TempItem);
			TempWeapon->WeaponAmmoChanged.Remove(AmmoDelegateHandler);
			TempWeapon->Destroy();
		}

		CharacterAmmoChanged.Broadcast(OutCurrentAmmo, OutMaxAmmo);
	}
}

void AJoyWayBaseCharacter::OnAmmoChanged(int CurrentAmmo, int MaxAmmo)
{
	CharacterAmmoChanged.Broadcast(CurrentAmmo, MaxAmmo);
}

void AJoyWayBaseCharacter::Equip()
{

	if (LastSelectedItem)
	{
		if (!IsValid(JoyWayBaseWeapon))
		{
			AJoyWayBaseWeapon* TargetWeapon = Cast<AJoyWayBaseWeapon>(LastSelectedItem);
			if (TargetWeapon)
			{
				EquipWeapon(TargetWeapon);
				return;
			}
		}
		if (InventoryComponent->AddItem(IPickableItem::Execute_Pick(LastSelectedItem)))
		{
			IPickableItem::Execute_DestroyItem(LastSelectedItem);
		}
	}

}

void AJoyWayBaseCharacter::GetHP(int& OutHP, int& OutMaxHP)
{
	OutHP = HP;
	OutMaxHP = MaxHP;
}

void AJoyWayBaseCharacter::Die()
{
	CharacterDieDelegate.Broadcast();
	if (IsValid(JoyWayBaseWeapon))
	{
		JoyWayBaseWeapon->Destroy();
	}
	Destroy();
}

void AJoyWayBaseCharacter::UseItem(UBaseItem* Item)
{
	if(IsValid(Item))
	{
		Item->Use(this);
	}
}

void AJoyWayBaseCharacter::GetAmmo(int& OutCurrentAmmo, int& OutMaxAmmo)
{
	if (IsValid(JoyWayBaseWeapon))
	{
		JoyWayBaseWeapon->GetAmmo(OutCurrentAmmo, OutMaxAmmo);
	}
	else
	{
		OutCurrentAmmo = 0;
		OutMaxAmmo = 0;
	}
}

void AJoyWayBaseCharacter::Heal(int AdditionalHP)
{
	HP += AdditionalHP;
	HP = HP > MaxHP ? MaxHP : HP;
	CharacterHPChanged.Broadcast(HP, MaxHP);
}
