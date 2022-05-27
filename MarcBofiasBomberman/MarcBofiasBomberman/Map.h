#pragma once
#include "Vector2D.h"
#include "Console.h"

class Map
{
public:
	Map();
	~Map();

	static const int height = 13, width = 13;

	char GetMap(int y, int x);
	void SetPosition(char sprite, Vector2D position);
	void Reset();
	void Draw(Console consola);
	bool LokingFor(char sprite);

private: 
	
	char nom[7];
	char map[height][width];
};

