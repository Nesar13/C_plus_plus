// I pledge my honor that I have abided by the Stevens Honor System. */
//Nesar Ahmed
#include <iostream>
#include <iomanip>
using namespace std;

bool is_value_equal(char, char, char);
bool is_it_over(char player[][3]);
int main()
{
	char again, current;
	char player[3][3];
	int r, c, moves = 1;
	char choice;

	do
	{

		for (int i = 1; i < 4; i++)
		{
			for (int j = 1; j < 4; j++)
			{
				player[i][j] = ' ';
			}
		}
		cout << setw(3) << "1" << setw(4) << "2" << setw(4) << "3" << endl;
		cout << setw(5) << "|" << setw(4) << "|" << endl;
		cout << "1" << setw(2) << player[1][1] << setw(2) << "|" << setw(2) << player[1][2] << setw(2) << "|" << setw(2) << player[1][3] << setw(2) << endl;;
		cout << setw(11) << " ___|___|___" << endl;
		cout << setw(5) << "|" << setw(4) << "|" << endl;
		cout << "2" << setw(2) << player[2][1] << setw(2) << "|" << setw(2) << player[2][2] << setw(2) << "|" << setw(2) << player[2][3] << setw(2) << endl;
		cout << setw(11) << " ___|___|___" << endl;
		cout << setw(5) << "|" << setw(4) << "|" << endl;
		cout << "3" << setw(2) << player[3][1] << setw(2) << "|" << setw(2) << player[3][2] << setw(2) << "|" << setw(2) << player[3][3] << setw(2) << endl;
		cout << setw(5) << "|" << setw(4) << "|" << endl;

		cout << "\nWho's going first? [X/O]: ";
		cin >> choice;

		while (choice != 'o' && choice != 'O' && choice != 'X' && choice != 'x')
		{
			cout << "This choice is not valid! Please try again: ";
			cin >> choice;
		}

		current = choice;
		cout << endl;

		while (moves <= 9)
		{
			moves = 1;
			do
			{
				cout << "\nplayer " << current << " enter row: ";
				cin >> r;

				while (r < 1 || r > 3)
				{
					cout << "Try again: ";
					cin >> r;
				}

				cout << "player " << current << " enter column: ";
				cin >> c;

				while (c < 1 || c > 3)
				{
					cout << "Invalid. Please try again: ";
					cin >> c;
				}

				if (player[r][c] != ' ')
				{
					cout << "Try again please: " << endl;
				}
			} while (player[r][c] != ' ');

			player[r][c] = current;

			cout << endl << setw(3) << "1" << setw(4) << "2" << setw(4) << "3" << endl;
			cout << setw(5) << "|" << setw(4) << "|" << endl;
			cout << "1" << setw(2) << player[1][1] << setw(2) << "|" << setw(2) << player[1][2] << setw(2) << "|" << setw(2) << player[1][3] << setw(2) << endl;;
			cout << setw(11) << " ___|___|___" << endl;
			cout << setw(5) << "|" << setw(4) << "|" << endl;
			cout << "2" << setw(2) << player[2][1] << setw(2) << "|" << setw(2) << player[2][2] << setw(2) << "|" << setw(2) << player[2][3] << setw(2) << endl;
			cout << setw(11) << " ___|___|___" << endl;
			cout << setw(5) << "|" << setw(4) << "|" << endl;
			cout << "3" << setw(2) << player[3][1] << setw(2) << "|" << setw(2) << player[3][2] << setw(2) << "|" << setw(2) << player[3][3] << setw(2) << endl;
			cout << setw(5) << "|" << setw(4) << "|" << endl;

			if (is_it_over(player))
			{
				cout << "Congratulations! player " << current << " has won!" << endl;
				cout << "Play Again? [y/n]: ";
				cin >> again;
				system("cls");
				break;
			}

			if (current == 'x' || current == 'X')
			{
				current = 'o';
			}

			else if (current == 'o' || current == 'O')
			{
				current = 'x';
			}


			moves++;
		}

		if (moves == 9)
		{
			cout << "This game ends in a tie!" << endl;
			cout << "Play Again? [y/n]: ";
			cin >> again;
			system("cls");
		}

	} while (again == 'Y' || again == 'y');

	return 0;
}

bool is_value_equal(char a, char b, char c)
{
	if (a != ' ' && b != ' ' && c != ' ')
	{

		if (a == b && b == c)
		{

			return true;
		}

		else
		{

			return false;
		}
	}

	else
	{
		return false;
	}
}

bool is_it_over(char player[][3])
{


	for (int i = 1; i < 4; i++)
	{
		if (is_value_equal(player[i][1], player[i][2], player[i][3]))
		{

			return true;
		}
	}

	//get columns
	for (int count = 1; count < 4; count++)
	{

		if (is_value_equal(player[1][count], player[2][count], player[3][count]))
		{

			return true;
		}
	}

	//get diagonals
	if (is_value_equal(player[1][1], player[2][2], player[3][2]))
	{

		return true;
	}

	if (is_value_equal(player[1][3], player[2][2], player[3][1]))
	{

		return true;
	}

	return false;
}