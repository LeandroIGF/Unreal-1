// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PickUpMovementComponent.generated.h"

class UStaticMeshComponent;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREAL1_API UPickUpMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPickUpMovementComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Proprietà che puoi modificare nell'Editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float Amplitude = 20.0f; // Ampiezza del movimento (unità Unreal)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float Frequency = 1.0f;  // Frequenza del movimento (cicli al secondo)

	UFUNCTION()
	void SetMeshToMove(UStaticMeshComponent* Mesh);

private:
	// Riferimento al componente Static Mesh da muovere
	UPROPERTY()
	UStaticMeshComponent* TargetMesh;

	// Posizione relativa iniziale del componente mesh
	FVector InitialRelativeLocation;

	void FindTargetStaticMesh();
		
};
