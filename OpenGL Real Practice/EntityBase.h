#pragma once

#include "Player.h"
#include "SpriteAnimated.h"
#include "FrameWork.h"

class EntityBase {
public:
	EntityBase(void) {}
	~EntityBase(void) {}

	virtual void Update(Player* a_player, float a_deltaTime) = 0;
	bool playerCollision(Player* a_player);

	SpriteAnimated sprite;
	glm::vec2 position;
	bool live;
	float hitCircle;
};