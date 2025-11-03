// Fill out your copyright notice in the Description page of Project Settings.


#include "Variant_Custom/CPP_FPS_Character.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACPP_FPS_Character::ACPP_FPS_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_FPS_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_FPS_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!GetWorld())
	{
		return;
	}

	ActorsFound = InteractionTraceObjects(DistanceInteraction, RadiusInteraction);
	float Distance;
	float InitDistance = 5000;
	ClosestActor = nullptr;

	for (AActor* Actor : ActorsFound)
	{
		Distance = Actor->GetDistanceTo(this);

		if (Distance < InitDistance)
		{
			InitDistance = Distance;
			ClosestActor = Actor;
		}
	}

	if (bDebugInteraction && IsValid(ClosestActor))
	{
		DrawDebugSphere(
			GetWorld(),
			ClosestActor->GetActorLocation(),
			200.f,
			12,
			FColor::Emerald,
			false,
			-1.f,
			(uint8)0U,
			10.f
		);

	}
}

// Called to bind functionality to input
void ACPP_FPS_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

TArray<AActor*> ACPP_FPS_Character::InteractionTraceObjects(const float Distance, const float Radius)
{
	FVector EndTrace = GetActorLocation() + (GetActorForwardVector() * Distance);

	
	TArray<FHitResult> Hits;

	TArray<AActor*> ActorsFoundInternal;

	if (!IsValid(GetWorld()))
	{		
		return ActorsFound;
	}

	UKismetSystemLibrary::SphereTraceMultiForObjects(
		GetWorld(), // Context to pass, we always pass the world context here
		GetActorLocation(), // Start Trace
		EndTrace, //End Trace
		Radius, // Radius Trace
		ObjectTypesToInteract, //ObjectTypes
		false, // complex trace
		ActorsToIgnore, //
		bDebugInteraction ? EDrawDebugTrace::ForOneFrame : EDrawDebugTrace::None,
		Hits, // Array HitResult to save hit information
		true // Ignore self
	);

	for(FHitResult HitResult : Hits)
	{
		if (IsValid(HitResult.GetActor()))
		{
			
			ActorsFoundInternal.AddUnique(HitResult.GetActor());
		}		
	}

	// UE LOG
	UE_LOG(LogTemp, Warning, TEXT("CHARACTER: %s"), *CharacterName);

	// LOG A SCHERMO
	/*
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			1,
			3.f,
			FColor::Yellow,
			TEXT("CHARACTER")
		);
	}

	// LOG TRAMITE KISMET SYSTEM LIBRARY
	if (IsValid(GetWorld()))
	{
		UKismetSystemLibrary::PrintString(GetWorld(), "CHARACTER");
	}
	*/


	return ActorsFoundInternal;
}



