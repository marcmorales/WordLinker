#pragma once
#include "wordLinker.h"

// Values Given Per Game
WordLinkMarks::WordLinkMarks() :
	AttemptsPerGame(2),
	PointPerValidWord(10)
{}

// Main Game Constructor
WordLink::WordLink() { Reset(); }

void WordLink::Reset() // TODO * Fix reset, not reseting total number of words submitted, need to clean up vector for word list as well
{
	// Word related objects/variables
	NewWord = " ";
	CurrentWord = "ant"; // TODO. Pull a random word from a list of words
	WordList.push_back(CurrentWord); // initialize WordList with the current Word

	// Player status
	Attempts = GamePoints.AttemptsPerGame;
	PlayerPoints = 0;
	PointValue = GamePoints.PointPerValidWord;
}

// Setters
void WordLink::SetNewWord(FString PlayerNewWord) { NewWord = PlayerNewWord; }
void WordLink::SetNewWordToList() { WordList.push_back(NewWord); }
void WordLink::SetCurrentWord(FString ValidPlayerNewWord) { CurrentWord = ValidPlayerNewWord; }
void WordLink::SetReduceAttemptByOne() { --Attempts; }
void WordLink::SetPlayerPoint() { PlayerPoints += PointValue; }

// Getters
WordLinkMarks WordLink::GetWordLinkMarks() const { return GamePoints;  }
FString WordLink::GetNewWord() const { return NewWord; }
FString WordLink::GetCurrentWord() const { return CurrentWord; }
int32 WordLink::GetAttempts() const { return Attempts; }
int32 WordLink::GetWordListCount() const { return WordList.size() - 1; } // -1 due to the initial word should not be counted
int32 WordLink::GetPlayerPoints() const { return PlayerPoints;  }

EWordStatus WordLink::CheckWordValidity()
{
	if (bNewWordLetterValid()) // check if NewWord's 1st letter == to CurrentWord last letter
	{
		// if letter is good
		if (bCheckNewWordNotInList()) // check repeating word
		{
			// if not in list
			return EWordStatus::Valid;
		}
		return EWordStatus::RepeatingWord;
	}
	return EWordStatus::InvalidLetter;
}
bool WordLink::bNewWordLetterValid() const
{
	// this statement returns true if the first letter of the new word and the last letter of current word matches
	// we need to -1 due to how array counts from 0. The .length() returns 3.
	if (tolower(NewWord[0]) == tolower(CurrentWord[CurrentWord.length() - 1])) return true;
	return false;
}
bool WordLink::bCheckNewWordNotInList() const
{
	int32 WordListSize(WordList.size()) ; 
	for (int32 i{ 0 }; i < WordListSize; ++i)
	{
		if (NewWord == WordList[i]) return false;
	}
	return true;
}
