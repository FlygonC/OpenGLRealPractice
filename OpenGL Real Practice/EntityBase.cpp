#pragma once

#include "EntityBase.h"


bool EntityBase::playerCollision(Player* a_player) {
	if (glm::length(position - a_player->position) <= a_player->hitCircle + hitCircle) {
		return true;
	}
	else {
		return false;
	}
}