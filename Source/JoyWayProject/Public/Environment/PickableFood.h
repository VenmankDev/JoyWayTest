// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/PickableItem.h"
#include "PickableFood.generated.h"

class UHealingItem;

UCLASS()
class JOYWAYPROJECT_API APickableFood : public AActor, public IPickableItem
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UMaterialInterface* MaterialToSelect;
	UPROPERTY(BlueprintReadWrite)
	UMaterialInterface* MaterialToSave;
	UPROPERTY(EditDefaultsOnly, Instanced)
	UHealingItem* HealingItem;
	APickableFood();

	virtual UBaseItem* Pick_Implementation() override;
	virtual void DestroyItem_Implementation() override;

};
