// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DamageSpawner.generated.h"

class UBoxComponent;
class IJoyWayDamageble;

UCLASS()
class JOYWAYPROJECT_API ADamageSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADamageSpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* DamageZone;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DamageDelay = 1.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Damage = 7;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION()
	virtual void OnDamageZoneBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	virtual void OnDamageZoneEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UFUNCTION()
	virtual void OnDamageTimer();

	TArray<AActor*> ActorsToDamage;
	FTimerHandle DamageTimer;

};
