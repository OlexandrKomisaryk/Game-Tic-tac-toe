#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<conio.h>
#include<ctime>
using namespace std;

class Tic_tac_toe
{
public:
	enum Level
	{
		EASY,
		HARD
	};
private:
	vector<char> filed;
	string human_name;
	char first_symbol = 'X';
	char second_symbol = 'O';
	static const int SIZE = 9;
	int PlaysFirst;
	int play;
	unsigned int coord;
	Level lv;
public:
	Tic_tac_toe();
	void Show();
	void Clear();
	void SetPlaysFirst(int val) { PlaysFirst = val; play = val; }
	void SetLevel(Level lv) { this->lv = lv; }
	void SetHumanName(string name) { human_name = name; }
	char CompSymbol();
	char PeopleSymbol();
	bool IsEmpty(int index);
	bool Vin(char symvol);
	void ShowVin();
	bool Full();
	void ShowLow();
	void CompMove();
	void PeopleMove();
	void Move();
	bool NextMoveVin(char checked_char);
};

