#pragma once
#include <iostream>
#include "Map.h"
#include "Bomberman.h"
#include "Collectable.h"
#include "Explosive.h"
#include "Box.h"
#include "Enemy.h"
#include "Shield.h"
#include "Powerup.h"

class GameManager
{
public:
	GameManager();
	~GameManager();

	bool GetWin();
	void DrawLegend(Console consola);
	void EnemiesAlive(Enemy a, Enemy b, Enemy c, Enemy d);
	void EnemyImpact(Bomberman &player, Enemy enemy);
	void BoomEnemy(Map map, Explosive bomb, Enemy &enemy);
	void BoomBomberman(Map map, Explosive bomb, Bomberman &player);
	void BoomCollectable(Map map, Explosive bomb, Collectable &collectable);
	void BoomBox(Map &map, Explosive bomb, Box &box, bool &destroyed);
	void InitBox(Map map, Box &box, Bomberman player);
	void CollectableSpawn(Box box, Collectable &collectable, bool &destroyed);
	void PickupShield(Bomberman &player, Shield &shield);
	void PickupPowerup(Bomberman &player, PowerUp &powerup);

private:
	int bombsUsed = 0;
	bool win = false;
};

