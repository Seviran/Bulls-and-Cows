
#pragma once

#include <iostream>
#include "FBullCowGame.h"

#pragma region public

	#pragma region Constructor
		FBullCowGame::FBullCowGame()
		{
			Reset();
			return;
		}
	#pragma endregion

	#pragma region Getters
		int32 FBullCowGame::GetCurrentTry() const
		{
			return MyCurrentTry;
		}

		int32 FBullCowGame::GetHiddenWordLength() const
		{
			return MyHiddenWord.length();
		}

		int32 FBullCowGame::GetMaxTries() const
		{
			TMap<int32, int32> WordLengthToMaxTries =
			{
				{3, 4}, {4, 7}, {5, 10}, {6, 15}, {7, 20}
			};
			return WordLengthToMaxTries[MyHiddenWord.length()];
		}

		bool FBullCowGame::IsGameWon() const
		{
			return bGameIsWon;
		}
	#pragma endregion Getters

	#pragma region Functions
		EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
		{
			int32 GuessLength = Guess.length();
			if(!IsIsogram(Guess)) // If the guess isn't an isogram
			{
				return EGuessStatus::Not_Isogram;
			}
			else if(!IsLowercase(Guess)) // If the guess isn't all lowercase
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
			return;
		}

		// Receives a valid(!) guess, increments turn, and returns count
		FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
		{
			MyCurrentTry++;
			FBullCowCount BullCowCount;

			// Assuming same length as guess
			int32 WordLength = MyHiddenWord.length();

			// Loop through all letters in the hidden word
			for(int MHWChar = 0; MHWChar < WordLength; MHWChar++)
			{
				// Loop through all letters in the guess word
				for(int GChar = 0; GChar < WordLength; GChar++)
				{
					// If they match
					if(MyHiddenWord[MHWChar] == Guess[GChar])
					{
						if(MHWChar == GChar) // If they are in the same place
						{
							BullCowCount.Bulls++;
						}
						else // If they are not in the same placec
						{
							BullCowCount.Cows++;
						}
					}
				}
			}

			CheckGameWon(BullCowCount, WordLength);

			return BullCowCount;
		}

		void FBullCowGame::Reset()
		{
			constexpr int32 CURRENT_TRY = 1;
			const FString HIDDEN_WORD = "planet"; // This must(!) be an isogram

			MyHiddenWord = HIDDEN_WORD;
			MyCurrentTry = CURRENT_TRY;
			bGameIsWon = false;

			return;
		}

		void FBullCowGame::CheckGameWon(FBullCowCount BullCowCount, int32 WordLength)
		{
			if(BullCowCount.Bulls == WordLength)
			{
				bGameIsWon = true;
			}
			else
			{
				bGameIsWon = false;
			}
			return;
		}

	#pragma endregion

#pragma endregion

#pragma region private

	bool FBullCowGame::IsIsogram(FString Word) const
	{
		if(Word.length() <= 1)
		{
			return true;
		}

		TMap<char, bool> LetterSeen;

		for(auto Letter : Word)
		{
			Letter = tolower(Letter);
			if(LetterSeen[Letter])
			{
				return false;
			}
			LetterSeen[Letter] = true;
		}

		return true;
	}
	bool FBullCowGame::IsLowercase(FString Word) const
	{
		for(auto Letter : Word)
		{
			if(!islower(Letter)) // If not a lowercase letter
			{
				return false;
			}
		}
		return true;
	}
#pragma endregion
