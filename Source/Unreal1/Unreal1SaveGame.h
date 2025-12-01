// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Unreal1SaveGame.generated.h"

/**
 * 
 */

 // Struttura per salvare i dati del giocatore
USTRUCT(BlueprintType)
struct FSaveDataTransformPlayer
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SaveData")
	FVector LocationPlayer;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SaveData")
	FRotator RotationPlayer;
};


// Classe per gestire il salvataggio del gioco
UCLASS()
class UNREAL1_API UUnreal1SaveGame : public USaveGame
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	FString SaveSlotName;

	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	int32 UserIndex;

	// esempoio di variabile da salvare dentro alla classe
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SaveData")
	float HealthPlayer;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SaveData")
	FSaveDataTransformPlayer DataPlayer;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SaveData")
	TMap<int32, int32> InventoryItems; // key: ItemID, value: Quantity	
};
