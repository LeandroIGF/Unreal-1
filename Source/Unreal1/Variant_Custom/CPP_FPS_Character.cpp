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

void ACPP_FPS_Character::OnConstruction()
{


}




