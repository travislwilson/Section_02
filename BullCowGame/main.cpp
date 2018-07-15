/* This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interactions. For game logic see the FBullCowGame class.
*/

// main application included library
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string; // set Unreal Namespace for strings
using int32 = int; // set Unreal Namespace for int

// instantiate  application methods
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
FBullCowGame BCGame;// instantiate a new game

// the entry point for our application
int main()
{
	bool bPlayAgain = false;
	do 
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain);
	return 0; //exit application
}

// introduce the game
void PrintIntro()
{

	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n\n";
	return;
}

// game loop
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop asking for guesses while the game
	// is NOT won and there are still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) // TODO change from FOR to WHILE loop
	{ 
		FText Guess = GetValidGuess();

		// submit valid guess to the game and recieve counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		// print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
		std::cout << std::endl;
	}
}

// loop continually until the user give a valid guess
FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do 
	{
		// get guess from player
		int32 CurrentTry = BCGame.GetCurrentTry();
		
		std::cout << "Try " << CurrentTry << ". Enter your guess: ";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word with out repeating letters.\n";
			break;
		case EGuessStatus::Not_Lowcase:
			std::cout << "Please use all lowercase in you guess.\n";
			break;
		default:
			// assume guess is valid
			break;
		}
		std::cout << std::endl;
	} 
	while (Status != EGuessStatus::OK); // keep looping till we get valid input
	return Guess;
}

// Ask if the player is done playing
bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)?\n";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y')|| (Response[0] == 'Y');
}

