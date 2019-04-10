#include "Tic_tac_toe.h"

Tic_tac_toe::Tic_tac_toe()
{
	filed.resize(SIZE,' ');
}

void Tic_tac_toe::Show()
{
string line(7, '-');
cout << "|" << filed[0] << "|" << filed[1] << "|" << filed[2] << "|" << endl;
cout << line << endl;
cout << "|" << filed[3] << "|" << filed[4] << "|" << filed[5] << "|" << endl;
cout << line << endl;
cout << "|" << filed[6] << "|" << filed[7] << "|" << filed[8] << "|" << endl;
}

char Tic_tac_toe::PlaySymbol()
{
	return play % 2 == 0 ? first_symbol : second_symbol;
}

bool Tic_tac_toe::IsEmpty(int index)
{
	return (filed[index] == ' ');
}

bool Tic_tac_toe::Vin(char symbol)
{
	int temp = 0;
	for (int i = 0; i < SIZE; i += 3)
	{
		if (filed[i] == symbol && filed[i + 1] == symbol &&  filed[i + 2] == symbol)
		{
			temp++;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (filed[i] == symbol && filed[i + 3] == symbol && filed[i + 6] == symbol)
		{
			temp++;
		}
	}
	if (filed[0] == symbol && filed[4] == symbol && filed[8] == symbol)
	{
		temp++;
	}
	if (filed[2] == symbol && filed[4] == symbol && filed[6] == symbol)
	{
		temp++;
	}
	if (temp <= 0)
		return false;
	else
	{
		cout << "Vin symvol: " << symbol << endl;
		return true;
	}
}

bool Tic_tac_toe::Full()
{
	int temp = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (filed[i] != ' ')
			temp++;
	}
	return (temp == 9) ? true : false;
}

void Tic_tac_toe::ShowLow()
{
	char ch = '|';
	string gap_line(11, ' ');
	cout << "Each digit corresponds to the number in the game field\n";
	cout << "In order to insert a symbol into a cell, press the corresponding digit.\n\n";
	cout << gap_line << ch << 7 << ch << 8 << ch << 9 << ch << endl;
	cout << gap_line << "-------" << endl;
	cout << gap_line << ch << 4 << ch << 5 << ch << 6 << ch << endl;
	cout << gap_line << "-------" << endl;
	cout << gap_line << ch << 1 << ch << 2 << ch << 3 << ch << endl;
	cout << endl;
}

void Tic_tac_toe::CompMove()
{
	srand(time(NULL));
	int temp = 0;
	while (temp == 0)
	{
		coord = rand() % SIZE;
		if (IsEmpty(coord))
		{
			filed[coord] = PlaySymbol();
			temp = 1;
		}
	}
}

void Tic_tac_toe::PeopleMove()
{
	int temp = 0;
	while (temp == 0)
	{
		switch (_getch())
		{
		case '7': { coord = 0; }
				  break;
		case '8': { coord = 1; }
				  break;
		case '9': { coord = 2; }
				  break;
		case '4': { coord = 3; }
				  break;
		case '5': { coord = 4; }
				  break;
		case '6': { coord = 5; }
				  break;
		case '1': { coord = 6; }
				  break;
		case '2': { coord = 7; }
				  break;
		case '3': { coord = 8; }
				  break;
		}
		if (_kbhit() && IsEmpty(coord))		//if you pressed the key and the cell is not busy, then adding a 
		{									//character without _kbhit () will remember the last step of the last
			filed[coord] = PlaySymbol();	//game of the person and will do it in the next game
			temp = 1;
		}
	}
}

void Tic_tac_toe::Move()
{
	if (play % 2 == 0)
		PeopleMove();
	else
		CompMove();
	play++;
}

void Tic_tac_toe::Clear()
{
	for (int i = 0; i < SIZE; i++)
	{
		filed[i] = ' ';
	}
}

