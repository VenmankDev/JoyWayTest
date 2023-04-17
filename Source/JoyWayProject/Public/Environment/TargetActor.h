// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/JoyWayDamageble.h"
#include "TargetActor.generated.h"

class UWidgetComponent;
class UDamageDemonstratorWidget;

UCLASS()
class JOYWAYPROJECT_API ATargetActor : public AActor, public IJoyWayDamageble
{
	GENERATED_BODY()
public:	
	ATargetActor();
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UWidgetComponent* DamageDemonstratorComponent;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UStaticMeshComponent* TargetMesh;

	UDamageDemonstratorWidget* DamageDemonstrator;

protected:
	virtual void BeginPlay() override;

	virtual void ApplyDamage_Implementation(int Value) override;

};
