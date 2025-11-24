// Fill out your copyright notice in the Description page of Project Settings.


#include "Variant_Custom/BFL_HUDHelper.h"
#include "Interact.h"
#include "CommonUI/Public/CommonActivatableWidget.h"

void UBFL_HUDHelper::PushWidget(TSubclassOf<UCommonActivatableWidget> WidgetToPush)
{
	
	UE_LOG(LogTemp, Warning, TEXT("Pushing Widget"));

}

void UBFL_HUDHelper::ShowInteractInfo(AActor* ActorInfo)
{
	if(IsValid(ActorInfo) && ActorInfo->Implements<UInteract>())
	{
		UE_LOG(LogTemp, Warning, TEXT("Showing Interact Info for Actor: %s"), *ActorInfo->GetName());
		
		// Call the BlueprintImplementableEvent o BLueprintNative event to show interact info
		IInteract::Execute_BlueprintInteract(ActorInfo, ActorInfo);

		// Call c++ interface function
		IInteract* InteractInterface = Cast<IInteract>(ActorInfo);
		InteractInterface->OptionalInteract(ActorInfo);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ActorInfo is not valid."));
	}

}

