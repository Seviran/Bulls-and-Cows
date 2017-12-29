
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
FText GetValidGuess();
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
	std::cout << "Welcome to Bulls and Cows, a fun word game\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking off?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();

	// TODO Change from FOR to WHILE loop once we are validating tries
	for(int32 count = 0; count < MaxTries; count++)
	{
		FText Guess = GetValidGuess();

		// Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}

	// TODO Summarise game
}

// Loop continually until the user gives a valid guess
FText GetValidGuess() // TODO Change to GetValidGuess
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;

	do
	{
		FText Guess = "";
		int32 CurrentTry = BCGame.GetCurrentTry();

		std::cout << "Try " << CurrentTry << ". Enter your guess: ";
		std::getline(std::cin, Guess);

		Status = CheckStatus(Status, Guess);


		Status = BCGame.CheckGuessValidity(Guess);

		switch(Status)
		{
			case EGuessStatus::Not_Isogram:
				std::cout << "Please enter a word without repeating letters.\n";
				break;
			case EGuessStatus::Not_Lowercase:
				std::cout << "Please enter all lowercase letters\n";
				break;
			case EGuessStatus::Wrong_Length:
				std::cout << "Please enter a "
					<< BCGame.GetHiddenWordLength()
					<< " letter word.\n";
				break;
			default:
				return Guess;
		}
		std::cout << std::endl;
	}
	while(Status != EGuessStatus::OK);
}

EGuessStatus CheckStatus(EGuessStatus Status, FText Guess)
{

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
