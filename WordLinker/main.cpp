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
void PrintStatusBar(WordLink*);

int32 main()
{
	do
	{
		WordLink *pWordLink(new WordLink); // construct new game on initial and for every reset

		GameIntro();
		PlayGame(pWordLink);
		GameSummary(pWordLink);

		delete pWordLink;
		pWordLink = nullptr;

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
		PrintStatAndAskNewWord(pWordLink); // TODO separate two action into two different functions
		
		EWordStatus WordStatus(pWordLink->CheckWordValidity());
		PrintGameFeedback(WordStatus, pWordLink);

	} while (pWordLink->GetAttempts() >= 0); // loop the game until attempt reaches 0.
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
	PrintStatusBar(pWordLink);
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