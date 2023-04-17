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
	// Sets default values for this component's properties
	UInventoryComponent();
	// Called when the game starts
	virtual void BeginPlay() override;
	FOnInvetoryUpdated OnInvetoryUpdated;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TArray<UBaseItem*> Items;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	int MaxCapacity;

	bool AddItem(UBaseItem* Item);
	bool RemoveItem(UBaseItem* Item);


		
};
