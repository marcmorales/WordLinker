#pragma once
#include <iostream>
#include <string>
#include "wordLinker.h"

// Logs player's remaining attempts and # of words submitted
void PrintStatusBar(WordLink *pWordLink)
{
	// Introduce the word the player will start with.
	// Have a prominent status bar where the player can see how many attempts left and how many words they successfully submitted.

	/* Should look like this:
	| Attempts: 2 | Words Submitted: ## |
	Current word: Null || Next word:
	*/

	//status bar
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "| Attempts: " << pWordLink->GetAttempts() << " | # of Words Submitted: " << pWordLink->GetWordListCount() << " |" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	
}