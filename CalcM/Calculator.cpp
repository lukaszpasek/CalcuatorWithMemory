#pragma once
#include <iostream>
#include "Calculator.h"

double calculator::ADD()
{
	return number1 + number2;
}
double calculator::SUBTRACT()
{
	return number1 - number2;
}
double calculator::MULTIPLY()
{
	return number1 * number2;
}
double calculator::DIVIDE()
{
	if (number2 == 0)
	{
		std::cout << "Nieprawidlowa operacja!Nie mozna dzielic przez 0! Error!\n";
		return -1;
	}
	return number1 / number2;
}
double calculator::PERCENT()
{
	if ((int)number2 == 0)
	{
		std::cout << "Nieprawidlowa operacja!Nie mozna dzielic przez 0! Error!\n";
		return -1;
	}
	return number2/100 * number1;
}
double calculator::SQRT()
{
	if (number1 < 0)
	{
		std::cout << "Nieprawidlowa operacja!Nie ma pierwiastka kwadratowego liczby ujemnej! Error!\n";
		return -1;
	}
	return pow(number1,1/number2);
}
double calculator::POW()
{
	return pow(number1,number2);
}


calculator::calculator()
{
	number1 = 0;
	number2 = 0;
	operation = 'd';
	numberMemory = 0;
}
void calculator::CLEAR()
{
	number1 = 0;
	number2 = 0;
	operation = 'd';
}
void calculator::CLEARMEMORY()
{
	numberMemory = 0;
}
void calculator::do_command(bool inMemory)
{
	double value = -1;
	if (inMemory)
	{
		this->number2 = this->number1;this->number1 = numberMemory;
	}
	switch (operation)
	{
	case '+':
		value = ADD();
		break;
	case '-':
		value = SUBTRACT();
		break;
	case '*':
		value = MULTIPLY();
		break;
	case '/':
		value = DIVIDE();
		break;
	case '%':
		value = PERCENT();
		break;
	case 'p':
		value = SQRT();
		break;
	case '^':
		value = POW();
		break;
	default:
		std::cout << "Nieprawidlowa operacja!\n";
		break;
	}
	if (inMemory) 
	{
		this->numberMemory = value;this->number1 = this->number2;
	}
	else this->number1 = value;
	this->operation = 'd';
}

void calculator::do_command()
{
	double value = -1;
	switch (operation)
	{
	case '+':
		value = ADD();
		break;
	case '-':
		value = SUBTRACT();
		break;
	case '*':
		value = MULTIPLY();
		break;
	case '/':
		value = DIVIDE();
		break;
	case '%':
		value = PERCENT();
		break;
	case 'p':
		value = SQRT();
		break;
	case '^':
		value = POW();
		break;
	default:
		std::cout << "Nieprawidlowa operacja!\n";
		break;
	}
	this->number1 = value;
	this->operation = 'd';
}


