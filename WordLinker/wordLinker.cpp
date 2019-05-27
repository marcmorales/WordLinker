#include "wordLinker.h"

// Constructor
WordLink::WordLink() : NewWord(" "), CurrentWord("Ant"){}

// Setters
void WordLink::SetNewWord(FString PlayerNewWord) { NewWord = PlayerNewWord; }

// Getters
FString WordLink::GetNewWord() { return NewWord; }
