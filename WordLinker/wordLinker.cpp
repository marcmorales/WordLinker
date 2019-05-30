#pragma once
#include <cctype>
#include <iostream>
#include <cstring>
#include <cstdio>
#include "wordLinker.h"

// Constructor
WordLink::WordLink() : 
	NewWord(" "), 
	CurrentWord("Ant"), // TODO create an array of words and randomize initial word
	Attempts(2), 
	PlayerPoints(0) 
{}

// Setters
void WordLink::SetNewWord(FString PlayerNewWord) { NewWord = PlayerNewWord; }

// Getters
FString WordLink::GetNewWord() const { return NewWord; }
FString WordLink::GetCurrentWord() const { return CurrentWord; }
int32 WordLink::GetAttempts() const { return Attempts; }
int32 WordLink::GetWordSubmitCount() const { return PlayerPoints; }


bool WordLink::bFirstLtrCheck() const
{
	// this statement returns true if the first letter of the new word and the last letter of current word matches
	// we need to -1 due to how array counts from 0. The .length() returns 3.
	if (tolower(NewWord[0]) == tolower(CurrentWord[CurrentWord.length() - 1])) return true;
	return false;
}

