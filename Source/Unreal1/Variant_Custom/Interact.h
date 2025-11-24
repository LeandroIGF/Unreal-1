// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interact.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UInteract : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class UNREAL1_API IInteract
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	// Esempio di funzione di interazione da implementare nelle classi che ereditano questa interfaccia
	// OBBLIGATORIA
	// quasi mai usata, solo per vedere nel modo vecchio c++
	virtual void Interact(AActor* Actor) = 0;

	// NON OBBLIGATORIA
	// Modo piu' usato per una funzione solo c++
	virtual void OptionalInteract(AActor* Actor);

	// Sistema di reflection di unreal, da implementare in c++ classi che ereditano questa interfaccia
	// non si puo' creare un'implementazione di default in questa interfaccia
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void BlueprintInteract(AActor* Actor);
	
};
