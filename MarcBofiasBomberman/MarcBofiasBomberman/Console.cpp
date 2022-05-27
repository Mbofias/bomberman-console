#include "pch.h"
#include "Console.h"

Console::Console()
{
	hnd = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO ci;
	GetConsoleScreenBufferInfo(hnd, &ci);

	width = ci.srWindow.Right - ci.srWindow.Left + 1;
	height = ci.srWindow.Bottom - ci.srWindow.Top + 1;
}
Console::~Console()
{
}
void Console::SetCursor(int x, int y)
{
	if (x < 0 || x >= width)
		return;
	if (y < 0 || y >= height)
		return;

	COORD coordenadas;
	coordenadas.X = x;
	coordenadas.Y = y;
	SetConsoleCursorPosition(hnd, coordenadas);
}
void Console::PutChar(int x, int y, char sprite)
{
	SetCursor(x, y);
	WriteConsoleA(hnd, &sprite, 1, NULL, NULL);
}