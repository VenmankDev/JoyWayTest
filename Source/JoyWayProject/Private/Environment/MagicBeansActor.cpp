// Fill out your copyright notice in the Description page of Project Settings.


#include "Environment/MagicBeansActor.h"
#include "Items/UselessItem.h"

// Sets default values
AMagicBeansActor::AMagicBeansActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

UBaseItem* AMagicBeansActor::Pick_Implementation()
{
	return UselessItem;
}

void AMagicBeansActor::DestroyItem_Implementation()
{
	Destroy();
}
