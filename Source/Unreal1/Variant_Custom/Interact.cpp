// Fill out your copyright notice in the Description page of Project Settings.


#include "Interact.h"

// Add default functionality here for any IInteract functions that are not pure virtual.


void IInteract::OptionalInteract(AActor* Actor)
{
	UE_LOG(LogTemp, Warning, TEXT("Optional Interact Implemented in c++")); 
	AActor* ImplementerActor = Cast<AActor>(this);
	//const AActor* ImplementerActor = Cast<IInteract>(this);
	//TODO: aggiungere controllo puntatore
	Execute_BlueprintInteract(ImplementerActor, ImplementerActor);
}



