// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Characters/JoyWayBaseCharacter.h"
#include "JoyWayBaseGameMode.generated.h"

/**
 * 
 */
UCLASS()
class JOYWAYPROJECT_API AJoyWayBaseGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AJoyWayBaseCharacter> PlayerPawnClass;

protected:
	FTransform SpawnTransform;
	AJoyWayBaseCharacter* CurrentPawn;

public:
	AJoyWayBaseGameMode();

	UFUNCTION()
	void LoadNewMap(FSoftObjectPath Path);

protected:
	virtual void BeginPlay() override;
	void OnCurrentPawnDie();
};
