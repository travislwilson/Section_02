#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	MyCurrentTry = 1;
	
	return;
}

bool FBullCowGame::IsGameWon() const { return false; }


bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}

// receives a VALID guess, incriements turn, and returns count
BullCowCount FBullCowGame::SubmitGuess(FString)
{
	// incriment the turn number
	// setup a return variable
	// loop through all letters in the guess
		// compare letters against the hidden word

	return BullCowCount();
}

