#pragma once
#include "dictionary.h"

WordLinkDictionary::MITDictionary::MITDictionary()
{
	this->doOpenMitDictionary();
}
void WordLinkDictionary::MITDictionary::doOpenMitDictionary()
{
	this->dictionary.open("mit_edu_ecprice_wordlist_10000.txt");

	if (this->dictionary.fail()) // if the file cannot be opened/located
	{
		std::cerr << "!! There is an error locating/opening the dictionary file !!\n";
		this->doCloseMitDictionary();

		return;
	}

	if (this->dictionary.is_open())
	{
		std::cout << "Dictionary reporting for duty!\n";
		return;
	}
}
void WordLinkDictionary::MITDictionary::doCloseMitDictionary()
{
	this->dictionary.close();
	return;
}

bool WordLinkDictionary::MITDictionary::bVerifyWordInDictionary()
{
	int32 count(0);
	while (!(this->dictionary.eof()))
	{
		++count;
		dictionary >> wordFromDictionary;
		std::cout << wordFromDictionary << '\n';
	}
	
	return false;
}
