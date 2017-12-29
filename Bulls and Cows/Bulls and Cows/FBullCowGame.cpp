
#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

int FBullCowGame::GetMaxTries() const
{
	return MymaxTries;
}

int FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

void FBullCowGame::Reset()
{
	constexpr int CURRENT_TRY = 1;
	MyCurrentTry = CURRENT_TRY;

	constexpr int MAX_TRIES = 5;
	MymaxTries = MAX_TRIES;

	return;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}

