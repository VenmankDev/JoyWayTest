// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "JoyWayBaseController.generated.h"

class AJoyWayBaseCharacter;
class AJoyWayBaseHUD;

/**
 * 
 */
UCLASS(Blueprintable)
class JOYWAYPROJECT_API AJoyWayBaseController : public APlayerController
{
	GENERATED_BODY()
	AJoyWayBaseCharacter* JoyWayBasePawn;
	AJoyWayBaseHUD* JoyWayBaseHUD;
public:
	//Movement
	void MoveForward(float Value);
	void MoveRight(float Value);
	void StartJumping();

	//Weapon
	void StartFireAction();
	void StopFireAction();
	void Reload();

	void Equip();

	UFUNCTION()
	void HPChanged(int CurrentHP, int MaxHP);

	UFUNCTION()
	void AmmoChanged(int CurrentAmmo, int MaxAmmo);

	UFUNCTION()
	void InitialUpdate();

	FDelegateHandle HPDelegateHandler;
	FDelegateHandle AmmoDelegateHandler;
protected:
	void BeginPlay() override;
	void SetupInputComponent() override;
	void OnPossess(APawn* aPawn) override;
	void OnUnPossess() override;
};
