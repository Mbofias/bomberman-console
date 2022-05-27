#include "pch.h"
#include "Bomberman.h"

Bomberman::Bomberman()
{
}
Bomberman::Bomberman(Vector2D position, char sprite)
{
	this->position = position;
	this->sprite = sprite;
}
Bomberman::~Bomberman()
{
}
int Bomberman::GetBombRange()
{
	return bombRange;
}
void Bomberman::SetBombRange(int bombRange)
{
	this->bombRange = bombRange;
}
char Bomberman::GetSprite()
{
	return sprite;
}
void Bomberman::SetSprite(char sprite)
{
	this->sprite = sprite;
}
bool Bomberman::GetAlive()
{
	return alive;
}
void Bomberman::SetAlive(bool alive)
{
	this->alive = alive;
}
bool Bomberman::GetCountdown()
{
	return countdown;
}
void Bomberman::SetCountdown(bool countdown)
{
	this->countdown = countdown;
}
bool Bomberman::GetShield()
{
	return shield;
}
void Bomberman::SetShield(bool shield)
{
	this->shield = shield;
}
void Bomberman::Draw(Console consola)
{
	consola.PutChar(position.x, position.y, sprite);
}
bool Bomberman::Obstacle(Map mapa, int y, int x)
{
	char map = mapa.GetMap(y, x);

	if (map == 'X' || map == 'C')
		return false;
	else
		return true;
}
void Bomberman::PlaceBomb(Explosive &bomb, Map &mapa, Console consola)
{
	countdown = true;
	bomb.position.x = position.x;
	bomb.position.y = position.y;
	bomb.SetRange(bombRange);
	bomb.Draw(consola);
}
char Bomberman::GetInput()
{
	char tecla;

	Sleep(30);

	if (_kbhit())
	{
		tecla = _getch();
		tecla = toupper(tecla);

		switch (tecla)
		{
		case 'W':
		case 'S':
		case 'A':
		case 'D':
		case ' ':
			return tecla;
			break;
		default:
			return '\0';
			break;
		}
	}
	else
		return '\0';
}
void Bomberman::MovementInput(Map &mapa, Console consola, Explosive &bomb)
{
	char direction = GetInput();

	consola.PutChar(position.x, position.y, ' ');

	switch (direction)
	{
	case 'W':
		if (Obstacle(mapa, position.y - 1, position.x))
			position.y--;
		break;
	case 'S':
		if (Obstacle(mapa, position.y + 1, position.x))
			position.y++;
		break;
	case 'A':
		if (Obstacle(mapa, position.y, position.x - 1))
			position.x--;
		break;
	case 'D':
		if (Obstacle(mapa, position.y, position.x + 1))
			position.x++;
		break;
	case ' ':
		if (!countdown)
		{
			PlaceBomb(bomb, mapa, consola);
		}
		break;
	default:
		break;
	}

	consola.PutChar(position.x, position.y, sprite);
}