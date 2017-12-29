
#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const
{
	return MymaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

void FBullCowGame::Reset()
{
	constexpr int32 CURRENT_TRY = 1;
	MyCurrentTry = CURRENT_TRY;

	constexpr int32 MAX_TRIES = 5;
	MymaxTries = MAX_TRIES;

	return;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

