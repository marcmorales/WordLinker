#pragma once
#include <string>
#include <vector>

using int32 = int;
using FString = std::string;

enum class EWordStatus
{
	Valid,
	InvalidLetter,
	RepeatingWord,
	Pending
};

class WordLink
{
public:
	WordLink();
	
	// =======================================
	// setters
	
	void SetNewWord(FString);
	void SetNewWordToList();
	void SetCurrentWord(FString);
	void SetReduceAttemptByOne();

	// =======================================
	// getters
	
	FString GetNewWord() const;
	FString GetCurrentWord() const;
	int32 GetAttempts() const;
	int32 GetWordListCount() const;

	// ======================================
	// WordLink methods
	
	EWordStatus CheckWordValidity();

	// check New Word's first letter if its equal to the current word's last letter.
	bool bNewWordLetterValid() const;

	// verify if the New word is already on the list
	bool bCheckNewWordNotInList() const;
	
	void Reset(); // TODO reset the game when initialized and if the player chose to restart the game after winning or losing.


private:
	// variables for all the words
	FString NewWord;
	FString CurrentWord;
	std::vector <FString> WordList;

	// player status
	int32 Attempts;
	int32 PlayerPoints;
	
	


};
