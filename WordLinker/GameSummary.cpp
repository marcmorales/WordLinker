#pragma once
#include <iostream>
#include <string>
#include "wordLinker.h"

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


