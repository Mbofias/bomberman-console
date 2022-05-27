#pragma once
#include "Console.h"
#include "Map.h"
#include "Vector2D.h"

class Enemy
{
public:
	Enemy();
	~Enemy();

	Vector2D position;

	bool GetAlive();
	void SetAlive(bool alive);
	char GetSprite();
	void SetSprite(char sprite);
	void Draw(Console consola);
	bool Obstacle(Map mapa, int x, int y);
	void Movement(Console consola, Map mapa);

private:
	bool alive = true;
	char sprite;
};

