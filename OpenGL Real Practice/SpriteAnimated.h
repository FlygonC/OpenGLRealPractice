#pragma once

#include <GL/glew.h>
#include <GL/wglew.h>
//GLEW includes must precede anything else
#include <GLFW/glfw3.h>

#include <SOIL.h>

class SpriteAnimated {
public:
	SpriteAnimated();
	void initializeSprite(char* texturePath, GLuint a_Shader, float a_x, float a_y, float a_width, float a_height);
	void updateGLData();
	void updateData();
	void Draw();
	void initializeAnimation(float a_frameWidth, float a_frameHeight, int a_numOfFrames);

	float width, frameWidth, sheetWidth, frameNormWidth, height, frameHeight, frameNormHeight, sheetHeight, x, y = 0;
	int numFrames, currentFrame;
	//Matrix4 Vertecies, Colors, UVs;
	float vertexData[16];
	float UVData[8];
	GLuint VBO, Texture, Shader;
};