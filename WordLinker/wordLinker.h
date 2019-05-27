#pragma once
#include <string>
#include <vector>

class WordLink
{
public:
	WordLink();
	
	// setters
	void SetNewWord(std::string);
	void SetCurrentWord(std::string);

	// getters
	std::string GetNewWord();
	void GetCurrentWord(std::string);

	void Reset(); // TODO reset the game when initialized and if the player chose to restart the game after winning or losing.


private:
	std::string NewWord;
	std::string CurrentWord;
};
