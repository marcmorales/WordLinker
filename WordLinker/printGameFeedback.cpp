#pragma once
#include <iostream>
#include <string>
#include "wordLinker.h"

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

		std::cout << "You entered: " << pWordLink->GetNewWord() << ". Valid input but its an unrecognized word.\n\n";
		if (pWordLink->GetAttempts() > 0) std::cout << "Attempt -1.\n\n";
		pWordLink->SetReduceAttemptByOne();
		break;

	case EWordStatus::IsInDictionary:
		std::cout << "You entered: " << pWordLink->GetNewWord() << ". Nice!\n\n";
		pWordLink->SetPlayerPoint();
		pWordLink->SetNewWordToList(); // add new word to the list of words.
		pWordLink->SetCurrentWord(pWordLink->GetNewWord()); // sets the valid new word as the current word
		break;

	case EWordStatus::NotInDictionary:
		std::cout << "You entered: " << pWordLink->GetNewWord() << ". It's not in the dictionary.\n\n";
		if (pWordLink->GetAttempts() > 0) std::cout << "Attempt -1.\n\n";
		pWordLink->SetReduceAttemptByOne();
		break;

	default:
		// if game logic passes by the default pending enum value, this is the final catch all error. Should never be called
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
