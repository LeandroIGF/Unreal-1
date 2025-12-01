// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveManagerSubsystem.h"
#include "Kismet/GameplayStatics.h"

void USaveManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	UE_LOG(LogTemp, Display, TEXT("Save Manager Subsystem Initialized"));

	// Additional initialization logic can be added here
}

void USaveManagerSubsystem::Deinitialize()
{
	Super::Deinitialize();

	UE_LOG(LogTemp, Display, TEXT("Save Manager Subsystem Deinitialized"));

	// Additional cleanup logic can be added here
}

bool USaveManagerSubsystem::DoesSaveExist()
{
	
	bool bSaveExists = UGameplayStatics::DoesSaveGameExist(DefaultSaveSlotName, DefaultUserIndex);
	// Additional logging for debugging or functionality
	return bSaveExists;
}

bool USaveManagerSubsystem::LoadOrCreateSaveGame()
{
	if (DoesSaveExist())
	{
		//LOADING SAVE GAME
		//1 - Load existing save game from disk
		USaveGame* LoadedSaveGame = UGameplayStatics::LoadGameFromSlot(DefaultSaveSlotName, DefaultUserIndex);

		if (IsValid(LoadedSaveGame))
		{
			//2 - Cast to your custom save game class
			CurrentSaveGame = Cast<UUnreal1SaveGame>(LoadedSaveGame);
			if (IsValid(CurrentSaveGame))
			{
				UE_LOG(LogTemp, Warning, TEXT("Save Game Loaded Successfully"));
				return true;
			}
		}
	}

	//CREATING NEW SAVE GAME IF NONE EXISTS
	//1 - Create a new save game object
	CurrentSaveGame = Cast<UUnreal1SaveGame>(UGameplayStatics::CreateSaveGameObject(UUnreal1SaveGame::StaticClass()));

	if(IsValid(CurrentSaveGame))
	{
		//2 - Initialize default values in CurrentSaveGame here		
		CurrentSaveGame->SaveSlotName = DefaultSaveSlotName;
		CurrentSaveGame->UserIndex = DefaultUserIndex;


		UE_LOG(LogTemp, Warning, TEXT("New Save Game Created Successfully"));
		return true;
	}

	UE_LOG(LogTemp, Error, TEXT("Failed to create or load SaveGame object!"));
	return false;
}

bool USaveManagerSubsystem::SaveGame()
{
	// Control to ensure CurrentSaveGame is valid
	if(!IsValid(CurrentSaveGame))
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot save: CurrentSaveGame is null."));
		return false;
	}

	// Salvare dati all'interno di CurrentSaveGame prima di salvarlo su disco
	//GetCurrentSaveGame()->HealthPlayer = 50;

	bool bSaveSuccessful = UGameplayStatics::SaveGameToSlot(CurrentSaveGame, DefaultSaveSlotName, DefaultUserIndex);

	if (bSaveSuccessful)
	{
		UE_LOG(LogTemp, Warning, TEXT("Game Saved Successfully to slot: %s"), *DefaultSaveSlotName);
		return true;
	}	
	
	UE_LOG(LogTemp, Error, TEXT("Failed to Save Gameto slot: %s"), *DefaultSaveSlotName);
	return false;
}

UUnreal1SaveGame* USaveManagerSubsystem::GetCurrentSaveGame()
{
	// Addtional checks can be added here if needed
	return CurrentSaveGame;
}

