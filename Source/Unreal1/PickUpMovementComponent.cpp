// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpMovementComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values for this component's properties
UPickUpMovementComponent::UPickUpMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UPickUpMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// Trova il componente Static Mesh nell'Owner e memorizza la posizione iniziale
	FindTargetStaticMesh();

	if (IsValid(TargetMesh))
	{
		// Ottieni la posizione relativa iniziale.
		InitialRelativeLocation = TargetMesh->GetRelativeLocation();
	}
}

void UPickUpMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsValid(TargetMesh))
	{
		// Ottieni il tempo totale di gioco
		float Time = GetWorld()->GetTimeSeconds();

		// Calcola l'offset Z usando la funzione Sinusoidale
		// Formula: Offset_Z = Ampiezza * sin(Tempo * 2 * PI * Frequenza)
		float VerticalOffset = Amplitude * FMath::Sin(Time * 2.0f * PI * Frequency);
		

		// Calcola la nuova posizione relativa
		FVector NewRelativeLocation = InitialRelativeLocation;
		NewRelativeLocation.Z += VerticalOffset;

		// Imposta la nuova posizione relativa (movimento relativo all'Owner)
		TargetMesh->SetRelativeLocation(NewRelativeLocation);
	}
}

void UPickUpMovementComponent::SetMeshToMove(UStaticMeshComponent* Mesh)
{
	if (IsValid(Mesh))
	{
		TargetMesh = Mesh;
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("Nullptr Mesh"));
		TargetMesh = nullptr;

	}
	
}

void UPickUpMovementComponent::FindTargetStaticMesh()
{
	AActor* Owner = GetOwner();
	if (Owner)
	{
		// Assumiamo che tu voglia muovere il primo UStaticMeshComponent trovato
		SetMeshToMove(Owner->FindComponentByClass<UStaticMeshComponent>());

		if (!TargetMesh)
		{
			UE_LOG(LogTemp, Warning, TEXT("PickUpMovementComponent: Nessun UStaticMeshComponent trovato nell'Owner %s."), *Owner->GetName());
		}
		// IMPORTANTE: Il componente deve essere Movable per poter essere mosso nel Tick
		else if (TargetMesh->Mobility != EComponentMobility::Movable)
		{
			TargetMesh->SetMobility(EComponentMobility::Movable);
			UE_LOG(LogTemp, Warning, TEXT("PickUpMovementComponent: Mobilità di %s impostata su Movable."), *TargetMesh->GetName());
		}
	}
}
