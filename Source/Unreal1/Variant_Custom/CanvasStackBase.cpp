// Fill out your copyright notice in the Description page of Project Settings.


#include "Variant_Custom/CanvasStackBase.h"
#include "Components/CanvasPanel.h"
#include "CommonUI/Public/Widgets/CommonActivatableWidgetContainer.h"



void UCanvasStackBase::NativeConstruct()
{

	Super::NativeConstruct();

	if (IsValid(RootCanvas))
	{
		UE_LOG(LogTemp, Display, TEXT("CANVAS VALID"));
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("CANVAS NOT VALID"));
	}

	if (IsValid(WidgetStackContainer))
	{
		UE_LOG(LogTemp, Display, TEXT("Container VALID"));
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("Container NOT VALID"));
	}
}
