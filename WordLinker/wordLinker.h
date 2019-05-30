#pragma once
#include <string>
#include <vector>

using int32 = int;
using FString = std::string;

class WordLink
{
public:
	WordLink();
	
	// =======================================
	// setters
	
	void SetNewWord(FString);
	void SetCurrentWord(FString);

	// =======================================
	// getters
	
	FString GetNewWord() const;
	FString GetCurrentWord() const;
	int32 GetAttempts() const;
	int32 GetWordSubmitCount() const;

	// check New Word's first letter if its equal to the current word's last letter.
	bool bFirstLtrCheck() const;
	void Reset(); // TODO reset the game when initialized and if the player chose to restart the game after winning or losing.


private:
	//FString SubmittedWordList[100];
	FString NewWord;
	FString CurrentWord;
	int32 Attempts;
	int32 PlayerPoints;
	int32 WordCount;

};
