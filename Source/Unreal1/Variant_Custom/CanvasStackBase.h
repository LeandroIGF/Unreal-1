// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "CanvasStackBase.generated.h"

class UCanvasPanel;
class UCommonActivatableWidgetContainerBase;

/**
 * 
 */
UCLASS()
class UNREAL1_API UCanvasStackBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:

	// Collegare questa variabile al CanvasPanel radice nel Widget Blueprint
	UPROPERTY(BlueprintReadOnly, EditAnywhere, meta = (BindWidget), Category = "CanvasStackBase")
	TObjectPtr<UCanvasPanel> RootCanvas;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, meta = (BindWidget), Category = "CanvasStackBase")
	TObjectPtr<UCommonActivatableWidgetContainerBase> WidgetStackContainer;

	
protected:

	// Sovrascrivi la funzione NativeConstruct per inizializzare il widget
	virtual void NativeConstruct() override;
	
};
