#pragma once

#include "Heart.h"

Heart::Heart() {
	position = glm::vec2(-20, 200);
	hitCircle = 20;

	sprite.initializeSprite("HeartSprite.png", position.x, position.y, 40, 40);
	sprite.makeBasicStructure(3, 1);
	sprite.setAnimation(0, 0, 2, LOOP);
	sprite.playAnimation(0);
	sprite.fps = 5;
}

Heart::~Heart() {

}

void Heart::Update(Player* a_player, float a_deltaTime) {

	position.x -= 100 * a_deltaTime;

	if (position.x < -20) {
		live = true;
		position = glm::vec2(rand() % 800 + 1620, rand() % 340 + 20);
	}

	if (live) {
		sprite.position = position;
		sprite.Update();
		sprite.Draw();
		if (playerCollision(a_player)) {
			live = false;
			a_player->lives += 1;
		}
	}
}