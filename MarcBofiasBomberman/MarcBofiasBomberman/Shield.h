#pragma once
#include "Collectable.h"

class Shield : public Collectable
{
public:
	Shield();
	Shield(char sprite);
	~Shield();
	bool GetShield();
	void SetShield(bool shield);
	void Pickup(Bomberman &player);

private:
	bool shield;
};

