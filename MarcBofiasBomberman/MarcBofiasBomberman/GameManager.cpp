#include "pch.h"
#include "GameManager.h"

GameManager::GameManager()
{
}
GameManager::~GameManager()
{
}
bool GameManager::GetWin()
{
	return win;
}
void GameManager::DrawLegend(Console consola)
{
	std::cout << std::endl << std::endl;
	std::cout << "\t\t\t\tLEYENDA" << std::endl << std::endl;
	std::cout << "\t\tO->Bomberman\tH->Enemigo\tX->Paredes" << std::endl; 
	std::cout << "\t\tC->Caja\tB->Bomba/Explosion\tS->Escudo(no sirve contra explosiones)" << std::endl;
	std::cout << "\t\tP->Radio de explosion aumentado";
}
void GameManager::EnemiesAlive(Enemy a, Enemy b, Enemy c, Enemy d)
{
	if (!a.GetAlive() && !b.GetAlive() && !c.GetAlive() && !d.GetAlive())
		win = true;
}
void GameManager::EnemyImpact(Bomberman &player, Enemy enemy)
{
	if ((player.position.x == enemy.position.x && player.position.y == enemy.position.y) && enemy.GetAlive())
	{
		if (player.GetShield())
			player.SetShield(false);
		else
			player.SetAlive(false);
	}
}
void GameManager::BoomEnemy(Map map, Explosive bomb, Enemy &enemy)
{
	for (int r = 0; r <= bomb.GetRange(); r++)
	{
		if (bomb.Obstacle(map, bomb.position.y + 1, bomb.position.x))
			if (bomb.position.y + r == enemy.position.y && bomb.position.x == enemy.position.x)
				enemy.SetAlive(false);
		if (bomb.Obstacle(map, bomb.position.y - 1, bomb.position.x))
			if (bomb.position.y - r == enemy.position.y && bomb.position.x == enemy.position.x)
				enemy.SetAlive(false);
		if (bomb.Obstacle(map, bomb.position.y, bomb.position.x + 1))
			if (bomb.position.y == enemy.position.y && bomb.position.x + r == enemy.position.x)
				enemy.SetAlive(false);
		if (bomb.Obstacle(map, bomb.position.y, bomb.position.x - 1))
			if (bomb.position.y== enemy.position.y && bomb.position.x - r == enemy.position.x)
				enemy.SetAlive(false);
	}
}
void GameManager::BoomBomberman(Map map, Explosive bomb, Bomberman &player)
{
	for (int r = 0; r <= bomb.GetRange(); r++)
	{
		if (bomb.Obstacle(map, bomb.position.y + 1, bomb.position.x))
			if (bomb.position.y + r == player.position.y && bomb.position.x == player.position.x)
				player.SetAlive(false);
		if (bomb.Obstacle(map, bomb.position.y - 1, bomb.position.x))
			if (bomb.position.y - r == player.position.y && bomb.position.x == player.position.x)
				player.SetAlive(false);
		if (bomb.Obstacle(map, bomb.position.y, bomb.position.x + 1))
			if (bomb.position.y == player.position.y && bomb.position.x + r == player.position.x)
				player.SetAlive(false);
		if (bomb.Obstacle(map, bomb.position.y, bomb.position.x - 1))
			if (bomb.position.y == player.position.y && bomb.position.x - r == player.position.x)
				player.SetAlive(false);
	}
}
void GameManager::BoomCollectable(Map map, Explosive bomb, Collectable &collectable)
{
	for (int r = 0; r <= bomb.GetRange(); r++)
	{
		if (bomb.Obstacle(map, bomb.position.y + 1, bomb.position.x))
			if (bomb.position.y + r == collectable.position.y && bomb.position.x == collectable.position.x)
				collectable.SetEnabled(false);
		if (bomb.Obstacle(map, bomb.position.y - 1, bomb.position.x))
			if (bomb.position.y - r == collectable.position.y && bomb.position.x == collectable.position.x)
				collectable.SetEnabled(false);
		if (bomb.Obstacle(map, bomb.position.y, bomb.position.x + 1))
			if (bomb.position.y == collectable.position.y && bomb.position.x + r == collectable.position.x)
				collectable.SetEnabled(false);
		if (bomb.Obstacle(map, bomb.position.y, bomb.position.x - 1))
			if (bomb.position.y == collectable.position.y && bomb.position.x - r == collectable.position.x)
				collectable.SetEnabled(false);
	}
}
void GameManager::BoomBox(Map &map, Explosive bomb, Box &box, bool &destroyed)
{
	for (int r = 0; r <= bomb.GetRange(); r++)
	{
		if (bomb.Obstacle(map, bomb.position.y + 1, bomb.position.x))
			if (bomb.position.y + r == box.position.y && bomb.position.x == box.position.x && box.GetEnabled())
			{
				box.Break(map);
				destroyed = true;
			}
		if (bomb.Obstacle(map, bomb.position.y - 1, bomb.position.x))
			if (bomb.position.y - r == box.position.y && bomb.position.x == box.position.x && box.GetEnabled())
			{
				box.Break(map);
				destroyed = true;
			}
		if (bomb.Obstacle(map, bomb.position.y, bomb.position.x + 1))
			if (bomb.position.y == box.position.y && bomb.position.x + r == box.position.x && box.GetEnabled())
			{
				box.Break(map);
				destroyed = true;
			}
		if (bomb.Obstacle(map, bomb.position.y, bomb.position.x - 1))
			if (bomb.position.y == box.position.y && bomb.position.x - r == box.position.x && box.GetEnabled())
			{
				box.Break(map);
				destroyed = true;
			}
	}
}
void GameManager::InitBox(Map map, Box &box, Bomberman player)
{
	do
	{
		box.position.x = 1 + rand() % (map.width - 2);
		box.position.y = 1 + rand() % 8;
	} 
	while (!box.Obstacle(map) || (box.position.x == player.position.x && box.position.y == player.position.x));
}
void GameManager::CollectableSpawn(Box box, Collectable &collectable, bool &destroyed)
{
	if (!box.GetEnabled() && (box.GetNumber() == collectable.GetNumber() ) )
		collectable.SetEnabled(true);

	destroyed = false;
}
void GameManager::PickupShield(Bomberman &player, Shield &shield)
{
	if (player.position.x == shield.position.x && player.position.y == shield.position.y)
		shield.Pickup(player);
}
void GameManager::PickupPowerup(Bomberman &player, PowerUp &powerup)
{
	if (player.position.x == powerup.position.x && player.position.y == powerup.position.y)
		powerup.Pickup(player);
}