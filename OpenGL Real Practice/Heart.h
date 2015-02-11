#pragma once

#include "EntityBase.h"

class Heart : public EntityBase {
public:
	Heart();
	~Heart();

	void Update(Player* a_player, float a_deltaTime);
};