#include <iostream>;
#include <string>;

using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();


// the entry point for our application
int main()
{
	PrintIntro();
	
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		GetGuessAndPrintBack();
		cout << endl;
	}


	cout << endl;
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

// get guess from player
string GetGuessAndPrintBack()
{
	string Guess = "";
	cout << "Enter your guess: ";
	getline(cin, Guess);
	
	//repeat the guess back to them
	cout << "You enterd: " << Guess;
	cout << endl;
	
	return Guess;
}

