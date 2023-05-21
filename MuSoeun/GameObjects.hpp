#pragma once
#include <iostream>
#include <vector>
#include <windows.h>

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

    class Snake : public Object
    {
    public:
        void Render(std::vector<char>& screenBuffer, int screenWidth) override {
            int index = (posY + 1) * (screenWidth + 1) + posX + 1;
            screenBuffer[index] = 'o';
             index = (posY + 1) * (screenWidth + 1) + posX + 2;
            screenBuffer[index] = 'o';
             index = (posY + 1) * (screenWidth + 1) + posX + 3;
            screenBuffer[index] = 'o';
            index = (posY + 2) * (screenWidth + 1) + posX + 1;
            screenBuffer[index] = 'o';
        }
    };
}