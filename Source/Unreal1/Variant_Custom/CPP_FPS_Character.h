// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPP_FPS_Character.generated.h"

UCLASS()
class UNREAL1_API ACPP_FPS_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPP_FPS_Character();

	//** Trace Interaction Distance
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "FPS_Character")
	float DistanceInteraction = 1500.f;

	//** Radius Interaction Distance
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "FPS_Character")
	float RadiusInteraction = 400.f;

	//** Objects types
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "FPS_Character")
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypesToInteract;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "FPS_Character")
	bool bDebugInteraction = false;

	//** Character Name
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "FPS_Character")
	FString CharacterName = "";



private:
	//** ActorToIgnore
	UPROPERTY(EditAnywhere, Category = "FPS_Character")
	TArray<AActor*> ActorsToIgnore;

	//** ActorToIgnore
	UPROPERTY(EditAnywhere, Category = "FPS_Character")
	TArray<AActor*> ActorsFound;

	UPROPERTY(EditAnywhere, Category = "FPS_Character")
	AActor* ClosestActor;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Interaction Trace Objects
	UFUNCTION(BlueprintCallable, Category = "FPS_Character")
	TArray<AActor*> InteractionTraceObjects(const float Distance, const float Radius);



};
