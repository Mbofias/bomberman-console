#pragma once
#include <Windows.h>

class Console
{
private:
	HANDLE hnd;

public:
	Console();
	~Console();

	int width;
	int height;

	void SetCursor(int x, int y);
	void PutChar(int x, int y, char sprite);
};