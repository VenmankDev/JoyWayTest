// Fill out your copyright notice in the Description page of Project Settings.


#include "Environment/DamageSpawner.h"
#include "Components/BoxComponent.h"
#include "Interfaces/JoyWayDamageble.h"

// Sets default values
ADamageSpawner::ADamageSpawner()
{

	PrimaryActorTick.bCanEverTick = false;
	DamageZone = CreateDefaultSubobject<UBoxComponent>(TEXT("DamageZone"));
	DamageZone->OnComponentBeginOverlap.AddDynamic(this, &ADamageSpawner::OnDamageZoneBeginOverlap);
	DamageZone->OnComponentEndOverlap.AddDynamic(this, &ADamageSpawner::OnDamageZoneEndOverlap);
}

// Called when the game starts or when spawned
void ADamageSpawner::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(DamageTimer, this, &ADamageSpawner::OnDamageTimer, DamageDelay, true);
}

void ADamageSpawner::OnDamageZoneBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Other->GetClass()->ImplementsInterface(UJoyWayDamageble::StaticClass()))
	{
		ActorsToDamage.AddUnique(Other);
	}
}

void ADamageSpawner::OnDamageZoneEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (ActorsToDamage.Contains(Other))
	{
		ActorsToDamage.RemoveSingle(Other);
	}
}

void ADamageSpawner::OnDamageTimer()
{
	for (int i = ActorsToDamage.Num() - 1; i >= 0; i--)
	{
		if (IsValid(ActorsToDamage[i]))
		{
			IJoyWayDamageble::Execute_ApplyDamage(ActorsToDamage[i], Damage);
		}
		else
		{
			ActorsToDamage.RemoveAt(i);
		}
	}
}