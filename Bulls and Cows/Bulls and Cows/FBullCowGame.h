
/*
	The game logic (no view code or direct user interaction)
	The game is a simple guess the word game based on Mastermind
*/

#pragma once

#include <string>
#include <map>

// To make syntax Unreal friendly
#define TMap std::map
using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame
{
	#pragma region public
	public:

		#pragma region Constructor
			FBullCowGame();
		#pragma endregion


		#pragma region Getters
			int32 GetCurrentTry() const;
			int32 GetHiddenWordLength() const;
			int32 GetMaxTries() const;
			bool IsGameWon() const;
		#pragma endregion

		#pragma region Functions
			EGuessStatus CheckGuessValidity(FString) const;
			FBullCowCount SubmitValidGuess(FString);
			void Reset();
			void CheckGameWon(FBullCowCount, int32);
		#pragma endregion

	#pragma endregion

	#pragma region private
	private:
		#pragma region Variables
			int32 MyCurrentTry;
			FString MyHiddenWord;
			bool bGameIsWon;
		#pragma endregion

		#pragma region Functions
			bool IsIsogram(FString) const;
			bool IsLowercase(FString) const;
		#pragma endregion

	#pragma endregion

	
};