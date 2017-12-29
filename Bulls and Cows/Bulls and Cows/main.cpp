
#include <iostream>
#include <string>

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

// The entry point for our application
int main()
{
	PrintIntro();

	do
	{
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
	// Loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for(int count = 0; count < NUMBER_OF_TURNS; count++)
	{
		std::string Guess = GetGuess();
		std::cout << std::endl;
	}
}

// Get a guess from the player
std::string GetGuess()
{
	std::string Guess = "";
	std::cout << "Enter your guess: ";
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
