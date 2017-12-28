
#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();

// The entry point for our application
int main()
{
    PrintIntro();

    // Loop for the number of turns asking for guesses
    constexpr int NUMBER_OF_TURNS = 5;
    for (int count = 0; count < NUMBER_OF_TURNS; count++)
    {
        GetGuessAndPrintBack();
        std::cout << std::endl;
    }

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

// Get a guess from the player
string GetGuessAndPrintBack()
{
    std::string Guess = "";
    std::cout << "Enter your guess: ";
    std::getline(std::cin, Guess);
    std::cout << "Your guess was: " << Guess << endl;
    return Guess;
}
