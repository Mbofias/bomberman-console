#include "pch.h"
#include "Explosive.h"

Explosive::Explosive()
{
}
Explosive::Explosive(char sprite)
{
	this->sprite = sprite;
}
Explosive::~Explosive()
{
}
int Explosive::GetRange()
{
	return range;
}
void Explosive::SetRange(int range)
{
	this->range = range;
}
char Explosive::GetSprite()
{
	return sprite;
}
void Explosive::SetSprite(char sprite)
{
	this->sprite = sprite;
}
bool Explosive::GetBoom()
{
	return boom;
}
void Explosive::SetBoom(bool boom)
{
	this->boom = boom;
}
void Explosive::Countdown(Map &map, Console consola, int contador)
{
	if (contador < 10)
		Draw(consola);
	if (contador >= 10 && contador < 15)
	{
		Explosion(map, consola);
		boom = true;
	}
	if (contador == 15)
	{
		boom = false;
		RemoveExplosion(map, consola);
	}
}
void Explosive::Explosion(Map &map, Console consola)
{
	for (int r = 0; r <= range; r++)
	{
		if (Obstacle(map, position.y + 1, position.x) && (position.y + r < 12))
		{
			consola.PutChar(position.x, position.y + r, sprite);
			map.SetPosition(sprite, Vector2D(position.x, position.y + r));
		}
		if (Obstacle(map, position.y - 1, position.x) && (position.y - r > 0))
		{
			consola.PutChar(position.x, position.y - r, sprite);
			map.SetPosition(sprite, Vector2D(position.x, position.y - r));
		}
		if (Obstacle(map, position.y, position.x + 1) && (position.x + r < 12))
		{
			consola.PutChar(position.x + r, position.y, sprite);
			map.SetPosition(sprite, Vector2D(position.x + r, position.y));
		}
		if (Obstacle(map, position.y, position.x - 1) && (position.x - r > 0))
		{
			consola.PutChar(position.x - r, position.y, sprite);
			map.SetPosition(sprite, Vector2D(position.x - r, position.y));
		}
	}
}
void Explosive::RemoveExplosion(Map &map, Console consola)
{
	for (int r = 0; r <= range; r++)
	{
		if (Obstacle(map, position.y + 1, position.x) && (position.y + r < 12))
		{
			map.SetPosition(' ', Vector2D(position.x, position.y + r));
			consola.PutChar(position.x, position.y + r, ' ');
		}
		if (Obstacle(map, position.y - 1, position.x) && (position.y - r > 0))
		{
			map.SetPosition(' ', Vector2D(position.x, position.y - r));
			consola.PutChar(position.x, position.y - r, ' ');
		}
		if (Obstacle(map, position.y, position.x + 1) && (position.x + r < 12))
		{
			map.SetPosition(' ', Vector2D(position.x + r, position.y));
			consola.PutChar(position.x + r, position.y, ' ');
		}
		if (Obstacle(map, position.y, position.x - 1) && (position.x - r > 0))
		{
			map.SetPosition(' ', Vector2D(position.x - r, position.y));
			consola.PutChar(position.x - r, position.y, ' ');
		}
	}
}
void Explosive::Draw(Console consola)
{
	consola.PutChar(position.x, position.y, sprite);
}
bool Explosive::Obstacle(Map mapa, int y, int x)
{
	switch (mapa.GetMap(y, x))
	{
	case 'X':
		return false;
		break;
	case 'C':
	default:
		return true;
	}
}