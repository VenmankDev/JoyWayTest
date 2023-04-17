// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/JoyWayBaseController.h"
#include "Characters/JoyWayBaseCharacter.h"
#include "HUDs/JoyWayBaseHUD.h"

void AJoyWayBaseController::BeginPlay()
{
	Super::BeginPlay();
	JoyWayBaseHUD = Cast<AJoyWayBaseHUD>(GetHUD());
}

void AJoyWayBaseController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("Fire", IE_Pressed, this, &AJoyWayBaseController::StartFireAction);
	InputComponent->BindAction("Fire", IE_Released, this, &AJoyWayBaseController::StopFireAction);
	InputComponent->BindAction("Equip", IE_Released, this, &AJoyWayBaseController::Equip);
	InputComponent->BindAction("Reload", IE_Pressed, this, &AJoyWayBaseController::Reload);
	InputComponent->BindAxis("MoveForward", this, &AJoyWayBaseController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AJoyWayBaseController::MoveRight);
	InputComponent->BindAxis("Turn", this, &AJoyWayBaseController::AddYawInput);
	InputComponent->BindAxis("LookUp", this, &AJoyWayBaseController::AddPitchInput);
	InputComponent->BindAction("Jump", IE_Pressed, this, &AJoyWayBaseController::StartJumping);
}

void AJoyWayBaseController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
	JoyWayBasePawn = Cast<AJoyWayBaseCharacter>(aPawn);
	if (IsValid(JoyWayBasePawn))
	{

		HPDelegateHandler = JoyWayBasePawn->CharacterHPChanged.AddUObject(this, &AJoyWayBaseController::HPChanged);
		AmmoDelegateHandler = JoyWayBasePawn->CharacterAmmoChanged.AddUObject(this, &AJoyWayBaseController::AmmoChanged);

		InitialUpdate();
	}
}

void AJoyWayBaseController::OnUnPossess()
{
	if (IsValid(JoyWayBasePawn))
	{
		JoyWayBasePawn->CharacterHPChanged.Remove(HPDelegateHandler);
		JoyWayBasePawn->CharacterAmmoChanged.Remove(AmmoDelegateHandler);
	}
}

void AJoyWayBaseController::MoveForward(float Value)
{
	if (IsValid(JoyWayBasePawn) && Value != 0.f)
	{
		JoyWayBasePawn->MoveForward(Value);
	}
}

void AJoyWayBaseController::MoveRight(float Value)
{
	if (IsValid(JoyWayBasePawn) && Value != 0.f)
	{
		JoyWayBasePawn->MoveRight(Value);
	}
}

void AJoyWayBaseController::StartFireAction()
{
	if (IsValid(JoyWayBasePawn))
	{
		JoyWayBasePawn->StartFire();
	}
}

void AJoyWayBaseController::StopFireAction()
{
	if (IsValid(JoyWayBasePawn))
	{
		JoyWayBasePawn->StopFire();
	}
}

void AJoyWayBaseController::Reload()
{
	if (IsValid(JoyWayBasePawn))
	{
		JoyWayBasePawn->Reload();
	}
}


void AJoyWayBaseController::StartJumping()
{
	if (IsValid(JoyWayBasePawn))
	{
		JoyWayBasePawn->Jump();
	}
}

void AJoyWayBaseController::Equip()
{
	if (IsValid(JoyWayBasePawn))
	{
		JoyWayBasePawn->Equip();
	}
}


void AJoyWayBaseController::HPChanged(int CurrentHP, int MaxHP)
{
	if (IsValid(JoyWayBaseHUD))
	{
		JoyWayBaseHUD->UpdateHP(CurrentHP, MaxHP);
	}
}

void AJoyWayBaseController::AmmoChanged(int CurrentAmmo, int MaxAmmo)
{
	if (IsValid(JoyWayBaseHUD))
	{
		JoyWayBaseHUD->UpdateAmmo(CurrentAmmo, MaxAmmo);
	}
}

void AJoyWayBaseController::InitialUpdate()
{
	if (IsValid(JoyWayBasePawn))
	{
		int CurrentValue;
		int MaxValue;

		JoyWayBasePawn->GetAmmo(CurrentValue, MaxValue);
		AmmoChanged(CurrentValue, MaxValue);
		JoyWayBasePawn->GetHP(CurrentValue, MaxValue);
		HPChanged(CurrentValue, MaxValue);
	}
}