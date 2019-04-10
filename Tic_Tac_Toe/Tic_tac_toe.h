#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<conio.h>
#include<ctime>
using namespace std;

class Tic_tac_toe
{
private:
	vector<char> filed;
	char first_symbol = 'X';
	char second_symbol = 'O';
	static const int SIZE = 9;
	int play;
	int coord;
public:
	Tic_tac_toe();
	void Show();
	void Clear();
	void SetPlay(int n) { play = n; }
	char PlaySymbol();
	bool IsEmpty(int index);
	bool Vin(char symvol);
	bool Full();
	void ShowLow();
	void CompMove();
	void PeopleMove();
	void Move();
};

