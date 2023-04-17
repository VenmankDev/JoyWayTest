// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/DamageDemonstratorWidget.h"

void UDamageDemonstratorWidget::UpdateDamage(float NewDamage)
{
	CurrentSumDamage += NewDamage;
	if (ClearTimer.IsValid())
	{
		GetWorld()->GetTimerManager().ClearTimer(ClearTimer);
	}

	GetWorld()->GetTimerManager().SetTimer(ClearTimer, this, &UDamageDemonstratorWidget::OnClearTimer, 5.f);
	ShowDamage(CurrentSumDamage);
}
void UDamageDemonstratorWidget::OnClearTimer()
{
	CurrentSumDamage = 0.f;
	ShowDamage(CurrentSumDamage);
}
