#pragma once

#include<algorithm> 
#include<fstream> 
#include<iostream> 
#include<string> 
#include<vector> 

std::vector<std::string> getWordsInDictionaryFile(const std::string& dictFilename)
{
	std::ifstream fin(dictFilename);

	if (!fin)
	{
		std::cout << "FNFE\n";
		return{}; 
	}

	std::vector<std::string> words; 
	std::string currentWord; 

	while (std::getline(fin, currentWord))
	{
		words.push_back(currentWord);
	}

	return words; 

}