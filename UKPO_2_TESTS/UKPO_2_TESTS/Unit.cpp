#include "stdafx.h"
#include "../../UKPO_2/UKPO_2/Unit.h"
#include <string>

Unit::Unit (std::string part, std::string rightShift, std::string leftShift)
{
		this -> part = part;
		this -> rightShift = rightShift;
		this -> leftShift = leftShift;
}

void Unit::setRightShift (std::string rightShift)
{
	this -> rightShift = rightShift;
}

std::string Unit::getLeftShift ()
{
	return this -> leftShift;
}

std::string Unit::getPart ()
{
	return this -> part;
}

std::string Unit::getRightShift ()
{
	return this -> rightShift;
}