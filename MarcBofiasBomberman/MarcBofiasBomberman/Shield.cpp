#include "pch.h"
#include "Shield.h"

Shield::Shield()
{
	sprite = 'S';
}
Shield::Shield(char sprite) : Collectable(sprite)
{
}
Shield::~Shield()
{
}
bool Shield::GetShield()
{
	return shield;
}
void Shield::SetShield(bool shield)
{
	this->shield = shield;
}
void Shield::Pickup(Bomberman &player)
{
	player.SetShield(shield);
	enabled = false;
}