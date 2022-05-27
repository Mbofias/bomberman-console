#pragma once
#include "Collectable.h"

class PowerUp : public Collectable
{
public:
	PowerUp();
	PowerUp(char sprite);
	~PowerUp();

	int GetRange();
	void SetRange(int);
	void Pickup(Bomberman &player);

private:
	int range = 1;
};

