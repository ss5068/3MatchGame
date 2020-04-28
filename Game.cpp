#include "Game.h"
#include "iostream"
#include <Windows.h>

const time_t CGame::FrameWait = 15;

CGame& CGame::GetInstance() {
	static CGame* Instance = new CGame();
	return *Instance;

}

CGame::CGame() {
	bDestroy = false;
	BeforeTime = 0;
	DeltaTime = 0;
	FrameCount = 0;
}

void CGame::Start() {
	Routine();
}

void CGame::Routine() {
	while (!bDestroy) {
		BeforeTime = clock();

		Tick();
		Render();

		WaitForFramerate();
		
	}
}

void CGame::Tick() {

}

void CGame::Render() {
	std::cout << "FPS : " << (1000.0f / DeltaTime);
	system("cls");
}

void CGame::WaitForFramerate()
{
	DeltaTime = clock() - BeforeTime;
	if (DeltaTime <= FrameWait) {
		Sleep(FrameWait - DeltaTime);
		DeltaTime = FrameWait;
	}
	FrameCount++;
}



