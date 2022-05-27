#include "pch.h"
#include "Box.h"

Box::Box()
{
	sprite = 'C';
}
Box::~Box()
{
}
char Box::GetSprite()
{
	return sprite;
}
void Box::SetSprite(char sprite)
{
	this->sprite = sprite;
}
bool Box::GetEnabled()
{
	return enabled;
}
void Box::Break(Map &map)
{
	map.SetPosition(' ', position);
	enabled = false;
}
bool Box::Obstacle(Map mapa)
{
	char map = mapa.GetMap(position.y, position.x);
	
	if (map == 'X' || map == 'C')
		return false;
	else
		return true;
}
void Box::Draw(Map &map, Console consola)
{
	map.SetPosition(sprite, position);
	consola.PutChar(position.x, position.y, sprite);
}
int Box::GetNumber()
{
	return number;
}
void Box::SetNumber(int num)
{
	number = num;
}