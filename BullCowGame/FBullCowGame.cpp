#include "FBullCowGame.h"

using FString = std::string; // set Unreal Namespace for strings
using int32 = int; // set Unreal Namespace for int

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return false; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "ant";
	
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false) // if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)// if the guess isn't all lowcase
	{
		return EGuessStatus::Not_Lowcase;
	} 
	else if (Guess.length() != GetHiddenWordLength()) // if the guess length is wrong
	{
		return EGuessStatus::Wrong_Length;
	}
	else 
	{
		return EGuessStatus::OK;
	}
	
		
	// otherwise
		// return OK
}

// receives a VALID guess, incriements turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// incriment the turn number
	MyCurrentTry++;

	// setup a return variable
	FBullCowCount BullCowCount;

	// loop through all letters in the guess
	int32 HiddenWordLenght = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLenght; MHWChar++) 
	{
		// compare letters against the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLenght; GChar++) 
		{
			// if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{
				// if they're in the same place
				if (MHWChar == GChar)
				{
					BullCowCount.Bulls++; //incriment bulls
				}
				else
				{
					BullCowCount.Cows++; // must be a cow
				}
			}
		}
	}
	return BullCowCount;
}

