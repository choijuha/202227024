#pragma once
#include "Scene.hpp"
#include <random>
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_RESET    "\x1b[0m"
#define KEY_ESC 27
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'
#define KEY_ENTER 13


using namespace std;

namespace MuSeoun_Engine
{
	class GameLoop
	{
	public:
	bool isESC = false;
	bool isYes = true;
	bool isENTER = false;
	int screen = 1;
	int Mainscreen()
	{
		screen = 1;
		isENTER = true;
		int num = 1;
		PrintScreenChoice(num);
		while (isENTER)
		{
			char c = _getch();
			if (c == KEY_RIGHT)
			{
				if (num <= 3)
				{
					num += 1;
				}
			}
			else if (c == KEY_LEFT)
			{
				if (num >= 2)
				{
					num -= 1;
				}
			}
			if (c == KEY_ENTER)
			{
				if (num == 2) screenchange(2);
				else if (num == 3)screenchange(3);
				else if (num == 1) screenchange(4);
				else if (num == 4) num = 0;
				isENTER = false;
			}
			PrintScreenChoice(num);
		}

	return 0;
}
int i_screen()
{
	screen = 2;
	system("cls");
	std::cout << "******************************************\n";
	std::cout << "*                                        *\n";
	std::cout << "* AŰ - ���� �������� �Ӹ��� �����ϴ�.   *\n";
	std::cout << "*                                        *\n";
	std::cout << "* DŰ - ���� ���������� �Ӹ��� �����ϴ�. *\n";
	std::cout << "*                                        *\n";
	std::cout << "*      ����� ������ ���� ������ϴ�.    *\n";
	std::cout << "*                                        *\n";
	std::cout << "* ���� ���̳� �ڽ��� ������ ��ų�       *\n";
	std::cout << "* X�� �ε����� ������ ����˴ϴ�.        *\n";
	std::cout << "*                                        *\n";
	std::cout << "******************************************\n";
	std::cout << "���� ȭ������ ���ư����� ESC Ű�� ��������.\n";
	isESC = false;
	while (!isESC)
	{
		char c = _getch();
		if (c == KEY_ESC)
		{
			system("cls");
			gotoxy(3, 5);
			cout << "���� ȭ������ ���ư����?" << endl;
			gotoxy(3, 8);
			cout << ANSI_COLOR_YELLOW"���ư���";
			gotoxy(15, 8);
			cout << ANSI_COLOR_RESET"���ư��� �ʴ´�";
			isESC = true;
			isYes = true;
		}
	}
	while (isESC)
	{
		if (screen == 2)
		{
			char c = _getch();
			KeyEventInMenu(c, 2);
		}
	}
	return 0;
}
int r_screen()
{
	screen = 3;
	system("cls");
	std::cout << "****************************************\n";
	std::cout << "*        ���� ��ŷ ȭ���Դϴ�.         *\n";
	std::cout << "****************************************\n";
	std::cout << "���� ȭ������ ���ư����� ESC Ű�� ��������.\n"; 
	isESC = false; 
	while (!isESC)
	{
		char c = _getch();
		if (c == KEY_ESC)
		{
			system("cls");
			gotoxy(3, 5);
			cout << "���� ȭ������ ���ư����?" << endl;
			gotoxy(3, 8);
			cout << ANSI_COLOR_YELLOW"���ư���";
			gotoxy(15, 8);
			cout << ANSI_COLOR_RESET"���ư��� �ʴ´�";
			isESC = true;
			isYes = true;
		}
	}
	while (isESC)
	{
		if (screen == 3)
		{
			char c = _getch();
			KeyEventInMenu(c, 3);
		}
	}
	return 0;
}
void PrintScreenChoice(int choicenum)
{
	if (choicenum == 1)
	{
		system("cls");
		std::cout << "****************************************\n";
		std::cout << "*              ������ ����             *\n";
		std::cout << "*             (Snake Bite)             *\n";
		std::cout << "*                                      *\n";
		gotoxy(0, 4);
		std::cout << ANSI_COLOR_RESET"*";
		gotoxy(6, 4);
		cout << ANSI_COLOR_YELLOW"1. ���� ����";
		gotoxy(39, 4);
		cout << ANSI_COLOR_RESET"*\n";
		std::cout << "*     2. ���� ����                     *\n";
		std::cout << "*     3. ���� ��ŷ ����                *\n";
		std::cout << "*     4. ���� ����                     *\n";
		std::cout << "****************************************\n";
	}
	else if (choicenum == 2)
	{
		system("cls");
		std::cout << "****************************************\n";
		std::cout << "*              ������ ����             *\n";
		std::cout << "*             (Snake Bite)             *\n";
		std::cout << "*                                      *\n";
		std::cout << "*     1. ���� ����                     *\n";
		gotoxy(0, 5);
		std::cout << ANSI_COLOR_RESET"*";
		gotoxy(6, 5);
		cout << ANSI_COLOR_YELLOW"2. ���� ����";
		gotoxy(39, 5);
		cout << ANSI_COLOR_RESET"*\n";
		std::cout << "*     3. ���� ��ŷ ����                *\n";
		std::cout << "*     4. ���� ����                     *\n";
		std::cout << "****************************************\n";
	}
	else if (choicenum == 3)
	{
		system("cls");
		std::cout << "****************************************\n";
		std::cout << "*              ������ ����             *\n";
		std::cout << "*             (Snake Bite)             *\n";
		std::cout << "*                                      *\n";
		std::cout << "*     1. ���� ����                     *\n";
		std::cout << "*     2. ���� ����                     *\n";
		gotoxy(0, 6);
		std::cout << ANSI_COLOR_RESET"*";
		gotoxy(6, 6);
		cout << ANSI_COLOR_YELLOW"3. ���� ��ŷ ����";
		gotoxy(39, 6);
		cout << ANSI_COLOR_RESET"*\n";
		std::cout << "*     4. ���� ����                     *\n";
		std::cout << "****************************************\n";
	}
	else if (choicenum == 4)
	{
		system("cls");
		std::cout << "****************************************\n";
		std::cout << "*              ������ ����             *\n";
		std::cout << "*             (Snake Bite)             *\n";
		std::cout << "*                                      *\n";
		std::cout << "*     1. ���� ����                     *\n";
		std::cout << "*     2. ���� ����                     *\n";
		std::cout << "*     3. ���� ��ŷ ����                *\n";
		gotoxy(0, 7);
		std::cout << ANSI_COLOR_RESET"*";
		gotoxy(6, 7);
		cout << ANSI_COLOR_YELLOW"4. ���� ����     ";
		gotoxy(39, 7);
		cout << ANSI_COLOR_RESET"*\n";
		std::cout << "****************************************\n";
	}
	else if(choicenum == 0)
	{
		system("cls");
		std::cout << "****************************************\n";
		std::cout << "*                                      *\n";
		std::cout << "*                                      *\n";
		std::cout << "*              ���� ����               *\n";
		std::cout << "*                                      *\n";
		std::cout << "*                                      *\n";
		std::cout << "****************************************\n";
		printf("");
	}
}
void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void KeyEventInMenu(char KeyInput, int st)
{
	if (isESC)
	{
		switch (KeyInput)
		{
		case KEY_LEFT:
			system("cls");
			gotoxy(3, 5);
			cout << "���� ȭ������ ���ư����?" << endl;
			gotoxy(3, 8);
			cout << ANSI_COLOR_YELLOW"���ư���";
			gotoxy(15, 8);
			cout << ANSI_COLOR_RESET"���ư��� �ʴ´�";
			isYes = true;
			break;
		case KEY_RIGHT:
			system("cls");
			gotoxy(3, 5);
			cout << "���� ȭ������ ���ư����?" << endl;
			gotoxy(3, 8);
			cout << ANSI_COLOR_RESET"���ư���";
			gotoxy(15, 8);
			cout << ANSI_COLOR_YELLOW"���ư��� �ʴ´�";
			cout << ANSI_COLOR_RESET"";
			isYes = false;
			break;
		case KEY_ENTER:
			if (isYes)
			{
				screenchange(1);
				isESC = false;
			}
			else
			{
				screenchange(st);
				isESC = false;
			}
			break;
		}
	}
}
void KeyEvent(char KeyInput)
{
	switch (KeyInput)
	{
	case KEY_ESC:
		gotoxy(3, 5);
		cout << "���� ȭ������ ���ư����?" << endl;
		gotoxy(3, 8);
		cout << ANSI_COLOR_YELLOW"���ư���";
		gotoxy(15, 8);
		cout << ANSI_COLOR_RESET"�ٽ� ����";
		isESC = true;
		if (isESC)
		{
		case KEY_LEFT:
			gotoxy(3, 5);
			cout << "���� ȭ������ ���ư����?" << endl;
			gotoxy(3, 8);
			cout << ANSI_COLOR_YELLOW"���ư���";
			gotoxy(15, 8);
			cout << ANSI_COLOR_RESET"�ٽ� ����";
			isYes = true;
			break;
		case KEY_RIGHT:
			gotoxy(3, 5);
			cout << "���� ȭ������ ���ư����?" << endl;
			gotoxy(3, 8);
			cout << ANSI_COLOR_RESET"���ư���";
			gotoxy(15, 8);
			cout << ANSI_COLOR_YELLOW"�ٽ� ����";
			cout << ANSI_COLOR_RESET"";
			isYes = false;
			break;
		}
	case KEY_ENTER:
		if (isYes)
		{
			screenchange(1);
			isESC = false;
		}
		else
		{
			GameRun(50, 20);
			isESC = false;
		}
		break;
	default:
		break;
	}
	
}
void Stop()
{
	isESC = true;
	KeyEvent(KEY_ESC);
	while (isESC)
	{
		KeyEvent(_getch());
	}
}
int screenchange(int sc)
{
	if (sc == 2)
	{
		i_screen();
	}
	else if (sc == 3)
	{
		r_screen();
	}
	else if (sc == 4)
	{
		GameRun(50, 20);
	}
	else if (sc == 1)
	{
		Mainscreen();
	}
	return 1;
}
		bool isstop = false;
		bool isGameRunning = false;
		bool isapple = true;
		void Run()
		{
			Mainscreen();
		}
		void GameRun(int screenWidth, int screenHeight)
		{
			screenWidth += 3;
			screenHeight += 3;
			isGameRunning = true;
			Scene scene(screenWidth, screenHeight);
			Object object;
			Snake snakeHead;
			Apple apple;
			Xobject x;
			scene.AddObject(&x);
			scene.AddObject(&apple);
			scene.AddObject(&snakeHead);
			snakeHead.SetPosition(15, 5);
			apple.SetRandomApplePos(screenWidth, screenHeight);
			x.SetRandomXPos(screenWidth, screenHeight);
			isapple = false;
			isGameRunning = true;
			while (isGameRunning)
			{
				for (int i = 1; i < snakeHead.tailX.size(); i++)
					{
						if (snakeHead.posX == snakeHead.tailX[i] && snakeHead.posY == snakeHead.tailY[i])
						{
							Stop();
							isGameRunning = false;
						}
					}
					if ((snakeHead.posX + 1) <= 0 || snakeHead.posX >= screenWidth - 2 || (snakeHead.posY + 1) <= 0 || snakeHead.posY >= screenHeight - 2)
					{
						Stop();
						isGameRunning = false;
						break;
					}
					if (isX)
					{
						if(snakeHead.posX == x.Xx && snakeHead.posY == x.Xy)
						{
							Stop();
							isGameRunning = false;
							break;
						}
					}
				if (snakeHead.posX == apple.applex && snakeHead.posY == apple.appley)
				{
					isapple = true;
					snakeHead.tailsize += 1;
				}
				if (isapple)
				{
					x.SetRandomXPos(screenWidth, screenHeight);
					apple.SetRandomApplePos(screenWidth, screenHeight); 
					isapple = false;
				}
				scene.Draw();
				snakeHead.Keyinput();
				snakeHead.Movecon();
			}
		}
	};
}