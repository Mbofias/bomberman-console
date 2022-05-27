#pragma once
#include "Vector2D.h"
#include "Map.h"
#include "Explosive.h"
#include "Console.h"
#include <conio.h>
#include <windows.h>

class Bomberman
{
public:
	Bomberman();
	Bomberman(Vector2D position, char sprite);
	~Bomberman();

	Vector2D position;

	int GetBombRange();
	void SetBombRange(int bombRange);
	char GetSprite();
	void SetSprite(char sprite);
	bool GetAlive();
	void SetAlive(bool alive);
	bool GetCountdown();
	void SetCountdown(bool counting);
	bool GetShield();
	void SetShield(bool shield);
	void Draw(Console);
	bool Obstacle(Map, int, int);
	void PlaceBomb(Explosive &bomb, Map &mapa, Console);
	char GetInput();
	void MovementInput(Map &mapa, Console consola, Explosive &bomb);

private:
	int bombRange = 1;
	bool countdown = false;
	bool alive = true;
	char sprite;
	bool shield = false;
};

