#pragma once
#include "Bomberman.h"

class Collectable
{
public:
	Collectable();
	Collectable(char sprite);
	~Collectable();

	Vector2D position;

	bool GetEnabled();
	void SetEnabled(bool enabled);
	char GetSprite();
	void SetSprite(char sprite);
	void Draw(Console consola);
	int GetNumber();
	void SetNumber(int num);

protected:
	bool enabled = false;
	char sprite;
	int number;
};