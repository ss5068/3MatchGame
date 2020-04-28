#pragma once
struct FPoint{
	short X;
	short Y; // short인 이유는 Windows API가 short임.

	FPoint();
	FPoint(short InX, short InY);

	// 연산자 오버로딩
};

