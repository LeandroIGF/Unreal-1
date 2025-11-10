// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_PickUp.generated.h"

class UPickUpMovementComponent;
class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class UNREAL1_API ACPP_PickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_PickUp();

private:

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "PickUp", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPickUpMovementComponent> PickUpMovement; // UPickUpMovementComponent*

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "PickUp", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USphereComponent> SphereCollision;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "PickUp", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Mesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
