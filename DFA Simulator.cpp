//project of simulate the finite automatas // programmer: Ali Forghani // sadjad university of technology // 2016

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <time.h>
using namespace std;
string input_linear_bar;
void gotoxy(int x, int y)
{
	COORD position;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (INVALID_HANDLE_VALUE != hConsole)
	{
		position.X = x;
		position.Y = y;

		SetConsoleCursorPosition(hConsole, position);
	}
}
//
void color(int number)
{
	HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, number);
}

class DFA
{
public:
	DFA()
	{
		fstream input;
		input.open("input_file.txt", ios::in);
		input >> domain_number;
		input >> state_number;
		input >> initial_state;
		
		flag = new bool[state_number];
		for (int i = 0; i < state_number; i++)
			input >> flag[i];
		transitions = new int*[state_number];
		for (int i = 0; i < state_number; i++)
			transitions[i] = new int[domain_number];
		for (int i = 0; i < state_number; i++)
			for (int j = 0; j < domain_number; j++)
				input >> transitions[i][j];
	}
	bool compile(string linear_bar)
	{
		int current_state = initial_state;
		int m = 11;
		int col = 5;
		for (int i = 0; i < linear_bar.size(); i++)
		{
			gotoxy(10, m);
			Sleep(1000);
			if (col == 9)
				col = 5;
			color(col++);
			cout << "from q" << current_state << " by " << linear_bar[i] << " to q" << transitions[current_state][(int)linear_bar[i] - 65] << endl;
			current_state = transitions[current_state][(int)linear_bar[i] - 65];
			m++;
		}
		if (flag[current_state])
			return true;
		else
			return false;
	}
private:
	int domain_number;
	int state_number;
	int initial_state;
	int **transitions;
	bool *flag;
};
int main()
{
	gotoxy(9, 0);
	color(3);
	cout << "Sadjad University of technology // Ali Forghani // 93412130";
	DFA test;
	gotoxy(18, 2);
	color(11);
	cout << "<<Deterministic Finite Accepter Simulator>>";
	gotoxy(10, 8);
	cout << "pleace Enter the linear_bar string to compile the DFA: ";
	cin >> input_linear_bar;
	bool compile = test.compile(input_linear_bar);
	gotoxy(18, 13 + input_linear_bar.size());
	if (compile)
	{
		color(10);
		cout << "Accepted";
	}
	else
	{
		color(12);
		cout << "Rejected";
	}
	system("pause>null");
	return 0;
}