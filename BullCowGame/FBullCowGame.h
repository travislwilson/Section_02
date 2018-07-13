#pragma once
#include <string>

class FBullCowGame {
public:
	
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	
	bool CheckGuessValidity(std::string);//TODO make a more rich return value.
	void Reset(); //TODO make a more rich return value.

// Please try and ignore this and focus above
private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
};