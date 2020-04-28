#pragma once
#include <ctime>

class CGame
{
public:
	static const time_t FrameWait;
	static CGame& GetInstance();
		 // new ����ƽ ���� �����͸� ����� ���⿡ �Լ��� ��ġ��
	void Start(); // ���� ������ �� ȣ��
private:

	bool bDestroy = false; // ���� ��ü�� �ı��Ǿ�� �ϴ��� ����
	std::time_t BeforeTime; // ������ ó�� �� �ð�
	std::time_t DeltaTime;// ������ ó�� �� �ð� ����
	int FrameCount; // ������ ����

	CGame(); // �̱��� ������ Ű ����Ʈ
	
	void Routine(); // ���α׷� ���� ��ƾ

	void Tick(); // �� �����Ӹ��� ȣ��
	void Render(); // ȭ���� �׷��� �� �� ȣ��
	void WaitForFramerate(); // ������ ���ð����� ������ ���� ������ ���
};

