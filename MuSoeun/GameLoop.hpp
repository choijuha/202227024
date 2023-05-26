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
	std::cout << "* A키 - 뱀이 왼쪽으로 머리를 돌립니다.   *\n";
	std::cout << "*                                        *\n";
	std::cout << "* D키 - 뱀이 오른쪽으로 머리를 돌립니다. *\n";
	std::cout << "*                                        *\n";
	std::cout << "*      사과를 먹으면 뱀이 길어집니다.    *\n";
	std::cout << "*                                        *\n";
	std::cout << "* 뱀이 벽이나 자신의 꼬리에 닿거나       *\n";
	std::cout << "* X와 부딪히면 게임이 종료됩니다.        *\n";
	std::cout << "*                                        *\n";
	std::cout << "******************************************\n";
	std::cout << "메인 화면으로 돌아가려면 ESC 키를 누르세요.\n";
	isESC = false;
	while (!isESC)
	{
		char c = _getch();
		if (c == KEY_ESC)
		{
			system("cls");
			gotoxy(3, 5);
			cout << "메인 화면으로 돌아갈까요?" << endl;
			gotoxy(3, 8);
			cout << ANSI_COLOR_YELLOW"돌아간다";
			gotoxy(15, 8);
			cout << ANSI_COLOR_RESET"돌아가지 않는다";
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
	std::cout << "*        게임 랭킹 화면입니다.         *\n";
	std::cout << "****************************************\n";
	std::cout << "메인 화면으로 돌아가려면 ESC 키를 누르세요.\n"; 
	isESC = false; 
	while (!isESC)
	{
		char c = _getch();
		if (c == KEY_ESC)
		{
			system("cls");
			gotoxy(3, 5);
			cout << "메인 화면으로 돌아갈까요?" << endl;
			gotoxy(3, 8);
			cout << ANSI_COLOR_YELLOW"돌아간다";
			gotoxy(15, 8);
			cout << ANSI_COLOR_RESET"돌아가지 않는다";
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
		std::cout << "*              지렁이 게임             *\n";
		std::cout << "*             (Snake Bite)             *\n";
		std::cout << "*                                      *\n";
		gotoxy(0, 4);
		std::cout << ANSI_COLOR_RESET"*";
		gotoxy(6, 4);
		cout << ANSI_COLOR_YELLOW"1. 게임 시작";
		gotoxy(39, 4);
		cout << ANSI_COLOR_RESET"*\n";
		std::cout << "*     2. 게임 설명                     *\n";
		std::cout << "*     3. 게임 랭킹 보기                *\n";
		std::cout << "*     4. 게임 종료                     *\n";
		std::cout << "****************************************\n";
	}
	else if (choicenum == 2)
	{
		system("cls");
		std::cout << "****************************************\n";
		std::cout << "*              지렁이 게임             *\n";
		std::cout << "*             (Snake Bite)             *\n";
		std::cout << "*                                      *\n";
		std::cout << "*     1. 게임 시작                     *\n";
		gotoxy(0, 5);
		std::cout << ANSI_COLOR_RESET"*";
		gotoxy(6, 5);
		cout << ANSI_COLOR_YELLOW"2. 게임 설명";
		gotoxy(39, 5);
		cout << ANSI_COLOR_RESET"*\n";
		std::cout << "*     3. 게임 랭킹 보기                *\n";
		std::cout << "*     4. 게임 종료                     *\n";
		std::cout << "****************************************\n";
	}
	else if (choicenum == 3)
	{
		system("cls");
		std::cout << "****************************************\n";
		std::cout << "*              지렁이 게임             *\n";
		std::cout << "*             (Snake Bite)             *\n";
		std::cout << "*                                      *\n";
		std::cout << "*     1. 게임 시작                     *\n";
		std::cout << "*     2. 게임 설명                     *\n";
		gotoxy(0, 6);
		std::cout << ANSI_COLOR_RESET"*";
		gotoxy(6, 6);
		cout << ANSI_COLOR_YELLOW"3. 게임 랭킹 보기";
		gotoxy(39, 6);
		cout << ANSI_COLOR_RESET"*\n";
		std::cout << "*     4. 게임 종료                     *\n";
		std::cout << "****************************************\n";
	}
	else if (choicenum == 4)
	{
		system("cls");
		std::cout << "****************************************\n";
		std::cout << "*              지렁이 게임             *\n";
		std::cout << "*             (Snake Bite)             *\n";
		std::cout << "*                                      *\n";
		std::cout << "*     1. 게임 시작                     *\n";
		std::cout << "*     2. 게임 설명                     *\n";
		std::cout << "*     3. 게임 랭킹 보기                *\n";
		gotoxy(0, 7);
		std::cout << ANSI_COLOR_RESET"*";
		gotoxy(6, 7);
		cout << ANSI_COLOR_YELLOW"4. 게임 종료     ";
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
		std::cout << "*              게임 종료               *\n";
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
			cout << "메인 화면으로 돌아갈까요?" << endl;
			gotoxy(3, 8);
			cout << ANSI_COLOR_YELLOW"돌아간다";
			gotoxy(15, 8);
			cout << ANSI_COLOR_RESET"돌아가지 않는다";
			isYes = true;
			break;
		case KEY_RIGHT:
			system("cls");
			gotoxy(3, 5);
			cout << "메인 화면으로 돌아갈까요?" << endl;
			gotoxy(3, 8);
			cout << ANSI_COLOR_RESET"돌아간다";
			gotoxy(15, 8);
			cout << ANSI_COLOR_YELLOW"돌아가지 않는다";
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
		cout << "메인 화면으로 돌아갈까요?" << endl;
		gotoxy(3, 8);
		cout << ANSI_COLOR_YELLOW"돌아간다";
		gotoxy(15, 8);
		cout << ANSI_COLOR_RESET"다시 시작";
		isESC = true;
		if (isESC)
		{
		case KEY_LEFT:
			gotoxy(3, 5);
			cout << "메인 화면으로 돌아갈까요?" << endl;
			gotoxy(3, 8);
			cout << ANSI_COLOR_YELLOW"돌아간다";
			gotoxy(15, 8);
			cout << ANSI_COLOR_RESET"다시 시작";
			isYes = true;
			break;
		case KEY_RIGHT:
			gotoxy(3, 5);
			cout << "메인 화면으로 돌아갈까요?" << endl;
			gotoxy(3, 8);
			cout << ANSI_COLOR_RESET"돌아간다";
			gotoxy(15, 8);
			cout << ANSI_COLOR_YELLOW"다시 시작";
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