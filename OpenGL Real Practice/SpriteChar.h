#pragma once

#include <GL/glew.h>
#include <GL/wglew.h>
//GLEW includes must precede anything else
#include <GLFW/glfw3.h>

#include <SOIL.h>

#include "FrameWork.h"

class SpriteChar {
public:
	SpriteChar();
	void initializeSprite(char* texturePath, float a_x, float a_y, float a_width, float a_height);
	void updateGLData();
	void updateData();
	void Draw();

	float width, height, sheetWidth, sheetHeight, x, y = 0;
	int code, row, column = 0;
	//Matrix4 Vertecies, Colors, UVs;
	float vertexData[16];
	GLuint VBO, Texture;
};