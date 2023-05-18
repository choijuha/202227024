#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;
bool IsGameRunning = false;
bool isStart = false;
class Scene
{

public: 
	vector<char> ScreenBuffer;
	void MakeStage(int w, int h)
	{
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (i == 0 || i == h - 1 || j == 0 || j == w - 1) 
				{
					ScreenBuffer[i * w + j] = '*';
				}
			}
		}
	}
private:
	
	vector<string> Hierarchy;

};
class Object
{

};
class Component
{

};
void Start()
{
	std::cout << "시작";
}
void Update()
{
	Scene s;
	s.MakeStage(20, 13);
	std::string str(s.ScreenBuffer.begin(), s.ScreenBuffer.end());
	cout << str;
}
int main()
{
	isStart = true;
	IsGameRunning = true;
	while (IsGameRunning)
	{
		if (isStart)
		{
			Start();
			isStart = false;
		}
		Update();
	}
}