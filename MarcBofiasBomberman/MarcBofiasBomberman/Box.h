#pragma once
#include <stdlib.h>
#include "Vector2D.h"
#include "Map.h"
#include "Collectable.h"

class Box
{
public:
	Box();
	~Box();
	char GetSprite();
	void SetSprite(char sprite);
	bool GetEnabled();
	void Break(Map &map);
	bool Obstacle(Map map);
	void Draw(Map &map, Console);
	int GetNumber();
	void SetNumber(int num);

	Vector2D position;

private:
	char sprite;
	bool enabled = true;
	int number;
};

