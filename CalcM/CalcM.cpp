// Calc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "Calculator.h"
using namespace std;

bool isNumber(const std::string& s)
{
	try
	{
		std::stod(s);
	}
	catch (...)
	{
		return false;
	}
	return true;
}

int main()
{
	cout << "----Kalkulator prosty ver.1.1----\n";
	cout << "Wprowadz E aby zakonczyc\n";
	calculator testCalculator;
	string input;
	bool isDoubleInput = false;
	while (cin >> input)
	{
		input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
		if (isNumber(input))
		{
			if (testCalculator.operation != 'd')

			{
				//if (isDoubleInput)
				//{
				//	int wyk = log10(testCalculator.number2) + 1;
				//	testCalculator.number2 += stod(input) / pow(10, wyk);
				//	isDoubleInput = false;
				//}
				//else
				//{
				testCalculator.number2 = stod(input);
				//}
				testCalculator.do_command();
				cout << testCalculator.number1 << "\n";
			}
			else
			{
				testCalculator.number1 = stod(input);
			}
		}
		else
		{
			char inputOperator = input[0];
			switch (inputOperator)
			{
			case 'C':
				testCalculator.CLEAR();
				continue;
				break;
			case 'E':
				exit(0);
				break;
			case 's':
				testCalculator.do_command();
				cout << testCalculator.number1 << "\n";
				break;
			case 'M':
				switch (input[1])
				{
				case 'R':
					cout << testCalculator.numberMemory << "\n";
					break;
				case 'C':
					testCalculator.CLEARMEMORY();
					break;
				default:
					testCalculator.operation = input[1];
					testCalculator.do_command(true);
					cout << testCalculator.numberMemory << "\n";
					break;
				}
				break;
			default:
				testCalculator.operation = inputOperator;
				break;
			}
		}
	}
}

