#pragma once
#include <string>
#include <vector>

using int32 = int;
using FString = std::string;

class WordLink
{
public:
	WordLink();
	
	// setters
	void SetNewWord(FString);
	void SetCurrentWord(FString);

	// getters
	FString GetNewWord();
	void GetCurrentWord(FString);

	void Reset(); // TODO reset the game when initialized and if the player chose to restart the game after winning or losing.


private:
	FString NewWord;
	FString CurrentWord;

};
