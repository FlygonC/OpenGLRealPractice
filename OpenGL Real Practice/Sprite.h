#pragma once

#include <GL/glew.h>
#include <GL/wglew.h>
//GLEW includes must precede anything else
#include <GLFW/glfw3.h>

#include <SOIL.h>

class Sprite {
public:
	Sprite();
	void initializeSprite(char* texturePath ,GLuint a_Shader, float a_x, float a_y, float a_width, float a_height);
	void updateGLData();
	void updateData();
	void Draw();

	float width, height, x, y = 0;
	//Matrix4 Vertecies, Colors, UVs;
	float vertexData[16];
	GLuint VBO, Texture, Shader;
};