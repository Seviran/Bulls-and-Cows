
/*
	This is the console executable, that makes use of the BullCow class.
	This acts as the view in the MVC pattern, and is responsible for all user interaction. For game logic, see the FBullCowGame class
*/

#pragma once

#include <iostream>
#include <string>

#include "FBullCowGame.h"

// To make syntax Unreal friendly
using FText = std::string;
using int32 = int;

// Function prototypes as outside a class
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
EGuessStatus CheckStatus(EGuessStatus Status);
void PrintGameSummary();

// Instantiate a new game, which we re-use across plays
FBullCowGame BCGame; 

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

void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << std::endl;
	std::cout << "          }   {         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |-,--- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

// Plays a single game to completion
void PlayGame()
{
	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();

	// Loop asking for guesses while the game is not(!) won
	// and there are still tries remaining
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();

		// Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}

	PrintGameSummary();
	return;
}

// Loop continually until the user gives a valid guess
FText GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess = "";
	do
	{
		int32 CurrentTry = BCGame.GetCurrentTry();

		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries();
		std::cout << ". Enter your guess: ";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);

		Status = CheckStatus(Status);
		
	}
	while(Status != EGuessStatus::OK);
	return Guess;
}

// Checks the status of the guess given by the player
EGuessStatus CheckStatus(EGuessStatus Status)
{
	switch(Status)
	{
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n\n";
			Status = EGuessStatus::Not_Isogram;
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters\n\n";
			Status = EGuessStatus::Not_Lowercase;
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a "
				<< BCGame.GetHiddenWordLength()
				<< " letter word.\n\n";
			Status = EGuessStatus::Wrong_Length;
			break;
		default:
			Status = EGuessStatus::OK;
	}

	return Status;
}

void PrintGameSummary()
{
	if(BCGame.IsGameWon())
	{
		std::cout << "Well done! - You win!\n";
	}
	else
	{
		std::cout << "Better luck next time!\n";
	}
	return;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same hidden word (y/n)?";
	FText Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;
	char firstChar = Response[0];
	return ((firstChar == 'y') || (firstChar == 'Y'));
}
