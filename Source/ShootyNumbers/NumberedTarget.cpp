// Fill out your copyright notice in the Description page of Project Settings.


#include "NumberedTarget.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ShootyNumbersGameMode.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ANumberedTarget::ANumberedTarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Create default subobjects
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	TargetCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("TargetCollision"));
	NumberDisplay = CreateDefaultSubobject<UTextRenderComponent>(TEXT("NumberDisplay"));

	// Setup scene hierarchy
	Mesh->SetupAttachment(GetRootComponent());
	TargetCollision->SetupAttachment(Mesh);
	NumberDisplay->SetupAttachment(Mesh);

	// Initialize Variables

	StartingLocation = GetActorLocation();
	Number = 0;
	bIsActive = false;
	bIsHit = false;
}

// Called when the game starts or when spawned
void ANumberedTarget::BeginPlay()
{
	Super::BeginPlay();
	bIsActive = true;
}

// Called every frame
void ANumberedTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANumberedTarget::HitTarget()
{
	if (bIsActive)
	{
		bIsHit = true;
		AShootyNumbersGameMode* MyGameMode = Cast<AShootyNumbersGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
		if (MyGameMode)
		{
			// Tell game mode we were hit
			MyGameMode->SetHitTarget(Number);
			bIsActive = false;
		}

	}
}
void ANumberedTarget::Reset()
{
	SetActorLocation(StartingLocation);
	bIsActive = true;
	bIsHit = false;
}

