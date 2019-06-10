#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "wordLinker.h"

using FString = std::string;
using int32 = int;

namespace WordLinkDictionary
{
	class MITDictionary
	{
	public:
		MITDictionary(); // default constructor
		void doOpenMitDictionary();
		void doCloseMitDictionary();

		bool bVerifyWordInDictionary(WordLink*);

	private:
		std::ifstream dictionary;
		FString wordFromDictionary;
	};
}

