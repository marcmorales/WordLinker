#include "wordLinker.h"

// Constructor
WordLink::WordLink() : NewWord(" "), CurrentWord("Ant"){}

// Setters
void WordLink::SetNewWord(std::string PlayerNewWord) { NewWord = PlayerNewWord; }

// Getters
std::string WordLink::GetNewWord() {	return NewWord; }
