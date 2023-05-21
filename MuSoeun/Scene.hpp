#pragma once
#include "GameObjects.hpp"

namespace MuSeoun_Engine
{

    class Scene {
    private:
        std::vector<Object*> hierarchy;
        std::vector<char> screenBuffer;
        int screenWidth;
        int screenHeight;

    public:
        Scene(int width, int height) : screenWidth(width), screenHeight(height) {
            screenBuffer.resize(screenWidth * screenHeight, ' ');  // 스크린 버퍼 크기 설정
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
            screenBuffer.resize(w * h + h, '*');  // 개행 문자를 추가하기 위해 공간을 확보

            for (int i = 0; i < h; ++i) {
                for (int j = 0; j < w; ++j) {
                    int index = i * (w + 1) + j;  // 개행 문자 공간을 고려하여 인덱스 계산
                    if (j == 0 || j == w - 1 || i == 0 || i == h - 1)
                        screenBuffer[index] = '*';  // 테두리는 '*'로 유지
                    else
                        screenBuffer[index] = ' ';  // 내부 공백으로 변경
                }
                screenBuffer[(i + 1) * (w + 1) - 1] = '\n';
                screenBuffer[(i + 1) * (w + 1) - 2] = '*';  // 개행 문자 뒤에 별 추가
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

}