#include"Tic_tac_toe.h"

int main()
{
	Tic_tac_toe game;
	int play;//if the number is divided by 2, then the first person plays

	game.ShowLow();
	while (true)
	{
		cout << "If you want to play first, enter a even number, the second - odd number, enter -100 to complete\n";
		cin >> play;
		if (play == -100)
			break;

		game.SetPlay(play);
		system("cls");
		game.Clear();
		game.Show();

		while ((!game.Vin('X')) && (!game.Vin('O')) && (!game.Full()))
		{
			game.Move();
			system("cls");
			game.Show();
		}
	}
	return 0;
}