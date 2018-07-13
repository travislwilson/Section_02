#include <iostream>;
#include <string>;

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
string RepeatGuess();

// game varibles
string Guess = "";

// the entry point for our application
int main()
{
	PrintIntro();
	PlayGame();
	return 0;
}

// introduce the game
void PrintIntro()
{
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
	cout << endl;
	return;
}

// play the game logic
void PlayGame()
{
	// loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		GetGuess();
		RepeatGuess();
		cout << endl;
	}
}

string GetGuess()
{
	// get guess from player
	cout << "Enter your guess: ";
	getline(cin, Guess);
	return Guess;
}

string RepeatGuess()
{
	// repeat guess back to player
	cout << "You enterd: " << Guess;
	cout << endl;
	return Guess;
}
