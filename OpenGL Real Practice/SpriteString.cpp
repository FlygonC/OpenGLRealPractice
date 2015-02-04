#pragma once

#include "SpriteString.h"

SpriteString::SpriteString() {}

SpriteString::~SpriteString() {}

void SpriteString::InitializeString(char a_input[], char* a_FontPath, float a_x, float a_y, float a_scale) {
	for (int i = 0; i < strlen(a_input); i++) {
		input[i] = a_input[i];
	}
	FontPath = a_FontPath;
	x = a_x;
	y = a_y;
	scale = a_scale;

	output.initializeSprite("TestFont.png", x, y, scale, scale);
}

void SpriteString::ProcessString() {
	
}

void SpriteString::Draw() {
	for (int i = 0; i < strlen(input); i++) {
		output.x = x+i*(scale);
		output.code = (int)input[i];
		//output[i].y = y;
		//output[i].width = scale;
		//output[i].height = scale;
		output.updateData();
		output.Draw();
	}
}