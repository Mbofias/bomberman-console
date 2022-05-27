#pragma once
#include "Vector2D.h"
#include "Map.h"
#include "Console.h"


class Explosive
{
public:
	Explosive();
	Explosive(char sprite);
	~Explosive();

	Vector2D position;

	int GetRange();
	void SetRange(int range);
	char GetSprite();
	void SetSprite(char sprite);
	bool GetBoom();
	void SetBoom(bool boom);
	void Countdown(Map &map, Console consola, int contador);
	void Explosion(Map &map, Console);
	void RemoveExplosion(Map &map, Console);
	void Draw(Console consola);
	bool Obstacle(Map mapa, int y, int x);

private:
	int range = 1;
	char sprite;
	bool boom = false;
};

