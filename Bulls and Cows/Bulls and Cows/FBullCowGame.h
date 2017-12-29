
#pragma once

#include <string>

class FBullCowGame
{
	public:
	// Constructors
	FBullCowGame();
	// Getters
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	// Function
	void Reset();
	bool CheckGuessValidity(std::string);
	// TODO Provide a method for counting bulls & cows, and incrementing turn number


	private:
	// See constructor for initialisation
	int MyCurrentTry;
	int MymaxTries;
};