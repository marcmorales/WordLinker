#pragma once
#include <iostream>
#include <string>
#include "wordLinker.h"

/*Unreal Engine 4 compliant*/
using int32 = int;
using FText = std::string;
/*------------------------*/

void GameIntro();
void PlayGame();

void PrintGameFeedback(EWordStatus);
void PrintStatAndAskNewWord();
FText AskNewWord();
void LogStatusBar();

WordLink WLink;

int32 main()
{
	GameIntro(); // TODO add some ASCII art
	PlayGame();

	// TODO Provide summary of the game

	// TODO Ask if the player wants to play the game again

	return 0;
}

// Game's welcome introduction and gives instruction how to play the game
void GameIntro()
{
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
void PlayGame()
{
	do
	{
		PrintStatAndAskNewWord(); // prints out player status
		
		EWordStatus WordStatus(WLink.CheckWordValidity());
		PrintGameFeedback(WordStatus);

	} while (WLink.GetAttempts() >= 0); // loop the game until attempt reaches 0.

}

void PrintStatAndAskNewWord()
{
	LogStatusBar();
	std::cout << "Current Word: " << WLink.GetCurrentWord() << " || New Word: ";

	WLink.SetNewWord(AskNewWord()); // Get Player input and set it as the New Word.
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
void LogStatusBar()
{
	// Introduce the word the player will start with.
	// Have a prominent status bar where the player can see how many attempts left and how many words they successfully submitted.
	// TODO Have a word tracker that shows the previous, current and next word.

	/* Should look like this:
	| Attempts: 2 | Words Submitted: ## |
	Current word: Null || Next word:
	*/

	//status bar
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "| Attempts: " << WLink.GetAttempts() << " | # of Words Submitted: " << WLink.GetWordListCount() << " |" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	
}

void PrintGameFeedback(EWordStatus WordStatus)
{
	switch (WordStatus)
	{
	case EWordStatus::InvalidLetter:
		std::cout << "You entered: " << WLink.GetNewWord() << ". Its first letter is invalid.\n";
		if (WLink.GetAttempts() > 0) std::cout << "Attempt -1.\n\n";

		WLink.SetReduceAttemptByOne();
		break;

	case EWordStatus::RepeatingWord:
		std::cout << "You entered: " << WLink.GetNewWord() << ". Its a repeated word.\n";
		if (WLink.GetAttempts() > 0) std::cout << "Attempt -1.\n\n";

		WLink.SetReduceAttemptByOne();
		break;

	case EWordStatus::Pending:
		std::cout << "You entered: " << WLink.GetNewWord() << ". Unrecognized input, please try again.(Pending still)\n\n";
		break;

	case EWordStatus::Valid:
		
		std::cout << "You entered: " << WLink.GetNewWord() << ". Nice!\n\n";
		WLink.SetPlayerPoint();
		WLink.SetNewWordToList(); // add new word to the list of words.
		WLink.SetCurrentWord(WLink.GetNewWord()); // sets the valid new word as the current word
		break;

	default:
		std::cout << "You entered: " << WLink.GetNewWord() << ". Unkown input, please try again.\n\n";
		break;
	}

	if (WLink.GetAttempts() < 0)
	{
		std::cout << "  ___   __   _  _  ____     __   _  _  ____  ____ \n";
		std::cout << " / __) / _\\ ( \\/ )(  __)   /  \\ / )( \\(  __)(  _ \\\n";
		std::cout << "( (_ \\/    \\/ \\/ \\ ) _)   (  O )\\ \\/ / ) _)  )   /\n";
		std::cout << " \\___/\\_/\\_/\\_)(_/(____)   \\__/  \\__/ (____)(__\\_)\n\n";

	}
		
}