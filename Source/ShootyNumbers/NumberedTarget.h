// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NumberedTarget.generated.h"

UCLASS()
class SHOOTYNUMBERS_API ANumberedTarget : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANumberedTarget();
	// COMPONENTS

	// Static Mesh for the target
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
		class UStaticMeshComponent* Mesh;

	// Box component for collision
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Mesh)
		class UBoxComponent* TargetCollision;

	// Text component for the number
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
		class UTextRenderComponent* NumberDisplay;

	// VARIABLES

	// Remember starting location for reset
	FVector StartingLocation;

	// Number 1-9 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Target)
		int32 Number;

	// The dice roll result will determine which targets are active for hitting
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Target)
		bool bIsActive;

	// Mark if the target has been hit when active
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Target)
		bool bIsHit;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void HitTarget();

	void Reset();

};
