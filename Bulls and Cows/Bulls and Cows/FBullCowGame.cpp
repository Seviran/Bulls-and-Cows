
#include <iostream>
#include "FBullCowGame.h"

#pragma region Constructor
FBullCowGame::FBullCowGame()
{
	Reset();
}
#pragma endregion

#pragma region Getters
int32 FBullCowGame::GetMaxTries() const
{
	return MymaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}
#pragma endregion

#pragma region Functions
EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	int32 GuessLength = Guess.length();
	if(false) // If the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if(false) // If the guess isn't all lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if(GuessLength != GetHiddenWordLength()) // if the guess length is wrong
	{
		return EGuessStatus::Wrong_Length;
	}
	else // Otherwise
	{
		return EGuessStatus::OK;
	}
}

void FBullCowGame::Reset()
{
	constexpr int32 CURRENT_TRY = 1;
	constexpr int32 MAX_TRIES = 5;
	const FString HIDDEN_WORD = "planet";

	MyCurrentTry = CURRENT_TRY;
	MymaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;

	return;
}

// Receives a valid guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// Increment the turn number
	MyCurrentTry++;
	// Setup a return variable
	FBullCowCount BullCowCount;

	int32 HiddenWordLength = MyHiddenWord.length();
	int32 GuessLength = Guess.length();
	for(int MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
	{
		for(int GChar = 0; GChar < HiddenWordLength; GChar++)
		{
			if(MyHiddenWord[MHWChar] == Guess[GChar])
			{
				if(MHWChar == GChar)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
		}
	}

	return BullCowCount;
}
#pragma endregion
