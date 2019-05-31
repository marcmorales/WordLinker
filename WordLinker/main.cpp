#include <iostream>
#include <string>
#include "wordLinker.h"

using int32 = int;
using FText = std::string;

void GameIntro();
void PlayGame();

void LogStatAndAskNewWord();
FText AskNewWord();
void LogStatusBar();
bool bValidateNewWord();

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

void PlayGame()
{
	do
	{
		LogStatAndAskNewWord();
		if (bValidateNewWord())
		{
			
			std::cout << "You entered: " << WLink.GetNewWord() << ". + 5 points.\n\n";
			WLink.SetNewWordToList(); // add new word to the list of words.
			WLink.SetCurrentWord(WLink.GetNewWord()); // sets the valid new word as the current word
		}
		else
		{
			// TODO * if not valid, check player stat
			WLink.SetReduceAttemptByOne(); // reduces remaining attempt by 1.
			std::cout << "The word: " << WLink.GetNewWord() << " is NOT valid.\n";
			std::cout << "Attempt reduced by 1.\n\n";

			// TODO if player still has enough attempt, Log the stat and ask player for another word*
			// TODO if player exhausted all attempts, run the game's game over function (still to be made).
		}
	} while (WLink.GetAttempts() >= 0); // temp

}

void LogStatAndAskNewWord()
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

bool bValidateNewWord()
{
	if (WLink.bNewWordLetterValid()) // check if NewWord's 1st letter == to CurrentWord last letter
	{
		if (WLink.bCheckNewWordNotInList()) // check repeating word
		{
			return true;
		}
	}
	return false; // if one of the check didnt run, either letter is invalid or is a repeated word.
}
