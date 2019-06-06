#pragma once
#include <cctype>
#include <vector>


using int32 = int;
using FString = std::string;

enum class EWordStatus
{
	Valid,
	InvalidLetter,
	RepeatingWord,
	NotInDictionary,
	Pending
};

struct WordLinkMarks
{
	WordLinkMarks();
	int32 PointPerValidWord;
	int32 AttemptsPerGame;
};

class WordLink
{
public:
	WordLink(); // main game constructor

	// =======================================
	// setters

	void SetNewWord(FString);
	void SetNewWordToList();
	void SetCurrentWord(FString);
	void SetReduceAttemptByOne();
	void SetPlayerPoint();

	// =======================================
	// getters

	WordLinkMarks GetWordLinkMarks() const;
	FString GetNewWord() const;
	FString GetCurrentWord() const;
	int32 GetAttempts() const;
	int32 GetWordListCount() const;
	int32 GetPlayerPoints() const;
	

	// ======================================
	// WordLink methods

	EWordStatus CheckWordValidity();

	// check New Word's first letter if its equal to the current word's last letter.
	bool bNewWordLetterValid() const;

	// verify if the New word is already on the list
	bool bCheckNewWordNotInList() const;

	void Reset();

	// =========================
	// Holds all the words submitted by the user including the initial word provided by the constructor
	std::vector <FString> WordList;


private:
	/* variables for all the words */
	FString NewWord;
	FString CurrentWord;
	
	// player status
	WordLinkMarks GamePoints;
	int32 Attempts;
	int32 PlayerPoints;
	int32 PointValue;

};


