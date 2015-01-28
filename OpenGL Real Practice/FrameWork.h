#pragma once

#include <GL/glew.h>
#include <GL/wglew.h>
//GLEW includes must precede anything else
#include <GLFW/glfw3.h>

#include <SOIL.h>
#include <iostream>

class FrameWork {
public:
	FrameWork();
	~FrameWork();

	GLFWwindow* window;
	GLuint vertexShader;
	GLuint fragmentShader;
	GLuint fragmentShaderTextured;
	GLuint shaderProgram, shaderProgramTextured;
};