// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPP_FPS_Character.generated.h"

class UCPP_FPS_InteractionComponent;

UCLASS()
class UNREAL1_API ACPP_FPS_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPP_FPS_Character();

	//** Character Name
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "FPS_Character")
	FString CharacterName = "";

	//** ActorClass To Spawn
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "FPS_Character")
	TSubclassOf<AActor> CompanionClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "FPS_Character", Meta = (MakeEditWidget = true))
	TArray<FTransform> Transform;

	

private:

	
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "FPS_Character", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> CompanionMesh; // UStaticMeshComponent*

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "FPS_Character", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCPP_FPS_InteractionComponent> InteractionComponent; // UCPP_FPS_InteractionComponent*

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void OnConstruction();
};
