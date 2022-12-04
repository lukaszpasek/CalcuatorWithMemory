// Calc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "Calculator.h"
using namespace std;


bool isNumber(const char s)
{
	return ((s >= 48 && s <= 57) || s==46);
}

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

bool isOperator(char x,char operators[])
{
	for (int i = 0; i < 7; i++)
	{
		if (operators[i] == '#') return false;
		if (operators[i] == x) return true;
	}
	return false;
}

string DoOperators(string input,char operators[])
{
	calculator testCalculator;
	int i = 0;
	string Input = input + '#';
	string result = "";
	input = "";
	while (Input[i] != NULL)
	{
		input += Input[i];
		if (!isOperator(Input[i],operators))
		{
			if (testCalculator.operation != 'd')
			{
				while (isNumber(Input[i+1])) input += Input[++i];
				testCalculator.number2 = stod(input);
				testCalculator.do_command();
				result = to_string(testCalculator.number1);
				input = "";
			}
			else if(isNumber(Input[i]))
			{
				testCalculator.number1 = stod(input);
			}
			else
			{
				result += input;
				input = "";
			}
		}
		else
		{
			input = "";
			input = Input[i];
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
			default:
				testCalculator.operation = inputOperator;
				break;
			}
			input = "";
		}
		i++;
	}
	return result;
}

string Calculate(string input)
{
	char Operators[] = { '+', '-', '*', '/', '^', 'p', '%','#' };
	char Operators1P[] = { '+', '-' ,'#' };
	char Operators2P[] = { '*', '/' ,'#' };
	char Operators3P[] = { '^', 'p', '%','#' };
	input = DoOperators(input, Operators3P);
	input = DoOperators(input, Operators2P);
	input = DoOperators(input, Operators1P);
	return input;
}

int main()
{
	cout << "----Kalkulator prosty ver.1.1----\n";
	cout << "Wprowadz E aby zakonczyc\n";
	string input;
	bool isDoubleInput = false;
	while (cin >> input)
	{
		input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
		string _input = "";
		bool add = false;
		string formula = "";
		for (int j = 0; j < input.length();j++)
		{
			if (input[j] == '(') add = true;
			else if (input[j] == ')')
			{
				string s = Calculate(formula);
				for (int it = 0; it < s.length();it++)
				{
					if (s[it] == '#') break;
					_input += s[it];
				}
				formula = "";
				add = false;
			}
			else if(add) formula += input[j];
			else _input += input[j];
			
		}
		input = Calculate(_input);
		for (int j = 0; j < input.length();j++)
		{
			if (input[j] == '#') input[j] = ' ';
		}
		cout << input << "\n";
	}
}

