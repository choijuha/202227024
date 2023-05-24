#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <thread>
#include <random>
#include "GameLoop.hpp"

using namespace std;

namespace MuSeoun_Engine
{
    class Object {
    public:
        int posX;
        int posY;

        void SetPosition(int x, int y) {
            posX = x;
            posY = y;
        }

        virtual void Render(std::vector<char>& screenBuffer, int screenWidth) { }
    };
    class Apple : public Object
    {
    public:
        int AppleposX;
        int ApplePosY;
        void AppleRender(std::vector<char>& screenBuffer, int screenWidth, int screenHeight)
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> distX(1, screenWidth - 1);
            std::uniform_int_distribution<int> distY(1, screenHeight - 1);

            AppleposX = distX(gen);
            ApplePosY = distY(gen);
            int index = (ApplePosY + 1) * (screenWidth + 1) + AppleposX + 1;
            screenBuffer[index] = '@';
        }
    };

    class Snake : public Object
    {
    public:
        std::vector<int> tailX;
        std::vector<int> tailY;
        int tailsize = 10;
        int dx = 1, dy = 0;
        void Render(std::vector<char>& screenBuffer, int screenWidth) override {
            int index = (posY + 1) * (screenWidth + 1) + posX + 1;
            screenBuffer[index] = 'o';

            // 꼬리 그리기
            for (int i = 0; i < tailX.size(); i++) {
                index = (tailY[i] + 1) * (screenWidth + 1) + tailX[i] + 1;
                screenBuffer[index] = 'o';
            }
        }

        void Move(int dx, int dy) {
            // 꼬리를 따라 뱀의 위치를 이동
            if (tailX.size() > 0) {
                tailX.pop_back();
                tailY.pop_back();
                tailX.insert(tailX.begin(), posX);
                tailY.insert(tailY.begin(), posY);
            }

            // 머리를 새로운 위치로 이동
            posX += dx;
            posY += dy;

            // 꼬리를 따라 이동한 뱀의 위치를 기록
            if (tailX.size() < tailsize)
            {
                tailX.insert(tailX.begin(), posX);
            }
            if (tailY.size() < tailsize)
            {
                tailY.insert(tailY.begin(), posY);
            }
        }
        void Update()
        {
            if (_kbhit())
            {
                char c = _getch();
                if ((c == 'a' || c == 'A'))
                {
                    // 왼쪽으로 회전
                    if (dx == 1)
                    {
                        dx = 0;
                        dy = -1;
                    }
                    else if (dx == -1)
                    {
                        dx = 0;
                        dy = 1;
                    }
                    else if (dy == 1)
                    {
                        dx = 1;
                        dy = 0;
                    }
                    else if (dy == -1)
                    {
                        dx = -1;
                        dy = 0;
                    }
                }
                else if ((c == 'd' || c == 'D'))
                {
                    // 오른쪽으로 회전
                    if (dx == 1)
                    {
                        dx = 0;
                        dy = 1;
                    }
                    else if (dx == -1)
                    {
                        dx = 0;
                        dy = -1;
                    }
                    else if (dy == 1)
                    {
                        dx = -1;
                        dy = 0;
                    }
                    else if (dy == -1)
                    {
                        dx = 1;
                        dy = 0;
                    }
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // 100ms 딜레이
            Move(dx, dy);
        }
    };
}