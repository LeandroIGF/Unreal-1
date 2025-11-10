// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CPP_FPS_InteractionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), BlueprintType, Blueprintable)
class UNREAL1_API UCPP_FPS_InteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
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

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "FPS_Character", Meta = (MakeEditWidget = true))
	TArray<FTransform> Transform;

private:
	//** ActorToIgnore
	UPROPERTY(VisibleAnywhere, Category = "FPS_Character")
	TArray<AActor*> ActorsToIgnore;

	//** ActorToIgnore
	UPROPERTY(VisibleAnywhere, Category = "FPS_Character")
	TArray<AActor*> ActorsFound;

	UPROPERTY(VisibleAnywhere, Category = "FPS_Character")
	AActor* ClosestActor;

	

public:	
	// Sets default values for this component's properties
	UCPP_FPS_InteractionComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Interaction Trace Objects
	UFUNCTION(BlueprintCallable, Category = "FPS_Character")
	TArray<AActor*> InteractionTraceObjects(const float Distance, const float Radius);
};
