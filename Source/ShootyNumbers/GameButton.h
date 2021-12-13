// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameButton.generated.h"

UCLASS()
class SHOOTYNUMBERS_API AGameButton : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameButton();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Mesh)
		class UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Mesh)
		class UBoxComponent* ButtonCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
		class UTextRenderComponent* ButtonLabel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
		bool bOverlapped;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
