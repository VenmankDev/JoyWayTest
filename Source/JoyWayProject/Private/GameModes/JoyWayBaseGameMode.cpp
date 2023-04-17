// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/JoyWayBaseGameMode.h"
#include "Characters/JoyWayBaseCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerStart.h"
#include "Controllers/JoyWayBaseController.h"
#include "Components/WidgetComponent.h"
#include "Environment/InventoryActor.h"
#include "Widgets/InventoryDemonstratorWidget.h"

AJoyWayBaseGameMode::AJoyWayBaseGameMode()
{
	PrimaryActorTick.bCanEverTick = false;
}


void AJoyWayBaseGameMode::BeginPlay()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AJoyWayBaseCharacter::StaticClass(), FoundActors);
	if (FoundActors.Num())
	{
		CurrentPawn = Cast<AJoyWayBaseCharacter>(FoundActors[0]);
	}
	if (!IsValid(CurrentPawn))
	{
		return;
	}
	CurrentPawn->CharacterDieDelegate.AddUObject(this, &AJoyWayBaseGameMode::OnCurrentPawnDie);
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), FoundActors);
	if (FoundActors.Num())
	{
		SpawnTransform = FoundActors[0]->GetActorTransform();
	}

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AInventoryActor::StaticClass(), FoundActors);
	for(AActor* InventoryActor : FoundActors)
	{
		UInventoryDemonstratorWidget* InventoryWidget = Cast<UInventoryDemonstratorWidget>(Cast<AInventoryActor>(InventoryActor)->InventoryWidget->GetWidget());
		InventoryWidget->SetInventory(CurrentPawn->InventoryComponent);
	}

}
void AJoyWayBaseGameMode::OnCurrentPawnDie()
{
	AJoyWayBaseCharacter* NewChar = (AJoyWayBaseCharacter*) GetWorld()->SpawnActor(PlayerPawnClass.Get(), &SpawnTransform);
	CurrentPawn->GetController()->Possess(NewChar);
	CurrentPawn = NewChar;

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AInventoryActor::StaticClass(), FoundActors);
	for (AActor* InventoryActor : FoundActors)
	{
		UInventoryDemonstratorWidget* InventoryWidget = Cast<UInventoryDemonstratorWidget>(Cast<AInventoryActor>(InventoryActor)->InventoryWidget->GetWidget());
		InventoryWidget->SetInventory(CurrentPawn->InventoryComponent);
	}
	CurrentPawn->CharacterDieDelegate.AddUObject(this, &AJoyWayBaseGameMode::OnCurrentPawnDie);
}

void AJoyWayBaseGameMode::LoadNewMap(FSoftObjectPath Path)
{
	UGameplayStatics::OpenLevel(this, Path.GetAssetPathName());
}