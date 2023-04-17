// Fill out your copyright notice in the Description page of Project Settings.


#include "Environment/InventoryActor.h"
#include "Components/WidgetComponent.h"

// Sets default values
AInventoryActor::AInventoryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	InventoryWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("InventoryWidget"));
	SetRootComponent(InventoryWidget);

}

