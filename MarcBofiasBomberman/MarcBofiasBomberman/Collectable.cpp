#include "pch.h"
#include "Collectable.h"

Collectable::Collectable()
{
}
Collectable::Collectable(char sprite)
{
	this->sprite = sprite;
}
Collectable::~Collectable()
{
}
bool Collectable::GetEnabled()
{
	return enabled;
}
void Collectable::SetEnabled(bool enabled)
{
	this->enabled = enabled;
}
char Collectable::GetSprite()
{
	return sprite;
}
void Collectable::SetSprite(char sprite)
{
	this->sprite = sprite;
}
void Collectable::Draw(Console consola)
{
	if(enabled)
		consola.PutChar(position.x, position.y, sprite);
}
int Collectable::GetNumber()
{
	return number;
}
void Collectable::SetNumber(int num)
{
	number = num;
}