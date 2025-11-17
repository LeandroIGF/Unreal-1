// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "BFL_HUDHelper.generated.h"



class UCommonActivatableWidget;

/**
 * 
 */
UCLASS()
class UNREAL1_API UBFL_HUDHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	//Push Widget Class To the given CommonWidget
	UFUNCTION(BlueprintCallable, Category = "HUD Helper")
	static void PushWidget(TSubclassOf<UCommonActivatableWidget> WidgetToPush);

};
