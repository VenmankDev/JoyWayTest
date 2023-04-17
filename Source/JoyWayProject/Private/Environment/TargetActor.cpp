// Fill out your copyright notice in the Description page of Project Settings.


#include "Environment/TargetActor.h"
#include "Components/WidgetComponent.h"
#include "Widgets/DamageDemonstratorWidget.h"

// Sets default values
ATargetActor::ATargetActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	TargetMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TargetMesh"));
	SetRootComponent(TargetMesh);
	DamageDemonstratorComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("DamageDemonstrator"));
	DamageDemonstratorComponent->SetupAttachment(TargetMesh);

}

// Called when the game starts or when spawned
void ATargetActor::BeginPlay()
{
	Super::BeginPlay();
	DamageDemonstrator = Cast<UDamageDemonstratorWidget>(DamageDemonstratorComponent->GetWidget());
}

void ATargetActor::ApplyDamage_Implementation(int Value)
{
	if (DamageDemonstrator)
	{
		DamageDemonstrator->UpdateDamage(Value);
	}
}
