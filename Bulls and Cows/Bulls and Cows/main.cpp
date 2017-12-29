
#include <iostream>
#include <string>

#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
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
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking off?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();

	int MaxTries = BCGame.GetMaxTries();

	// Loop for the number of turns asking for guesses
	// TODO Change from FOR to WHILE loop once we are validating tries
	for(int count = 0; count < MaxTries; count++)
	{
		std::string Guess = GetGuess();
		// TODO Make loop checking valid guess

		// Submit valid guess to the game
		// Print number of bulls and cows
		std::cout << "Your guess was: " << Guess;
		std::cout << std::endl;
	}

	// TODO Summarise game
}

// Get a guess from the player
std::string GetGuess()
{
	std::string Guess = "";
	int CurrentTry = BCGame.GetCurrentTry();

	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)?";
	std::string Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;
	char firstChar = Response[0];
	return ((firstChar == 'y') || (firstChar == 'Y'));
}
