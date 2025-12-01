// Fill out your copyright notice in the Description page of Project Settings.


#include "Variant_Custom/CPP_FPS_Character.h"
#include "CPP_FPS_InteractionComponent.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACPP_FPS_Character::ACPP_FPS_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Creiamo la mesh da aggiungere nella gerarchia dei componenti visibil
	CompanionMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Companion"));

	//... Altri settaggi relativi al componente

	CompanionMesh->SetupAttachment(RootComponent);

	//Creaimo il nostro componente di logica, uguale a quello visibile ma senza il setup attachment

	InteractionComponent = CreateDefaultSubobject<UCPP_FPS_InteractionComponent>(TEXT("Interaction"));

	InteractionComponent->RadiusInteraction = 200.f;
	InteractionComponent->DistanceInteraction = 1000.f;

	InteractionComponent->Transform.Add(FTransform());
	InteractionComponent->Transform.Add(FTransform());
	InteractionComponent->Transform.Add(FTransform());


}

// Called when the game starts or when spawned
void ACPP_FPS_Character::BeginPlay()
{
	Super::BeginPlay();

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnParams.Owner = this;

	GetWorld()->SpawnActor<AActor>(CompanionClass,GetActorTransform(), SpawnParams);

	//DrawDebugSphere(GetWorld(), GetActorLocation(), 100.f, 12, FColor::Blue, false, 5.f, (uint8)0U, 10.f);
	
	if(IsValid(InteractionComponent))
	{
		UE_LOG(LogTemp, Display, TEXT("IS VALID"));
	}

	//SETUP CALL BACK PICK UPS

	//Interfaces
	for (ACPP_PickUp* Target : PickUps)
	{
		if (Target->Implements<UInteract>())
		{
			TScriptInterface<IInteract> Interactable = TScriptInterface<IInteract>(Target);
			//Interactable.GetInterface()->BlueprintInteract(this);
			IInteract::Execute_BlueprintInteract(Interactable.GetObject(), this);

		}
	}


	//BIND
	for (ACPP_PickUp* Target : PickUps)
	{
		if(Target)
		{	
			// bind multicast dynamic delegate
			Target->OnInteractMultiDynamic.AddDynamic(this, &ACPP_FPS_Character::PrintInteractable);

			// bind single dynamic delegate
			Target->OnInteractSingleDynamic.BindDynamic(this, &ACPP_FPS_Character::PrintInteractable);

			// bind single delegate
			Target->OnInteractSingle.BindUObject(this, &ACPP_FPS_Character::PrintInteractable);

			// bind multicast delegate
			Target->OnInteractMulti.AddUObject(this, &ACPP_FPS_Character::PrintInteractable);
		}
	}

	for (ACPP_PickUp* Target : PickUps)
	{
		if (Target)
		{
			// bind multicast dynamic delegate
			Target->OnInteractMultiDynamic.Broadcast();

			// bind multicast delegate
			Target->OnInteractMulti.Broadcast();
			
			// bind single delegate
			Target->OnInteractSingle.Execute();
			
			// bind single dynamic delegate
			Target->OnInteractSingleDynamic.Execute();			
		}
	}	
}

// Called every frame
void ACPP_FPS_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

// Called to bind functionality to input
void ACPP_FPS_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACPP_FPS_Character::OnConstruction(const FTransform& Transforms)
{


}

AActor* ACPP_FPS_Character::GetCompanion()
{	
	if(!IsValid(SpawnedCompanionActor))
	{		
		return nullptr;
	}

	FVector Location;

	Location = SpawnedCompanionActor->GetActorLocation();

	return SpawnedCompanionActor;
}

void ACPP_FPS_Character::PrintInteractable()
{
	if (InteractableObject.GetObject() && InteractableObject.GetInterface())
	{
		// se la classe che ha l'interfaccia il suo padre c++ lo implementa
		InteractableObject.GetInterface()->OptionalInteract(this);
	}
	else
	{
		// se la classe e' un blueprint che implementa l'interfaccia
		//IInteractable::Execute_BlueprintInteract
		InteractableObject.GetInterface()->Execute_BlueprintInteract(InteractableObject.GetObject(), this);
	}
}

void ACPP_FPS_Character::InterfaceBluprintFunction(const TScriptInterface<IInteract>& InterfacInput, TScriptInterface<IInteract>& InterfaceOutput)
{
	
}








