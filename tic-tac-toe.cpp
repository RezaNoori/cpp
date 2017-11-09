#include <iostream>                                                  
#include "stdafx.h"
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;
using std::string;

void menu();
void new_game();
void get_1(char[][9], int);
void print_game(char[][9], int);
string get_name_1();
string get_name_2();
void play(char[][9], int);
bool user_1(char[][9], int, int, string);
bool user_2(char[][9], int, int, string);
bool horizontal(char[][9], int);
bool vertical(char[][9], int);
bool diagonal_from_left(char[][9], int);
bool diagonal_from_right(char[][9], int);
void save_game(bool, string, string);
void result_game();

int main()
{
	menu();
}

void menu()
{
	cout << "**********************************####----->> Programmer Reza Noori <<-----####**************************************" << endl;
	int k;
	while (true)
	{
		cout << "**************************\n***  1.New Game        ***\n***  2.Result Game     ***\n***  3.Exit            ***\n**************************" << endl;
		cout << "Enter number:";
		cin >> k;
		if (k == 1){
			new_game();
		}
		if (k == 2){
			result_game();
		}
		if (k == 3){
			break;
		}
	}
}

void result_game()
{
	string line;
	ifstream fp1("save_games.txt", ios::in);
	while (!fp1.eof())
	{
		getline(fp1, line);
		cout << line << endl;
	}
	fp1.close();
}

void new_game()
{
	const char r = 9, c = 9;
	char array[r][c];
	get_1(array, r);
	print_game(array, r);
	play(array, r);
}

void get_1(char array[][9], int r)
{
	char array_1[9] = { '*', '1', '2', '3', '4', '5', '6', '7', '8' };
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j <9; j++)
		{
			if (i == 0)
			{
				array[i][j] = array_1[j];
				continue;
			}
			if (i != 0 && j == 0)
			{
				array[i][j] = array_1[i];
			}
			else
			{
				array[i][j] = ' ';
			}
		}
	}
}

void print_game(char array[][9], int r)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << array[i][j] << "_|_";
		}
		cout << endl;
	}
}

string get_name_1()
{
	string name_1;
	cout << "user 1 :: Please Enter your name --->>>";
	cin >> name_1;
	return name_1;
}

string get_name_2()
{
	string name_2;
	cout << "user 2 :: Please Enter your name --->>>";
	cin >> name_2;
	return name_2;
}

void play(char array[][9], int r)
{
	string name_1;
	name_1 = get_name_1();
	cout << name_1 << " :::>>> O " << endl;
	string name_2;
	name_2 = get_name_2();
	cout << name_2 << " :::>>> X " << endl;
	bool t;
	char x, y;
	for (int i = 1; i <= 64; i++)
	{
		if (i % 2 != 0)
		{
			t = user_1(array, r, i, name_1);
			print_game(array, r);
			if (t == true)
			{
				cout << "Do you want to save the score?(y/n):";
				cin >> x;
				if (x == 'y')
				{
					t = true;
					save_game(t, name_1, name_2);
				}
				break;
				menu();
			}
		}
		else
		{
			t = user_2(array, r, i, name_2);
			print_game(array, r);
			if (t == true)
			{
				cout << "Do you want to save the score?(y/n):";
				cin >> x;
				if (x == 'y')
				{
					t = false;
					save_game(t, name_1, name_2);
				}
				break;
				menu();
			}
		}
	}
}

bool user_1(char array[][9], int r, int i, string name_1)
{
	cout << "***************************************###---->> " << name_1 << " <<----###***************************************" << endl;
	int x, y;
	while (true)
	{
		cout << "Please Enter pow    ||--:>>";
		cin >> x;
		if (x > 0 && x < 9)
		{
			cout << "Please Enter Column ||--:>>";
			cin >> y;
			if (y > 0 && y < 9)
			{
				if (array[x][y] == ' ')
				{
					array[x][y] = 'O';
					break;
				}
				else
				{
					cout << "This home offers plenty Please choose another home!!!" << endl;
					continue;
				}
			}
			else
			{
				cout << "try again!!!" << endl;
				continue;
			}
		}
		else
		{
			cout << "try again!!!" << endl;
			continue;
		}
	}
	bool t, w, p, h;
	if (i >= 7)
	{
		t = horizontal(array, r);
		w = vertical(array, r);
		p = diagonal_from_left(array, r);
		h = diagonal_from_right(array, r);
		if (t == true || w == true || p == true || h == true)
		{
			cout << "\a \n\n\n\t\t **********************you win ***********************\n\n\n\n" << "\a" << endl;
			return true;
		}
	}
}

bool user_2(char array[][9], int r, int i, string name_2)
{
	cout << "***************************************###---->> " << name_2 << " <<----###***************************************" << endl;
	int z, k;
	while (true)
	{
		cout << "Please Enter pow    ||--:>>";
		cin >> z;
		if (z > 0 && z < 9)
		{
			cout << "Please Enter Column ||--:>>";
			cin >> k;
			if (k > 0 && k < 9)
			{
				if (array[z][k] == ' ')
				{
					array[z][k] = 'X';
					break;
				}
				else
				{
					cout << "This home offers plenty Please choose another home!!!" << endl;
					continue;
				}
			}
			else
			{
				cout << "try again!!!" << endl;
				continue;
			}
		}
		else
		{
			cout << "try again!!!" << endl;
			continue;
		}
	}
	bool t, w, p, h;
	if (i >= 8)
	{
		t = horizontal(array, r);
		w = vertical(array, r);
		p = diagonal_from_left(array, r);
		h = diagonal_from_right(array, r);
		if (t == true || w == true || p == true || h == true)
		{
			cout << "\a \n\n\n\t\t **********************you win ***********************\n\n\n\n" << "\a" << endl;
			return true;
		}
	}
}

bool horizontal(char array[][9], int r)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i != 0 && j != 0)
			{
				if (array[i][j] == 'O')
				{
					if (array[i][j + 1] == 'O')
					{
						if (array[i][j + 2] == 'O')
						{
							if (array[i][j + 3] == 'O')
							{
								return true;
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i != 0 && j != 0)
			{
				if (array[i][j] == 'X')
				{
					if (array[i][j + 1] == 'X')
					{
						if (array[i][j + 2] == 'X')
						{
							if (array[i][j + 3] == 'X')
							{
								return true;
							}
						}
					}
				}
			}
		}
	}
}

bool vertical(char array[][9], int r)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i != 0 && j != 0)
			{
				if (array[i][j] == 'O')
				{
					if (array[i + 1][j] == 'O')
					{
						if (array[i + 2][j] == 'O')
						{
							if (array[i + 3][j] == 'O')
							{
								return true;
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i != 0 && j != 0)
			{
				if (array[i][j] == 'X')
				{
					if (array[i + 1][j] == 'X')
					{
						if (array[i + 2][j] == 'X')
						{
							if (array[i + 3][j] == 'X')
							{
								return true;
							}
						}
					}
				}
			}
		}
	}
}

bool diagonal_from_left(char array[][9], int r)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i != 0 || j != 0)
			{
				if (array[i][j] == 'O')
				{
					if (array[i + 1][j + 1] == 'O')
					{
						if (array[i + 2][j + 2] == 'O')
						{
							if (array[i + 3][j + 3] == 'O')
							{
								return true;
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i != 0 || j != 0)
			{
				if (array[i][j] == 'X')
				{
					if (array[i + 1][j + 1] == 'X')
					{
						if (array[i + 2][j + 2] == 'X')
						{
							if (array[i + 3][j + 3] == 'X')
							{
								return true;
							}
						}
					}
				}
			}
		}
	}
}

bool diagonal_from_right(char array[][9], int r)
{
	for (int i = 0; i<r; i++)
	{
		for (int j = 9; j >0; j--)
		{
			if (i != 0 || j != 0)
			{
				if (array[i][j] == 'O')
				{
					if (array[i + 1][j - 1] == 'O')
					{
						if (array[i + 2][j - 2] == 'O')
						{
							if (array[i + 3][j - 3] == 'O')
							{
								return true;
							}
						}
					}
				}
			}
		}
	}
	for (int i = r; i>0; i--)
	{
		for (int j = 9; j >0; j--)
		{
			if (i != 0 || j != 0)
			{
				if (array[i][j] == 'X')
				{
					if (array[i + 1][j - 1] == 'X')
					{
						if (array[i + 2][j - 2] == 'X')
						{
							if (array[i + 3][j - 3] == 'X')
							{
								return true;
							}
						}
					}
				}
			}
		}
	}
}

void save_game(bool t, string name_1, string name_2)
{
	fstream p("save_games.txt", ios::app);
	if (!p)
	{
		cout << "cannot open file .Press a kay to continue ...";
		cin.get();
		exit(0);
	}
	if (t == true)
	{
		p << name_1 << "       ---- || >> *** you win  ***\n" << name_2 << "       ---- || >> *** you lose ***\n******************************\n";
	}
	else
	{
		p << name_2 << "       ---- || >> *** you win  ***\n" << name_1 << "       ---- || >> *** you lose ***\n******************************\n";
	}
	cout << "Game saved successfully" << endl;
	p.close();
}
