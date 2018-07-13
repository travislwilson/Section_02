#pragma once
#include <string>

class FBullCowGame {
public:
	FBullCowGame(); // constructor
	
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); //TODO make a more rich return value.
	bool CheckGuessValidity(std::string);//TODO make a more rich return value.
	//provide a mehtod for counting bulls & cows and increasing turn #

// Please try and ignore this and focus above
private:
	// see constructor for initialisation
	int MyCurrentTry;
	int MyMaxTries;
};