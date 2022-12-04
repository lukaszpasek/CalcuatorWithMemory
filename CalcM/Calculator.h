#pragma once


class calculator
{
	double ADD();
	double SUBTRACT();
	double MULTIPLY();
	double DIVIDE();
	double MODULO();
	double SQRT();

public:
	calculator();
	char operation;
	double number1;
	double number2;
	double numberMemory;
	void do_command();
	void do_command(bool inMemory);
	void CLEAR();
	void CLEARMEMORY();
};

