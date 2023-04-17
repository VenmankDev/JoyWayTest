// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InventoryActor.generated.h"


class UWidgetComponent;

UCLASS()
class JOYWAYPROJECT_API AInventoryActor : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UWidgetComponent* InventoryWidget;

	AInventoryActor();
};
