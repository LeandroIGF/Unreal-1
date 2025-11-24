// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Variant_Custom/Interact.h"
#include "CPP_PickUp.generated.h"

//forward declarations
class UPickUpMovementComponent;
class USphereComponent;
class UStaticMeshComponent;

// delegates declarations

// single delegate declaration
DECLARE_DELEGATE(FOnInteractSingleDelegate);
// single delegate with parameters declaration and return value
DECLARE_DELEGATE_RetVal_TwoParams(bool, FOnInteractReturnWithParams, float, float);

// multicast delegate declaration
DECLARE_MULTICAST_DELEGATE(FOnINteractMultiDelegate);
// multicast delegate with parameters declaration
DECLARE_MULTICAST_DELEGATE_ThreeParams(FOnInteractMultiParam, bool, float, int);

// single delegate dynamic declaration
DECLARE_DYNAMIC_DELEGATE(FOnInteractSingleDynamicDelegate);
// multicast delegate dynamic declaration
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteractMultiDynamicDelegate);
// multicast delegate dynamic with parameters declaration
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInteractMultiDynamicParamDelegate, bool, bSuccess, float, HealthGained);

UCLASS()
class UNREAL1_API ACPP_PickUp : public AActor, public IInteract
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_PickUp();

	// implementazione IInteract interface
	virtual void Interact(AActor* Actor) override;

	void BlueprintInteract_Implementation(AActor* Actor);

	FOnInteractSingleDelegate OnInteractSingle;

	FOnINteractMultiDelegate OnInteractMulti;

	FOnInteractReturnWithParams OnInteractReturnParams;

	UPROPERTY()
	FOnInteractSingleDynamicDelegate OnInteractSingleDynamic;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnInteractMultiDynamicDelegate OnInteractMultiDynamic;

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
