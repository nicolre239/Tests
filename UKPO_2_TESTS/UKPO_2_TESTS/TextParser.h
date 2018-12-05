#include <string>
#include <vector>
#include "../../UKPO_2/UKPO_2/Unit.h"
#pragma once
class TextParser
{
public:
	std::string findText;
	int answer;
	std::string fullText;

	TextParser (std::string findTextInput, std::string fullTextInput);
	bool CheckRightShift (int a, int b);
	int findInVec (std::vector<int> vec, int a);
	bool CheckAllUsed (std::vector<std::vector<int>> posVector, std::vector<int> comboVector);
	int Combine (std::vector<Unit*> vecUnit, std::vector<std::vector<int>> posVector, std::vector<int> comboVector, int i, int j);
	std::vector<std::vector<int>> findAll (std::vector<Unit*> vecUnit);
	std::vector <Unit*> toUnits (std::vector<std::string> cutString);
	std::vector<std::string> cutString ();
	int findPart (std::string fText, int startPos);
};

