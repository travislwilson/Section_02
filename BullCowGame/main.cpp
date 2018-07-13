#include <iostream>;
#include <string>;

using namespace std;

int main()
{
	constexpr int WORD_LENGTH = 5;
	
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
	cout << endl;

	// get a guess from a player
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin,Guess);

	//repeat the guess back to them
	cout << "You enterd " << Guess;
	cout << endl;

	return 0;
}