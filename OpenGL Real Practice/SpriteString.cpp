#pragma once

#include "SpriteString.h"

SpriteString::SpriteString() {}

SpriteString::~SpriteString() {}

void SpriteString::InitializeString(const char* a_input, const char* a_FontPath, float a_x, float a_y, float a_scale) {
	for (int i = 0; i < strlen(a_input)+1; i++) {
		input[i] = a_input[i];
	}
	//FontPath = a_FontPath;
	x = a_x;
	y = a_y;
	scale = a_scale;

	output.initializeSprite(a_FontPath, x, y, scale, scale);
	output.makeBasicStructure(16, 16);
}

void SpriteString::Draw() {
	//int testLength = strlen(input);
	int i = 0;
	while (input[i] != '\0') {
		output.x = x+i*(scale);

		output.playFrame(input[i]);
		output.Draw();
		i++;
	}
}

void SpriteString::makeBasicStructure(int a_width, int a_height) {
	/*for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			frames[(i*16) + j].x0 = (a_width / 16)*j;
			frames[(i*16) + j].x1 = (a_width / 16)*j + (a_width / 16);

			frames[(i*16) + j].y0 = (a_height / 16)*i;
			frames[(i*16) + j].y1 = (a_height / 16)*i + (a_height / 16);
		}
	}*/
}