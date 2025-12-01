// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Unreal1SaveGame.h"
#include "SaveManagerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL1_API USaveManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	// Add private member variables and functions here
	UPROPERTY()
	UUnreal1SaveGame* CurrentSaveGame;

	const FString DefaultSaveSlotName = TEXT("DefaultPlayerSaveSlot");
	const int32 DefaultUserIndex = 0;

public:
	// Subsystem initialization and deinitialization
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// Controlliamo se un salvataggio esiste
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SaveGame")
	bool DoesSaveExist();

	// Carichiamo il salvataggio
	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	bool LoadOrCreateSaveGame();

	// Salviamo il gioco
	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	bool SaveGame();

	// Otteniamo il salvataggio corrente
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SaveGame")
	UUnreal1SaveGame* GetCurrentSaveGame();
	
};
