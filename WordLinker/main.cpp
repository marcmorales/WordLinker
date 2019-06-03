#pragma once
#include <iostream>
#include <string>
#include "wordLinker.h"

/*Unreal Engine 4 compliant*/
using int32 = int;
using FText = std::string;
/*------------------------*/

void GameIntro();
void PlayGame(WordLink*);
void GameSummary(WordLink*);
bool bAskPlayAgain();

void PrintGameFeedback(EWordStatus, WordLink*);
void PrintStatAndAskNewWord(WordLink*);
FText AskNewWord();
void LogStatusBar(WordLink*);



int32 main()
{
	do
	{
		WordLink *pWordLink = new WordLink; // construct new game on initial and for every reset

		GameIntro();
		PlayGame(pWordLink);
		GameSummary(pWordLink);

		delete pWordLink;

	} while (bAskPlayAgain());

	return 0;
}

// Game's welcome introduction and gives instruction how to play the game
void GameIntro()
{
	std::cout << "     _ _ _ _____ _____ ____      __    _____ _____ _____ _____ _____     \n";
	std::cout << " ___| | | |     | __  |    \\ ___|  |  |     |   | |  |  |   __| __  |___ \n";
	std::cout << "|___| | | |  |  |    -|  |  |___|  |__|-   -| | | |    -|   __|    -|___|\n";
	std::cout << "    |_____|_____|__|__|____/    |_____|_____|_|___|__|__|_____|__|__|    \n\n";
	std::cout << "Welcome to Word Linker, a game where you connect words!" << std::endl;
	std::cout << "How to play:" << std::endl;
	std::cout << "- Take the last letter of the current word and use it as the first letter for the word you'll write." << std::endl;
	std::cout << "- Link words without repeating previously mentioned word as long as you can." << std::endl;
	std::cout << "- Each valid word give 10 points. 100+ points reward you with gold, 70+ is silver and 50+ grants you bronze." << std::endl;
	std::cout << "- You have 2 attempts if you entered an incorrect word." << std::endl;
	std::cout << "- IE: Used a word not starting with the proper letter and repeated a word." << std::endl << std::endl << std::endl;
	return;
}

// handles game loop, validation and feedback for each player input
void PlayGame(WordLink *pWordLink)
{
	
	do
	{
		PrintStatAndAskNewWord(pWordLink); // prints out player status
		
		EWordStatus WordStatus(pWordLink->CheckWordValidity());
		PrintGameFeedback(WordStatus, pWordLink);

	} while (pWordLink->GetAttempts() >= 0); // loop the game until attempt reaches 0.

	
}

void GameSummary(WordLink *pWordLink)
{
	// list all the words submitted
	std::cout << "List of words you entered:\n";
	for (int i(1); i <= pWordLink->GetWordListCount(); ++i)
	{
		std::cout << pWordLink->WordList[i];
		if (i >= pWordLink->GetWordListCount()) std::cout << '.';
		else std::cout << ", ";
	}
	std::cout << std::endl;

	// print total number of words submitted
	std::cout << "Total valid words submitted: " << pWordLink->GetWordListCount() << '\n';

	// print player points
	std::cout << "You're total points is: " << pWordLink->GetPlayerPoints() << '\n';

	// final congratulation message
	if (pWordLink->GetPlayerPoints() >= 50)
	{
		if (pWordLink->GetPlayerPoints() >= 70)
		{
			if (pWordLink->GetPlayerPoints() >= 100)
			{
				std::cout << "Gold winner!!!\n\n";
				return;
			} 
			std::cout << "Silver winner!!\n\n";
			return;
		}
		std::cout << "Bronze winner!\n\n";
	} 
}

bool bAskPlayAgain()
{
	std::cout << "Do you want to play again? (Y/N): ";
	FText PlayerResponse;
	std::getline(std::cin, PlayerResponse);
	int32 LwrCaseResponse(tolower(PlayerResponse[0]));

	if (LwrCaseResponse == 'Y' || LwrCaseResponse == 'y') return true;
	else if (LwrCaseResponse == 'N' || LwrCaseResponse == 'n') return false;
	else return false;
}

void PrintStatAndAskNewWord(WordLink *pWordLink)
{
	LogStatusBar(pWordLink);
	std::cout << "Current Word: " << pWordLink->GetCurrentWord() << " || New Word: ";

	pWordLink->SetNewWord(AskNewWord()); // Get Player input and set it as the New Word.
}

// Waits for Player's input for the new word.
FText AskNewWord()
{
	//set NewWord from player input.
	FText NewWord{" "};
	std::getline(std::cin, NewWord);
	return NewWord;
}

// Logs player's remaining attempts and # of words submitted
void LogStatusBar(WordLink *pWordLink)
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

void PrintGameFeedback(EWordStatus WordStatus, WordLink *pWordLink)
{
	switch (WordStatus)
	{
	case EWordStatus::InvalidLetter:
		std::cout << "You entered: " << pWordLink->GetNewWord() << ". Its first letter is invalid.\n";
		if (pWordLink->GetAttempts() > 0) std::cout << "Attempt -1.\n\n";

		pWordLink->SetReduceAttemptByOne();
		break;

	case EWordStatus::RepeatingWord:
		std::cout << "You entered: " << pWordLink->GetNewWord() << ". Its a repeated word.\n";
		if (pWordLink->GetAttempts() > 0) std::cout << "Attempt -1.\n\n";

		pWordLink->SetReduceAttemptByOne();
		break;

	case EWordStatus::Pending:
		std::cout << "You entered: " << pWordLink->GetNewWord() << ". Unrecognized input, please try again.(Pending still)\n\n";
		break;

	case EWordStatus::Valid:
		
		std::cout << "You entered: " << pWordLink->GetNewWord() << ". Nice!\n\n";
		pWordLink->SetPlayerPoint();
		pWordLink->SetNewWordToList(); // add new word to the list of words.
		pWordLink->SetCurrentWord(pWordLink->GetNewWord()); // sets the valid new word as the current word
		break;

	default:
		std::cout << "You entered: " << pWordLink->GetNewWord() << ". Unknown input, please try again.\n\n";
		break;
	}

	// Game Over ASCII ART
	if (pWordLink->GetAttempts() < 0)
	{
		std::cout << "  ___   __   _  _  ____     __   _  _  ____  ____ \n";
		std::cout << " / __) / _\\ ( \\/ )(  __)   /  \\ / )( \\(  __)(  _ \\\n";
		std::cout << "( (_ \\/    \\/ \\/ \\ ) _)   (  O )\\ \\/ / ) _)  )   /\n";
		std::cout << " \\___/\\_/\\_/\\_)(_/(____)   \\__/  \\__/ (____)(__\\_)\n\n";

	}
		
}