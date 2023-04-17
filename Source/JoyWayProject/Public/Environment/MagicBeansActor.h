// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/PickableItem.h"
#include "MagicBeansActor.generated.h"

class UUselessItem;

UCLASS()
class JOYWAYPROJECT_API AMagicBeansActor : public AActor, public IPickableItem
{
	GENERATED_BODY()
	
public:	
	AMagicBeansActor();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UMaterialInterface* MaterialToSelect;
	UPROPERTY(BlueprintReadWrite)
	UMaterialInterface* MaterialToSave;
	UPROPERTY(EditDefaultsOnly, Instanced)
	UUselessItem* UselessItem;


	virtual UBaseItem* Pick_Implementation() override;
	virtual void DestroyItem_Implementation() override;

};
