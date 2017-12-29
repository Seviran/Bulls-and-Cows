
#pragma once

#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame
{
	public:
	// Constructors
	FBullCowGame();
	// Getters
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	// Function
	void Reset();
	bool CheckGuessValidity(FString);
	// TODO Provide a method for counting bulls & cows, and incrementing turn number


	private:
	// See constructor for initialisation
	int32 MyCurrentTry;
	int32 MymaxTries;
};