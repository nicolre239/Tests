#include "stdafx.h"
#include "stdio.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "TextParser.h"
#include "../../UKPO_2/UKPO_2/Unit.h"

TextParser::TextParser (std::string findText, std::string fullText)
{
	this -> answer = -1;
	this -> findText = findText;
	this -> fullText = fullText;
};


int TextParser::findPart (std::string fText, int startPos)
{
	std::ifstream fileIn;
	fileIn.open("input.txt");
	
	std::string redfText;
	redfText = fText;

	std::string Text = "";
	std::string temp = "";
	
	Text = this -> fullText;

	unsigned int i = startPos, j = 0, strNum = 0;

	while (1)
	{
		if (i + redfText.length() - j > Text.length())
		{
			//std::cout << "Nothing found" << std::endl;
			return -1;
		}

		if (redfText[j] == Text[i])
		{
			j++;
			i++;

			if (j == redfText.length())
			{
				//std::cout << "answer >> " << i - redfText.length() + 1 << " << answer" <<std::endl;
				return i - redfText.length() + 1;
			}
		}

		else 
		{
			i ++;
			j = 0;
		}

	}

	fileIn.close();

	return 0;
};


bool TextParser::CheckRightShift (int a, int b)
{
	std::ifstream fileIn;
	fileIn.open("input.txt");

	std::string Text= "";
	std::string temp= "";

	Text = this -> fullText;

	if (a + b <= Text.length())
		return 1;

	return 0;
};

int TextParser::findInVec (std::vector<int> vec, int a)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == a)
			return i;
	}

	return -1;
};

bool TextParser::CheckAllUsed (std::vector<std::vector<int>> posVector, std::vector<int> comboVector)
{
	for (int i = 0; i < comboVector.size(); i++)
	{
		if (findInVec(posVector[i], comboVector[i]) != posVector[i].size() - 1)
			return 0;
	}

	return 1;
};


int TextParser::Combine (std::vector<Unit*> vecUnit, std::vector<std::vector<int>> posVector, std::vector<int> comboVector, int i, int j)
{

	int leftShift;
	if (i == 0)
		leftShift = posVector[i][j] - 1;
	else
		leftShift = posVector[i][j] - comboVector [i - 1] - vecUnit[i-1] -> getPart().length();

	std::string trueLeftShift = vecUnit[i] -> getLeftShift();

	if ((trueLeftShift == "1" && leftShift == 1) || (trueLeftShift == "1+" && leftShift >= 1) || (trueLeftShift == "0+" && leftShift >= 0) || trueLeftShift == "")
	{
		comboVector.push_back(posVector[i][j]);
		i++;
		
		if (i == vecUnit.size())
		{
			if ((vecUnit[i-1] -> getRightShift() == "") || (vecUnit[i-1] -> getRightShift() == "0+") || (((vecUnit[i-1] -> getRightShift() == "1") || (vecUnit[i-1] -> getRightShift() == "1+")) && CheckRightShift(comboVector[i-1], vecUnit[i-1] -> getPart().length())))
				{
					std::cout << "last answer >>" << comboVector[0] << "<< last answer" << std::endl;
					this -> answer = comboVector[0];
				}
			else
				std::cout << "404, combination not found" << std::endl;

			return -1;
		}
		
		else
		{
			j = 0;
			Combine(vecUnit, posVector, comboVector, i, j);
		}
	}
	else
	{
		if (j == posVector[i].size() - 1)
		{
			if (CheckAllUsed(posVector, comboVector))
			{
				std::cout << "404, combination not found" << std::endl;
				return -1;
			}
			j = findInVec(posVector[i-1], comboVector[comboVector.size()-1]) + 1;
			comboVector.pop_back();
			i--;
			Combine(vecUnit, posVector, comboVector, i, j);
		}
		else
		{
			j++;
			Combine(vecUnit, posVector, comboVector, i, j);
		}
	}

	return -1;
};

std::vector<std::vector<int>> TextParser::findAll (std::vector<Unit*> vecUnit)
{
	std::vector<std::vector<int>> posVector(0);
	std::vector<int> temp(0);
	std::vector<int> comboVector(0);

	int j = 0;

	for (int i = 0; i < vecUnit.size(); i++)
	{
		while (findPart(vecUnit[i] -> getPart(), j) > 0)
		{
			temp.push_back(findPart(vecUnit[i] -> getPart(), j));
			j = findPart(vecUnit[i] -> getPart(), j);
		}

		posVector.push_back(temp);
		temp.clear();
		j = 0;
	}

	for (int k = 0; k < posVector.size(); k++)
		if (posVector[k].size() == 0)
		{
			std::cout << "404, combination not found" << std::endl;
			return posVector;
		}
		
	this->Combine(vecUnit, posVector, comboVector, 0, 0);

	return posVector;
};

std::vector <Unit*> TextParser::toUnits (std::vector<std::string> cutString)
{
	std::vector <Unit*> vecUnit(0);
	int j = 0;
	Unit* temp;
	std::string tempShift = "";
	
	for (int i =0; i < cutString.size(); i++)
	{
		if (cutString[i] == "+")
			tempShift = "1+";
		
		else if (cutString[i] == "*")
		{
			if ((tempShift == "1+") || (tempShift == "1"))
				tempShift = "1+";
			else 
				tempShift = "0+";

		}

		else if (cutString[i] == ".")
		{
			if ((tempShift == "1+") || (tempShift == "0+"))
				tempShift = "1+";
			else 
				tempShift = "1";
		}

		else
		{
			temp = new Unit (cutString[i], "", tempShift);
			vecUnit.push_back(temp);
			tempShift = "";
			j++;
		}
	}

	if (vecUnit.size() == 0)
	{
		temp = new Unit ("", "", tempShift);
		vecUnit.push_back(temp);
		return vecUnit;
	}

	if (tempShift != "")
		vecUnit[vecUnit.size() - 1] -> setRightShift(tempShift);

	for (int i = 0; i < vecUnit.size() - 1; i++)
		vecUnit[i] -> setRightShift(vecUnit[i+1] -> getLeftShift());

	
	this -> findAll(vecUnit);

	return vecUnit;
};

std::vector<std::string> TextParser::cutString ()
{
	std::string fText = this -> findText;
	std::vector<std::string> redfText(0);
	std::string temp = "";

	for (unsigned int i = 0; i < fText.length(); i++)
	{
		if ((fText[i] != '.') && (fText[i] != '*') && (fText[i] != '+'))
			temp += fText[i];

		else 
		{
			if (temp != "")
			redfText.push_back(temp);

			temp = fText[i];
			redfText.push_back(temp);
		
			temp = "";
		}

	}

	if (temp != "")
		redfText.push_back(temp);

	//for (unsigned int i = 0; i < redfText.size(); i++)
	//	std::cout << redfText[i] << std::endl;
	
	 toUnits(redfText);
	 return redfText;
};