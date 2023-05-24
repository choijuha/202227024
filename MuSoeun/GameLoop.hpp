#pragma once
#include "Scene.hpp"
#include "Component.hpp"

using namespace std;

namespace MuSeoun_Engine
{
	class GameLoop
	{
	

	public:
		bool isGameRunning;
		GameLoop() { isGameRunning = false; }
		~GameLoop() {}

		void Run(int screenWidth, int screenHeight)
		{
			screenWidth += 3;
			screenHeight += 3;
			isGameRunning = true;
			bool isapple = true;
			Scene scene(screenWidth, screenHeight);
			Object object;
			Component com;
			Snake snakeHead;
			Apple apple;
			scene.AddObject(&snakeHead);
			snakeHead.SetPosition(15, 5);
			isGameRunning = true;
			com.Start();
			while (isGameRunning)
			{
				if (isapple)
				{
					apple.AppleRender(scene.screenBuffer, scene.screenWidth, scene.screenHeight);
					isapple = false;
				}
				if (snakeHead.tailX.size() >= snakeHead.tailsize && snakeHead.tailY.size() >= snakeHead.tailsize)
				{
					if ((snakeHead.posX + 1) <= 0 || snakeHead.posX >= screenWidth - 2 || (snakeHead.posY + 1) <= 0 || snakeHead.posY >= screenHeight - 2)
					{
						Stop();
						break;
					}
					// 머리가 자신의 꼬리에 충돌하는지 확인
					for (int i = 1; i < snakeHead.tailX.size(); i++)
					{
						if (snakeHead.posX == snakeHead.tailX[i] && snakeHead.posY == snakeHead.tailY[i])
						{
							Stop();
							break;
						}
					}
				}

				scene.Draw();
				snakeHead.Update();
			}
			// 머리가 벽에 충돌하는지 확인
			
		}
		void Stop()
		{
			isGameRunning = false;
		}
	};
}