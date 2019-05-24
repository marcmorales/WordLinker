#include <iostream>
#include <string>

void GameIntro();
void PlayGame();

void LogStatAndAskNewWord();
void AskNewWord();
void LogStatusBar();

int main()
{
	GameIntro(); // TODO add some ASCII art

	// Run the game
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
	LogStatAndAskNewWord();
	return;
}

void LogStatAndAskNewWord()
{

	LogStatusBar();
	AskNewWord();
}

// Waits for Player's input for the new word.
void AskNewWord()
{
	std::cout << "Current Word: PLACEHOLDER || New Word: ";
	//set NewWord from player input.
	std::string NewWord = "";
	std::getline(std::cin, NewWord);
	
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
	constexpr int ATTEMPTS = 2; // place holders
	constexpr int WORDS_SUBMITTED = 5; // place holders

	//status bar
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "| Attempts: " << ATTEMPTS << " | # of Words Submitted: " << WORDS_SUBMITTED << " |" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	
}
