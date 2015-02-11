#pragma once

#include "Player.h"

Player::Player() {
	position = glm::vec2(200,200);
	velocity = glm::vec2(0, 0);
	hitCircle = 10;

	sprite.initializeSprite("PlayerSprite.png", position.x, position.y, 40, 40);
	sprite.makeBasicStructure(4, 1);
	sprite.setAnimation(0, 0, 3, LOOP);
	sprite.playAnimation(0);
	sprite.fps = 24;
}

Player::~Player() {

}

void Player::Update(float a_deltaTime) {
	//movement
	if (FrameWork::getKeyPressed(GLFW_KEY_W)) {
		velocity.y += 500 * a_deltaTime;
	}
	if (FrameWork::getKeyPressed(GLFW_KEY_S)) {
		velocity.y -= 500 * a_deltaTime;
	}
	if (FrameWork::getKeyPressed(GLFW_KEY_D)) {
		velocity.x += 500 * a_deltaTime;
	}
	if (FrameWork::getKeyPressed(GLFW_KEY_A)) {
		velocity.x -= 500 * a_deltaTime;
	}

	/*if (velocity.x < 0) {
		velocity.x += 100 * a_deltaTime;
	}
	else if (velocity.x > 0) {
		velocity.x -= 100 * a_deltaTime;
	}
	if (velocity.y < 0) {
		velocity.y += 100 * a_deltaTime;
	}
	else if (velocity.y > 0) {
		velocity.y -= 100 * a_deltaTime;
	}*/
	//maximum velocity caps
	if (velocity.x >= 200) {
		velocity.x = 200;
	}
	if (velocity.x <= -200) {
		velocity.x = -200;
	}
	if (velocity.y >= 200) {
		velocity.y = 200;
	}
	if (velocity.y <= -200) {
		velocity.y = -200;
	}
	//collision with screen edges
	if (position.y <= 15 && velocity.y < 0) {
		position.y = 15;
		velocity.y *= -1;
	}
	if (position.y >= 400 - 15 && velocity.y > 0) {
		position.y = 400 - 15;
		velocity.y *= -1;
	}
	if (position.x <= 15 && velocity.x < 0) {
		position.x= 15;
		velocity.x *= -1;
	}
	if (position.x >= 800 - 15 && velocity.x > 0) {
		position.x = 800 - 15;
		velocity.x *= -1;
	}
	//apply movment
	if (velocity.x != 0) {
		position.x += (velocity.x * abs(glm::normalize(velocity).x)) * a_deltaTime;
	}
	if (velocity.y != 0) {
		position.y += (velocity.y * abs(glm::normalize(velocity).y)) * a_deltaTime;
	}
	//Sprite update
	sprite.position = position;
	//sprite.x = position.x;
	//sprite.y = position.y;
	sprite.Update();
	sprite.Draw();
	
}