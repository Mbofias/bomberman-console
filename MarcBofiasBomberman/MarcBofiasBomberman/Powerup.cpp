#include "pch.h"
#include "Powerup.h"

PowerUp::PowerUp()
{
	sprite = 'P';
}
PowerUp::PowerUp(char sprite) : Collectable(sprite)
{
}
PowerUp::~PowerUp()
{
}
int PowerUp::GetRange()
{
	return range;
}
void PowerUp::SetRange(int range)
{
	this->range = range;
}
void PowerUp::Pickup(Bomberman &player)
{
	player.SetBombRange(player.GetBombRange() + range);
	enabled = false;
}