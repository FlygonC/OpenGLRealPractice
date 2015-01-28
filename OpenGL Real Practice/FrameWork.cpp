#pragma once

#include "FrameWork.h"

FrameWork::FrameWork() {
	//Start GLFW #########
	glfwInit();
	//Set GLFW Window settings
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	//Create Window
	window = glfwCreateWindow(800, 800, "OpenGL", nullptr, nullptr); // Windowed
	//GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", glfwGetPrimaryMonitor(), nullptr); // Fullscreen
	glfwMakeContextCurrent(window);
	//Start GLEW ##########
	glewExperimental = GL_TRUE;
	glewInit();
	//Other GL things #########
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//Shaders #########
	//Shader Copilation #########
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	const GLchar* vertexSource =
		"#version 430\n"
		"layout(location = 0) in vec2 position;"
		"layout(location = 1) in vec4 colorIn;"
		"layout(location = 2) in vec2 UVIn;"
		"out vec4 colorOut;"
		"out vec2 UVOut;"
		"void main(){"
		"	colorOut = colorIn;"
		"	UVOut = UVIn;"
		"	gl_Position = vec4(position, 0.0, 1.0);"
		"}";
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);
	{
		GLint status;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
		char buffer[512];
		glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
		printf(buffer);
	}

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	const GLchar* fragmentSource =
		"#version 430\n"
		"in vec4 colorOut;"
		"in vec2 UVOut;"
		"out vec4 outColor;"
		"uniform sampler2D tex;"
		"void main(){"
		//"	outColor = texture(tex, UVOut) * vec4(colorOut);"
		"	outColor = vec4(colorOut);"
		"}";
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	{
		GLint status;
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
		char buffer[512];
		glGetShaderInfoLog(fragmentShader, 512, NULL, buffer);
		printf(buffer);
	}
	fragmentShaderTextured = glCreateShader(GL_FRAGMENT_SHADER);
	const GLchar* fragmentSourceTextured =
		"#version 430\n"
		"in vec2 UVOut;"
		"out vec4 outColor;"
		"uniform sampler2D tex;"
		"void main(){"
		"	outColor = texture(tex, UVOut);"
		"}";
	glShaderSource(fragmentShaderTextured, 1, &fragmentSourceTextured, NULL);
	glCompileShader(fragmentShaderTextured);
	{
		GLint status;
		glGetShaderiv(fragmentShaderTextured, GL_COMPILE_STATUS, &status);
		char buffer[512];
		glGetShaderInfoLog(fragmentShaderTextured, 512, NULL, buffer);
		printf(buffer);
	}
	//Build Program 1
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	//Build Program 2
	shaderProgramTextured = glCreateProgram();
	glAttachShader(shaderProgramTextured, vertexShader);
	glAttachShader(shaderProgramTextured, fragmentShaderTextured);
	glLinkProgram(shaderProgramTextured);
	//Texture Settings
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}
FrameWork::~FrameWork() {
	glDeleteProgram(shaderProgram);
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);
	glfwTerminate();
}

/*
#include <GL/glew.h>
#include <GL/wglew.h>
//GLEW includes must precede anything else
#include <GLFW/glfw3.h>

#include <SOIL.h>
#include <iostream>

class FrameWork {
public:
	FrameWork() {
		//Start GLFW #########
		glfwInit();
		//Set GLFW Window settings
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
		//Create Window
		window = glfwCreateWindow(800, 800, "OpenGL", nullptr, nullptr); // Windowed
		//GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", glfwGetPrimaryMonitor(), nullptr); // Fullscreen
		glfwMakeContextCurrent(window);
		//Start GLEW ##########
		glewExperimental = GL_TRUE;
		glewInit();
		//Other GL things #########
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		//Shaders #########
		//Shader Copilation #########
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		const GLchar* vertexSource =
			"#version 430\n"
			"layout(location = 0) in vec2 position;"
			"layout(location = 1) in vec4 colorIn;"
			"layout(location = 2) in vec2 UVIn;"
			"out vec4 colorOut;"
			"out vec2 UVOut;"
			"void main(){"
			"	colorOut = colorIn;"
			"	UVOut = UVIn;"
			"	gl_Position = vec4(position, 0.0, 1.0);"
			"}";
		glShaderSource(vertexShader, 1, &vertexSource, NULL);
		glCompileShader(vertexShader);
		{
			GLint status;
			glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
			char buffer[512];
			glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
			printf(buffer);
		}

		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		const GLchar* fragmentSource =
			"#version 430\n"
			"in vec4 colorOut;"
			"in vec2 UVOut;"
			"out vec4 outColor;"
			"uniform sampler2D tex;"
			"void main(){"
			//"	outColor = texture(tex, UVOut) * vec4(colorOut);"
			"	outColor = vec4(colorOut);"
			"}";
		glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
		glCompileShader(fragmentShader);
		{
			GLint status;
			glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
			char buffer[512];
			glGetShaderInfoLog(fragmentShader, 512, NULL, buffer);
			printf(buffer);
		}
		//Build Program
		shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);
		//Texture Settings
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	}
	~FrameWork() {
		glDeleteProgram(shaderProgram);
		glDeleteShader(fragmentShader);
		glDeleteShader(vertexShader);
		glfwTerminate();
	}

	GLFWwindow* window;
	GLuint vertexShader;
	GLuint fragmentShader;
	GLuint shaderProgram;
};
*/