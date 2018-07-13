/* This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interactions. For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();
FBullCowGame BCGame;// instantiate a new game

// the entry point for our application
int main()
{
	bool bPlayAgain = false;
	do {
		std::cout << std::endl;
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
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop for the number of turns asking for guesses
	// TODO change from FOR to WHILE loop
	for (int32 count = 1; count <= MaxTries; count++){
		FText Guess = GetGuess(); // TODO make loop checking valid
		
		// submit valid guess to the game
		// print number of bulls and cows
		
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
}

FText GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	// get guess from player
	FText Guess = "";
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)?\n";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y')|| (Response[0] == 'Y');
}

