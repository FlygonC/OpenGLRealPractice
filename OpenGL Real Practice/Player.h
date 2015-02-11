#pragma once

#include "SpriteAnimated.h"

class Player {
public:
	Player();
	~Player();
	void Update(float a_deltaTime);

	SpriteAnimated sprite;
	glm::vec2 position;
	glm::vec2 velocity;
	float hitCircle;
	int lives;
};