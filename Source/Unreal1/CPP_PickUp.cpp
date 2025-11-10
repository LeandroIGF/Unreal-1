// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PickUp.h"
#include "Components/SphereComponent.h"
#include "PickUpMovementComponent.h"

// Sets default values
ACPP_PickUp::ACPP_PickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Setup Component Visivi

	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collision"));
	SphereCollision->InitSphereRadius(75.0f);
	SphereCollision->SetCollisionProfileName("BlockAll");
	SphereCollision->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel2);
	
	SetRootComponent(SphereCollision);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Mesh->SetupAttachment(GetRootComponent());

	//Setup Componenti di logica

	PickUpMovement = CreateDefaultSubobject<UPickUpMovementComponent>(TEXT("PickUp Movement"));
	//PickUpMovement->SetMeshToMove(Mesh); // Da cambiare se si vuole cercare

}

// Called when the game starts or when spawned
void ACPP_PickUp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_PickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

