#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>

int state = 0;
int screen = 1;

int print_title()
{
	system("cls");
	std::cout << "****************************************\n";
	std::cout << "*              지렁이 게임             *\n";
	std::cout << "*             (Snake Bite)             *\n";
	std::cout << "*                                      *\n";
	std::cout << "*     1. 게임 시작                     *\n";
	std::cout << "*     2. 게임 설명                     *\n";
	std::cout << "*     3. 게임 랭킹 보기                *\n";
	std::cout << "*     4. 게임 종료(esc)                *\n";
	std::cout << "****************************************\n";
	return 0;
}
int i_screen()
{
	system("cls");
	std::cout << "****************************************\n";
	std::cout << "*        게임 설명 화면입니다.         *\n";
	std::cout << "****************************************\n";
	std::cout << "타이틀 화면으로 돌아갈까요?(Y/N)\n";
	return 0;
}
int r_screen()
{
	system("cls");
	std::cout << "****************************************\n";
	std::cout << "*        게임 랭킹 화면입니다.         *\n";
	std::cout << "****************************************\n";
	std::cout << "타이틀 화면으로 돌아갈까요?(Y/N)\n";
	return 0;
}
void makestage(int x, int y)
{
	system("cls");
	for (int i = 0; i < x + 2; i++)
	{
		for (int j = 0; j < y + 2; j++)
		{
			COORD pos = { i,j };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			if (j > 0 && j < y + 1 && i > 0 && i < x + 1) if (j == 1 || j == y ||  i == 1 ||  i == x) printf("*");
		}
	}
	printf("\n타이틀 화면으로 돌아갈까요?(Y/N)\n");
}
int screenchange(int sc)
{
	char c = 0;
	if (sc == 2)
	{
		i_screen();
		screen = 0;
	}
	else if (sc == 3)
	{
		r_screen();
		screen = 0;
	}
	else if (sc == 4)
	{
		makestage(30, 10);
		screen = 0;
	}
	else if (sc == 1) print_title();
	c = _getch();
	if (c == 'y')
	{
		state = 0;
		screen = 1;
	}
	else if (c == '4' || c == 27) return 0;

	return 1;
}

int main()
{
	int a = 0;
	int isgamerunning = 1;
	while (isgamerunning)
	{
		char c = 0;

		switch (state)
		{
		case 0:
			if (screen == 1)
			{
				print_title();
				screen = 0;
			}
			c = _getch();
			if (c == '2')
			{
				state = 2;
				screen = 2;
			}
			else if (c == '3')
			{
				state = 3;
				screen = 3;
			}
			else if (c == '1')
			{
				state = 1;
				screen = 4;
			}
			else if (c == '4' || c == 27)
				isgamerunning = 0;
			break;
		case 1:
			isgamerunning = screenchange(screen);
			break;
		case 2:
			isgamerunning = screenchange(screen);
			break;
		case 3:
			isgamerunning = screenchange(screen);
			break;
		default:
			break;
		}
	}
	return 0;
}