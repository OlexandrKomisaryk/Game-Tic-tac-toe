#include "Tic_tac_toe.h"

Tic_tac_toe::Tic_tac_toe()
{
	field.resize(SIZE,' ');
}

void Tic_tac_toe::ShowField(ostream *out) //The method takes the pointer to class ostream so that we can pass the link
{										  //to the object child-class ofstream and work with the files.
string line(7, '-');
*out << "|" << field[0] << "|" << field[1] << "|" << field[2] << "|" << endl;
*out << line << endl;
*out << "|" << field[3] << "|" << field[4] << "|" << field[5] << "|" << endl;
*out << line << endl;
*out << "|" << field[6] << "|" << field[7] << "|" << field[8] << "|" << endl;
}


char Tic_tac_toe::PeopleSymbol()
{
	return PlaysFirst % 2 == 0 ? first_symbol : second_symbol;
}
char Tic_tac_toe::CompSymbol()
{
	return PeopleSymbol() == first_symbol ? second_symbol : first_symbol;
}

bool Tic_tac_toe::IsEmpty(int index)
{
	return (field[index] == ' ');
}

bool Tic_tac_toe::Vin(char symbol)
{
	int temp = 0;
	for (int i = 0; i < SIZE; i += 3)
	{
		if (field[i] == symbol && field[i + 1] == symbol &&  field[i + 2] == symbol)
		{
			temp++;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (field[i] == symbol && field[i + 3] == symbol && field[i + 6] == symbol)
		{
			temp++;
		}
	}
	if (field[0] == symbol && field[4] == symbol && field[8] == symbol)
	{
		temp++;
	}
	if (field[2] == symbol && field[4] == symbol && field[6] == symbol)
	{
		temp++;
	}
		return temp <= 0 ? false : true;
}

void Tic_tac_toe::ShowVin(ostream *out)
{
	if (Vin(CompSymbol()))
	{
		*out << "Vin symbol: " << CompSymbol() << ". Won the computer!\n";
	}
	else if (Vin(PeopleSymbol()))
	{
		*out << "Vin symbol: " << PeopleSymbol() << ". Won the " << human_name << "!\n";
	}
	else if (Full())
	{
		*out << "The game ended with a draw.\n";
	}
}

bool Tic_tac_toe::Full()
{
	int temp = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (field[i] != ' ')
			temp++;
	}
	return (temp == 9) ? true : false;
}

void Tic_tac_toe::ShowLow()
{
	char ch = '|';
	string gap_line(11, ' ');
	cout << "Each digit corresponds to the number in the game field.\n";
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
	if (!NextMoveVin(CompSymbol()) && !(NextMoveVin(PeopleSymbol())))
	switch (lv)
	{
		case EASY:
		{
			srand(time(NULL));
			int temp = 0;
			while (temp == 0)
			{
				coord = rand() % SIZE;
				if (IsEmpty(coord))
				{
					field[coord] = CompSymbol();
					temp = 1;
				}
			}
		}
		break;
		case HARD:
		{
			int ArrayPosition[9] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 };//the priorities of the cells on the field
			for (int i = 0; i < SIZE; i++)
			{
				if (IsEmpty(ArrayPosition[i]))
				{
					field[ArrayPosition[i]] = CompSymbol();
					break;
				}
			}
		}
		break;
		default:
			break;
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
			field[coord] = PeopleSymbol();	//game of the person and will do it in the next game
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

bool Tic_tac_toe::NextMoveVin(char checked_char) //If in the next step the computer wins, it does this step. 
{												 //If the computer does not win in the next step,
	int i;									     //but a person wins, then the computer blocks its step.
	for (i = 0; i < SIZE; i++)
	{
		if (IsEmpty(i))
		{
			field[i] = checked_char;
			if (Vin(checked_char)) 
			{
				if (checked_char == PeopleSymbol())
				{
					field[i] = CompSymbol();
				}
				break;
			}
			else
			{
				field[i] = ' ';
			}
		}
	}
	return (i < SIZE);
	
}

void Tic_tac_toe::Clear()
{
	for (int i = 0; i < SIZE; i++)
	{
		field[i] = ' ';
	}
}

