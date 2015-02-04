#pragma once

#include "SpriteChar.h"
#include <String.h>

#include "FrameWork.h"

class SpriteString {
public:
	SpriteString();
	~SpriteString();
	void InitializeString(char a_input[], char* a_FontPath, float a_x, float a_y, float a_scale);
	void Draw();
	void ProcessString();

	char input[256];
	char* FontPath;
	SpriteChar output;
	float scale, x, y;
};