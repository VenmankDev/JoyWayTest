// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnInvetoryUpdated)

class UBaseItem;

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class JOYWAYPROJECT_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	FOnInvetoryUpdated OnInvetoryUpdated;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TArray<UBaseItem*> Items;

protected:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	int MaxCapacity;

public:
	UInventoryComponent();

	bool AddItem(UBaseItem* Item);
	bool RemoveItem(UBaseItem* Item);

protected:
	virtual void BeginPlay() override;


		
};
