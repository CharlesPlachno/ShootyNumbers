// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShootyNumbersGameMode.generated.h"

UCLASS(minimalapi)
class AShootyNumbersGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AShootyNumbersGameMode();

	// Game Status Variables

	// False when the game ends by win or loss, true when it is started
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GameStatus")
	bool bGameActive;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GameStatus")
	bool bCanRoll;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GameStatus")
	bool bPauseTargets;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GameStatus")
	bool bDidWin;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GameStatus")
	bool bWaitForRoll;

	// Bool Array to represent which Targets are hit. Game is won when all are true
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GameStatus")
	TArray<bool> TargetsUp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Dice)
	int32 DiceRoll1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Dice)
	int32 DiceRoll2;

	int32 DiceTotal;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Dice)
	int32 TurnTotal;

	// Game Functions

	UFUNCTION(BlueprintCallable)
		void StartGame();

	UFUNCTION(BlueprintCallable)
		void RollDice();

	void SetHitTarget(int32 TargetNumber);

	void Win();

	void Lose();

	void TurnOver();

	bool CheckAllTargets();
};



