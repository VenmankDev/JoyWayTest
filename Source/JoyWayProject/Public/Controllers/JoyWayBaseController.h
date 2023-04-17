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
protected:
	AJoyWayBaseCharacter* JoyWayBasePawn;
	AJoyWayBaseHUD* JoyWayBaseHUD;

	FDelegateHandle HPDelegateHandler;
	FDelegateHandle AmmoDelegateHandler;

public:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void StartJumping();

	void StartFireAction();
	void StopFireAction();
	void Reload();
	void Equip();

protected:
	UFUNCTION()
	void HPChanged(int CurrentHP, int MaxHP);

	UFUNCTION()
	void AmmoChanged(int CurrentAmmo, int MaxAmmo);

	UFUNCTION()
	void InitialUpdate();

	void BeginPlay() override;
	void SetupInputComponent() override;
	void OnPossess(APawn* aPawn) override;
	void OnUnPossess() override;
};
