#pragma once
#include "Scene.hpp"
#include "Component.hpp"

using namespace std;

namespace MuSeoun_Engine
{
	class GameLoop
	{
	private:
		bool isGameRunning;

	public:
		GameLoop() { isGameRunning = false; }
		~GameLoop() {}

		void Run(int screenWidth, int screenHeight)
		{
			isGameRunning = true;
			Scene scene(screenWidth, screenHeight);
			Object object;
			Component com;
			Snake snake;  // Snake °´Ã¼ »ý¼º
			scene.AddObject(&snake);
			snake.SetPosition(15, 5);
			isGameRunning = true;
			com.Start();
			while (isGameRunning)
			{
				scene.Draw();
				com.Update();
			}
		}
		void Stop()
		{
			isGameRunning = false;
		}
	};
}