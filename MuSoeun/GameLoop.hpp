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
	
int state = 0;
int screen = 1;
int Mainscreen()
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
	std::cout << "메인 화면으로 돌아가려면 ESC 키를 누르세요.\n";
	isESC = true;
	while (isESC)
	{
		KeyEventInMenu(_getch(), 2);
	}
	return 0;
}
int r_screen()
{
	system("cls");
	std::cout << "****************************************\n";
	std::cout << "*        게임 랭킹 화면입니다.         *\n";
	std::cout << "****************************************\n";
	return 0;
}
void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}void KeyEventInMenu(char KeyInput, int st)
{
	switch (KeyInput)
	{
	case KEY_ESC:
		system("cls");
		gotoxy(3, 5);
		cout << "메인 화면으로 돌아갈까요?" << endl;
		gotoxy(3, 8);
		cout << ANSI_COLOR_YELLOW"돌아간다";
		gotoxy(15, 8);
		cout << ANSI_COLOR_RESET"돌아가지 않는다";
		isESC = true;
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
	default:
		break;
	}
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
		cout << ANSI_COLOR_RESET"다시 시작(R)";
		isESC = true;
		break;
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
	if (isESC)
	{
		switch (KeyInput)
		{
		case KEY_LEFT:
			gotoxy(3, 5);
			cout << "메인 화면으로 돌아갈까요?" << endl;
			gotoxy(3, 8);
			cout << ANSI_COLOR_YELLOW"돌아간다";
			gotoxy(15, 8);
			cout << ANSI_COLOR_RESET"다시 시작(R)";
			isYes = true;
			break;
		case KEY_RIGHT:
			gotoxy(3, 5);
			cout << "메인 화면으로 돌아갈까요?" << endl;
			gotoxy(3, 8);
			cout << ANSI_COLOR_RESET"돌아간다";
			gotoxy(15, 8);
			cout << ANSI_COLOR_YELLOW"다시 시작(R)";
			cout << ANSI_COLOR_RESET"";
			isYes = false;
			break;
		}
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
	char c = 0;
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
		void GLOOP()
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
						Mainscreen();
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
			scene.AddObject(&snakeHead);
			snakeHead.SetPosition(15, 5);
			scene.AddObject(&apple);  
			apple.SetRandomApplePos(screenWidth, screenHeight);
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
				if (snakeHead.posX == apple.applex && snakeHead.posY == apple.appley)
				{
					isapple = true;
					snakeHead.tailsize += 1;
				}
				if (isapple)
				{
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