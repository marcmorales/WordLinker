#pragma once
#include <iostream>
#include "wordLinker.h"

// Constructor
WordLink::WordLink() { Reset(); }

void WordLink::Reset()
{
	// Word related objects/variables
	NewWord = " ";
	CurrentWord = "ant"; // TODO. Pull a random word from a list of words
	WordList.push_back(CurrentWord); // initialize WordList with the current Word

	// Player status
	Attempts = 2;
	PlayerPoints = 0;
}

// Setters
void WordLink::SetNewWord(FString PlayerNewWord) { NewWord = PlayerNewWord; }
void WordLink::SetNewWordToList() { WordList.push_back(NewWord); }
void WordLink::SetCurrentWord(FString ValidPlayerNewWord) { CurrentWord = ValidPlayerNewWord; }

// Getters
FString WordLink::GetNewWord() const { return NewWord; }
FString WordLink::GetCurrentWord() const { return CurrentWord; }
int32 WordLink::GetAttempts() const { return Attempts; }
int32 WordLink::GetWordListCount() const { return WordList.size() - 1; } // -1 due to the initial word should not be counted


bool WordLink::bNewWordLetterValid() const
{
	// this statement returns true if the first letter of the new word and the last letter of current word matches
	// we need to -1 due to how array counts from 0. The .length() returns 3.
	if (tolower(NewWord[0]) == tolower(CurrentWord[CurrentWord.length() - 1])) return true;
	return false;
}

bool WordLink::bCheckNewWordNotInList() const
{
	size_t WordListSize{ WordList.size() }; 
	for (int32 i{ 0 }; i < WordListSize; ++i)
	{
		if (NewWord == WordList[i]) return false;
	}
	return true;
}
