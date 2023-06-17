#pragma once
#include "GameObjects.hpp"

using namespace MuSeoun_Engine;

    class Scene {
    public:
        std::vector<Object*> hierarchy;
         std::vector<char> screenBuffer;
         int screenWidth;
         int screenHeight;
        Scene(int width, int height) : screenWidth(width), screenHeight(height) {
            screenBuffer.resize(screenWidth * screenHeight, ' '); 
        }
        ~Scene() {}
        void SetCursorState(bool visible)
        {
            CONSOLE_CURSOR_INFO consoleCursorInfo;
            consoleCursorInfo.bVisible = visible;
            consoleCursorInfo.dwSize = 1;
            SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursorInfo);
        }
        void MakeStage(std::vector<char>& screenBuffer, int w, int h) 
        {
            COORD position = { 0 , 0 };
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
            screenBuffer.resize(w * h + h, '*'); 

            for (int i = 0; i < h; ++i) {
                for (int j = 0; j < w; ++j) {
                    int index = i * (w + 1) + j; 
                    if (j == 0 || j == w - 1 || i == 0 || i == h - 1)
                        screenBuffer[index] = '*';  
                    else
                        screenBuffer[index] = ' '; 
                }
                screenBuffer[(i + 1) * (w + 1) - 1] = '\n';
                screenBuffer[(i + 1) * (w + 1) - 2] = '*'; 
            }
        }

        void AddObject(Object* object) {
            hierarchy.push_back(object);
        }
        void Draw() {
            SetCursorState(false);
            MakeStage(screenBuffer, screenWidth, screenHeight);

            for (Object* object : hierarchy) {
                object->Render(screenBuffer, screenWidth);
            }

            std::cout.write(screenBuffer.data(), screenBuffer.size());
        }
    };