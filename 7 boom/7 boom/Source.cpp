#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
struct player
{
	char boom;
	char num;
};
enum
{
	null, one = 1, two, three, four
};
bool check_num_for_7(int);
void player_1();
void player_2();
void player_X(int);
bool check_i(int, player*, int, bool);
bool check_input(int&, int, int);
int main()
{
	int choise;

	do {
		do
		{
			system("cls");
			cout << "How many players do you want[0-15]?" << endl;
		} while (!check_input(choise, 0, 15));
		switch (choise)
		{
		case null:
			break;
		case one:
			player_1();
			break;
		case two:
			player_2();
			break;
		default:
			player_X(choise);
			break;
		}
		if (choise)
		{
			system("cls");
			cout << "do you want to play again[1/0]?";
			while (!check_input(choise, 0, 1));
		}
	} while (choise);

	return 0;
}
bool check_num_for_7(int num)
{
	bool is_7 = false;
	//if the number devide by 7
	if (num % 7 == 0)
		is_7 = true;
	//if is seven in the number
	while (num && !is_7)
	{
		if (num % 10 == 7)
			is_7 = true;
		num /= 10;
	}
	return is_7;
}
bool check_input(int& num, int min, int max)
{
	bool check = true;

	char num1[100];

	cin >> num1;

	for (int i = 0; num1[i] && check; ++i)
	{
		if (num1[i] < '0' && num1[i] > '9')
			check = false;
	}

	if (check)
	{
		num = atoi(num1);
		if (num < min || num > max)
			check = false;
	}

	return check;
}
void player_1()

{
	int number = 1;

	bool lost1 = false;

	char boom_1[]{ "boom" };

	player p[1];

	char keyBoom, keyNum, key;

	cout << "player:" << endl << "enter a char for boom:";

	keyBoom = _getch();

	cout << keyBoom << endl;

	p->boom = keyBoom;

	cout << "enter a char for number:";

	do
	{
		keyNum = _getch();
	} while (keyNum == p->boom);

	cout << keyNum << endl;

	p->num = keyNum;


	//Sleep(500);
	cout << "-------------------------------------------------------" << endl << endl;
	//system("cls");

	while (!lost1)
	{
		do
		{
			key = _getch();
		} while (key != p->boom && key != p->num);

		if (check_num_for_7(number))
		{
			if (key != p->boom)
				lost1 = true;
			else
			{
				cout << "boom!" << ' ';
				++number;
			}

		}
		else
		{
			if (key != p->num)
				lost1 = true;
			else
				cout << number++ << ' ';
		}
		if (lost1)
			break;
	}

	Sleep(1000);

	system("cls");

	cout << "great!!!! you got to the number " << number << endl;

	system("pause");
}
void player_2()
{
	int number = 1;

	bool win1 = false, win2 = false;

	char boom_1[]{ "boom" };

	player p[2];

	char keyBoom, keyNum, key;

	cout << "player 1:" << endl << "enter a char for boom:";

	keyBoom = _getch();

	cout << keyBoom << endl;

	p->boom = keyBoom;

	cout << "enter a char for number:";

	do
	{
		keyNum = _getch();
	} while (keyNum == p->boom);

	cout << keyNum << endl;

	p->num = keyNum;

	cout << "player 2:" << endl << "enter a char for boom:";

	do
	{
		keyBoom = _getch();
	} while (keyBoom == p->boom || keyBoom == p->num);

	cout << keyBoom << endl;

	cout << "enter a char for number:";

	p[1].boom = keyBoom;

	do
	{
		keyNum = _getch();
	} while (keyNum == p->boom || keyNum == p->num || keyNum == p[1].boom);

	cout << keyNum << endl;

	p[1].num = keyNum;

	//Sleep(500);
	cout << "-------------------------------------------------------" << endl << endl;
	//system("cls");

	while (!win1 && !win2)
	{
		do
		{
			key = _getch();
		} while (key != p->boom && key != p->num);

		if (check_num_for_7(number))
		{
			if (key != p->boom)
				win2 = true;
			else
			{
				cout << "boom!" << ' ';
				++number;
			}

		}
		else
		{
			if (key != p->num)
				win2 = true;
			else
				cout << number++ << ' ';
		}
		if (win2)
			break;
		do
		{
			key = _getch();
		} while (key != p[1].boom && key != p[1].num);

		if (check_num_for_7(number))
		{
			if (key != p[1].boom)
				win1 = true;
			else
			{
				cout << "boom!" << ' ';
				++number;
			}
		}
		else
		{
			if (key != p[1].num)
				win1 = true;
			else
				cout << number++ << ' ';
		}
	}

	Sleep(1000);

	system("cls");

	if (win1)
		cout << "player 1 win!!!!!!" << endl;
	else
		cout << "player 2 win!!!!!!" << endl;

	system("pause");
}
void player_X(int x)
{
	int turn = 0, number = 1;

	bool loost = false;

	player *players = new player[x];

	char key;

	for (int i = 0; i < x; ++i)
	{
		cout << "player " << i + 1 << ':' << endl;
		cout << "enter a char for boom:";
		do {
			key = _getch();
		} while (!check_i(i, players, key, false));
		players[i].boom = key;
		cout << key << endl;
		cout << "enter a char for number:";
		do
		{
			key = _getch();
		} while (!check_i(i, players, key, true));
		players[i].num = key;
		cout << key << endl;
	}

	cout << "-----------------------------------" << endl;

	while (!loost)
	{
		key = _getch();
		if (check_num_for_7(number))
		{
			if (key != players[turn].boom)
				break;
			else
			{
				cout << "boom!" << ' ';
				++number;
			}
		}
		else
		{
			if (key != players[turn].num)
				break;
			else
				cout << number++ << ' ';
		}
		if (turn == x - 1)
			turn = 0;
		else
			turn++;
	}

	delete[] players;

	cout << "great!!!! you got to the number " << number << endl;

	system("pause");
}
bool check_i(int x, player *p, int tCheck, bool one)
{
	bool c = true;
	for (int i = 0; c && i < x; ++i)
	{
		if (p[i].boom == tCheck || p[i].num == tCheck)
			c = false;
	}
	if (c && one)
		if (p[x].boom == tCheck)
			c = false;
	return c;
}