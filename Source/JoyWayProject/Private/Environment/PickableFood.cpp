// Fill out your copyright notice in the Description page of Project Settings.


#include "Environment/PickableFood.h"
#include "Items/HealingItem.h"

// Sets default values
APickableFood::APickableFood()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

UBaseItem* APickableFood::Pick_Implementation()
{
	return HealingItem;
}

void APickableFood::DestroyItem_Implementation()
{
	Destroy();
}
