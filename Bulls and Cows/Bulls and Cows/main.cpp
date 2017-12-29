
/*
	This is the console executable, that makes use of the BullCow class.
	This acts as the view in the MVC pattern, and is responsible for all user interaction. For game logic, see the FBullCowGame class
*/

#include <iostream>
#include <string>

#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // Instantiate a new game

// The entry point for our application
int main()
{
	do
	{
		PrintIntro();
		PlayGame();
	}
	while(AskToPlayAgain());

	// Exits the application
	return 0;
}

// Introduce the game
void PrintIntro()
{
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking off?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();

	// Loop for the number of turns asking for guesses
	// TODO Change from FOR to WHILE loop once we are validating tries
	for(int32 count = 0; count < MaxTries; count++)
	{
		FText Guess = GetGuess();
		// TODO Make loop checking valid guess

		// Submit valid guess to the game
		// Print number of bulls and cows
		std::cout << "Your guess was: " << Guess;
		std::cout << std::endl;
	}

	// TODO Summarise game
}

// Get a guess from the player
FText GetGuess()
{
	FText Guess = "";
	int32 CurrentTry = BCGame.GetCurrentTry();

	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)?";
	FText Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;
	char firstChar = Response[0];
	return ((firstChar == 'y') || (firstChar == 'Y'));
}
