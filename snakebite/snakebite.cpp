#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int state = 0;
int screen = 1;
char **snake;

typedef struct Snake {
	int x, y;
	struct Snake* next;
} Snake;

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
void makestage(int width, int height)
{//char gpt의 작품
	system("cls");
	bool gameover = false;
	int apple_x, apple_y;
	bool appleeat = false;
	srand(time(NULL));
	int random_number = rand();
	apple_x = (random_number % (width -1 - 1 + 1)) + 1;
	apple_y = (random_number % (height -1 - 1 + 1)) + 1;
	width += 2; height += 2;
	char** grid;
	grid = (char**)malloc(sizeof(char*) * height);
	for (int i = 0; i < height; i++) {
		grid[i] = (char*)malloc(sizeof(char) * (width + 1));
		for (int j = 0; j < width; j++) {
			if (i == 0 || j == 0 || i == height - 1 || j == width - 1) {
				grid[i][j] = '*';
			}
			else {
				grid[i][j] = ' ';
			}
		}
		grid[i][width] = '\0';
	}

	int head_x = width / 2, head_y = height /2;
	int tail_x[100], tail_y[100], tail_length =3;
	for (int i = 0; i < tail_length; i++) {
		tail_x[i] = head_x - i - 1;
		tail_y[i] = head_y;
	}
	int dx = -1, dy = 0;
	while (1) {
		// 이동
		int prev_tail_x = tail_x[tail_length - 1], prev_tail_y = tail_y[tail_length - 1];
		for (int i = tail_length - 1; i > 0; i--) {
			tail_x[i] = tail_x[i - 1];
			tail_y[i] = tail_y[i - 1];
		}
		tail_x[0] = head_x;
		tail_y[0] = head_y;
		head_x += dx;
		head_y += dy;

		// 방향키 입력 처리
		if (_kbhit()) {
			char c = _getch();
			if (c == 'a' || c == 'A') { dx = -1; dy = 0; }
			else if (c == 'd' || c == 'D') { dx = 1; dy = 0; }
			else if (c == 'w' || c == 'W') { dx = 0; dy = -1; }
			else if (c == 's' || c == 'S') { dx = 0; dy = 1; }
			else if (c == 27) break;
		}
		if (head_x < 0 || head_x >= width || head_y < 0 || head_y >= height )
		{
			printf("game over");
			break;
		}
		
		if (gameover) break;
		if (head_x == apple_x && head_y == apple_y)
		{
			grid[apple_y][apple_x] = ' ';
			random_number = rand();
			apple_x = (random_number % (width -1 - 1 + 1)) + 1;
			apple_y = (random_number % (height -1 - 1 + 1)) + 1;
			tail_length++;
		}
		// 화면 출력
		system("cls");
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				if (appleeat == false)
				{
					if (y == apple_y && x == apple_x)
					{
						grid[y][x] = 'o';
					}
				}
				if (y == 0 || y == height - 1 || x == 0 || x == width - 1) {
					printf("%c", grid[y][x]);
				}
				else {
					int flag = 0;
					for (int i = 0; i < tail_length; i++) {
						if (tail_x[i] == x && tail_y[i] == y) {
							printf("%c", '+');
							flag = 1;
							break;
						}
					}
					if (flag == 0) {
						printf("%c", grid[y][x]);
					}
				}

				
			}
			printf("\n");
		}
		for (int i = 0; i < tail_length; i++)
		{
			if (head_x == tail_x[i] && head_y == tail_y[i])
			{
				if (tail_length > 3)
				{
					printf("game over");
					gameover = true;
					break;
				}
			}
		}
		// 일시정지
		Sleep(50);
	}

	for (int i = 0; i < height; i++) {
		free(grid[i]);
	}
	free(grid);
	printf("\n다시 시작하기(R)\n타이틀 화면으로 돌아갈까요?(Y/N)\n");
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
		makestage(50, 20);
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

	if (state == 1)
	{
		if (c == 'R' || c == 'r')
		{
			makestage(50, 20);
			screen = 0;
		}
	}


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