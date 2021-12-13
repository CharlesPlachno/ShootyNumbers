// Fill out your copyright notice in the Description page of Project Settings.


#include "GameButton.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AGameButton::AGameButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	ButtonCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("ButtonCollision"));
	ButtonLabel = CreateDefaultSubobject<UTextRenderComponent>(TEXT("NumberDisplay"));

	// Setup scene hierarchy
	Mesh->SetupAttachment(GetRootComponent());
	ButtonCollision->SetupAttachment(Mesh);
	ButtonLabel->SetupAttachment(Mesh);

	bOverlapped = false;
}

// Called when the game starts or when spawned
void AGameButton::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

