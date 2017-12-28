
#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
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
	cout << "Welcome to Bulls and Cows, a fun word game\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking off?\n";
	cout << endl;
	return;
}

void PlayGame()
{
	// Loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for(int count = 0; count < NUMBER_OF_TURNS; count++)
	{
		string Guess = GetGuess();
		cout << endl;
	}
}

// Get a guess from the player
string GetGuess()
{
	string Guess = "";
	cout << "Enter your guess: ";
	getline(cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again (y/n)?";
	string Response = "";
	getline(cin, Response);
	cout << endl;
	char firstChar = Response[0];
	return ((firstChar == 'y') || (firstChar == 'Y'));
}
