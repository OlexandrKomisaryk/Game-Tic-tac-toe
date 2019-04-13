#include"Tic_tac_toe.h"
#include<fstream>

int main()
{
	string path = "E://C++//Tic_Tac_Toe//result.txt";
	ofstream fout(path);

	Tic_tac_toe game;
	int WhoPlaysFirst;//if the number is divided by 2, then the first person plays
	int level;
	string name;

	game.ShowLow();
	cout << "Please enter your name: ";
	cin >> name;
	game.SetHumanName(name);

	while (true)
	{
		cout << "\n If you want to play first, enter a even number, the second - odd number, enter -100 to complete: ";
		cin >> WhoPlaysFirst;
		cout << endl;
		if (WhoPlaysFirst == -100)
			break;

		cout << "Enter the level of difficulty of the game, 1 is Easy, 2 is Hard: ";
		cin >> level;

		if (level == 2)
			game.SetLevel(Tic_tac_toe::Level::HARD);
		else 
			game.SetLevel(Tic_tac_toe::Level::EASY);

		game.SetPlaysFirst(WhoPlaysFirst);
		system("cls");
		game.Clear();
		game.ShowField(&cout);

		if (fout.is_open())
		{
			fout << name << " vs Computer\n\n";
		}
		while ((!game.Vin(game.CompSymbol())) && (!game.Vin(game.PeopleSymbol())) && (!game.Full()))
		{
			game.Move();
			system("cls");
			game.ShowField(&cout);
			cout << endl;
			game.ShowVin(&cout);
			if (fout.is_open())
			{
				game.ShowField(&fout);
				fout << "#######\n";
				game.ShowVin(&fout);
			}
		}
		fout.close();
	}
	return 0;
}