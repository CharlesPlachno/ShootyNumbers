// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShootyNumbersGameMode.h"
#include "ShootyNumbersHUD.h"
#include "ShootyNumbersCharacter.h"
#include "UObject/ConstructorHelpers.h"

AShootyNumbersGameMode::AShootyNumbersGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AShootyNumbersHUD::StaticClass();

	bWaitForRoll = false;
	bGameActive = false;
	bCanRoll = false;
	bPauseTargets = true;
	bDidWin = false;
	DiceRoll1 = 0;
	DiceRoll2 = 0;
	DiceTotal = 0;
	TurnTotal = 0;
	TargetsUp.Init(true, 9);
}

void AShootyNumbersGameMode::StartGame()
{
	bDidWin = false;
	bGameActive = true;
	bCanRoll = true;
	TargetsUp.Init(false, 9);
	bPauseTargets = false;
	DiceRoll1 = 0;
	DiceRoll2 = 0;
	DiceTotal = 0;
	TurnTotal = 0;
	bWaitForRoll = true;
}

void AShootyNumbersGameMode::RollDice()
{
	if (!bGameActive) {
		StartGame();
	}
	if (bCanRoll)
	{
		bPauseTargets = false;
		bWaitForRoll = false;
		DiceRoll1 = FMath::RandRange(1, 6);
		DiceRoll2 = FMath::RandRange(1, 6);

		// Figure out which targets should be available
		DiceTotal = DiceRoll1 + DiceRoll2;
		TurnTotal = 0;
		bCanRoll = false;
	}

}


// Given a target number, set the corresponding value in targets array to true
void AShootyNumbersGameMode::SetHitTarget(int32 TargetNumber)
{
	int32 Index = TargetNumber - 1;
	// Check if this target has already been hit
	if (!bPauseTargets) 
	{
		if (!TargetsUp[Index])
		{
			// If not, set it to true
			TargetsUp[Index] = true;
			UE_LOG(LogTemp, Warning, TEXT("Target hit"));

			// Add Target Number to turn total
			TurnTotal += TargetNumber;

			// Check if hit this turn target value is equal or over total
			if (TurnTotal == DiceTotal)
			{
				TurnOver();
			}
			else if (TurnTotal > DiceTotal)
			{
				Lose();
			}
		}
	}
}
void AShootyNumbersGameMode::Win()
{
	bWaitForRoll = false;
	bDidWin = true;
	bPauseTargets = true;
	bCanRoll = false;
	bGameActive = false;
}

void AShootyNumbersGameMode::Lose()
{
	bPauseTargets = true;
	bCanRoll = false;
	bGameActive = false;
}

void AShootyNumbersGameMode::TurnOver()
{
	bWaitForRoll = true;
	bPauseTargets = true;
	bCanRoll = true;
	// Check if Game Won
	if (CheckAllTargets())
	{
		Win();
	}
}

bool AShootyNumbersGameMode::CheckAllTargets()
{
	for (bool TargetState : TargetsUp)
	{
		if (!TargetState)
		{
			return false;
		}
	}
	return true;
}

bool AShootyNumbersGameMode::GetTargetStatus(int32 TargetNumber)
{
	return TargetsUp[TargetNumber - 1];
}