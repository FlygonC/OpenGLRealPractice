#pragma once

#include "EntityBase.h"

class Bomb : public EntityBase {
public:
	Bomb();
	~Bomb();

	void Update(Player* a_player, float a_deltaTime);
};