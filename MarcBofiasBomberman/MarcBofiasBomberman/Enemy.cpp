#include "pch.h"
#include "Enemy.h"

Enemy::Enemy()
{
	sprite = 'H';
	position.y = 11;
}
Enemy::~Enemy()
{
}
bool Enemy::GetAlive()
{
	return alive;
}
void Enemy::SetAlive(bool alive)
{
	this->alive = alive;
}
char Enemy::GetSprite()
{
	return sprite;
}
void Enemy::SetSprite(char sprite)
{
	this->sprite = sprite;
}
void Enemy::Draw(Console consola)
{
	if(alive)
		consola.PutChar(position.x, position.y, sprite);
}
bool Enemy::Obstacle(Map mapa, int x, int y)
{
	char map = mapa.GetMap(y, x);

	if (map == 'X' || map == 'C')
		return false;
	else
		return true;
}
void Enemy::Movement(Console consola, Map mapa)
{
	int direction = rand() % 6;

	Sleep(30);

	consola.PutChar(position.x, position.y, ' ');

	switch (direction)
	{
	case 0:
		if (Obstacle(mapa, position.y - 1, position.x))
			position.y--;
		break;
	case 1:
		if (Obstacle(mapa, position.y + 1, position.x))
			position.y++;
		break;
	case 2:
		if (Obstacle(mapa, position.y, position.x - 1))
			position.x--;
		break;
	case 3:
		if (Obstacle(mapa, position.y, position.x + 1))
			position.x++;
		break;
	default:
		break;
	}
}