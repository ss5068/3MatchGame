#pragma once
#include <ctime>

class CGame
{
public:
	static const time_t FrameWait;
	static CGame& GetInstance();
		 // new 스태틱 변수 포인터를 만들고 여기에 함수를 매치함
	void Start(); // 게임 시작할 때 호출
private:

	bool bDestroy = false; // 게임 객체가 파괴되어야 하는지 여부
	std::time_t BeforeTime; // 프레임 처리 전 시간
	std::time_t DeltaTime;// 프레임 처리 후 시간 차이
	int FrameCount; // 프레임 갯수

	CGame(); // 싱글턴 패턴의 키 포인트
	
	void Routine(); // 프로그램 메인 루틴

	void Tick(); // 매 프레임마다 호출
	void Render(); // 화면을 그려야 할 때 호출
	void WaitForFramerate(); // 정해진 대기시간보다 빠르게 일이 끝나면 대기
};

