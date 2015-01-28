#pragma once

#include "SpriteAnimated.h"

SpriteAnimated::SpriteAnimated() {}

void SpriteAnimated::initializeSprite(char* texturePath, GLuint a_Shader, float a_x, float a_y, float a_width, float a_height) {
	Shader = a_Shader;
	x = a_x;
	y = a_y;
	width = a_width;
	height = a_height;

	glGenBuffers(1, &VBO); // Generate 1 buffer

	glGenTextures(1, &Texture);
	glBindTexture(GL_TEXTURE_2D, Texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	int texWidth, texHeight;
	unsigned char* image = SOIL_load_image(texturePath, &texWidth, &texHeight, 0, SOIL_LOAD_AUTO);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	sheetWidth = texWidth; sheetHeight = texHeight;
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	updateData();
	updateGLData();
}

void SpriteAnimated::updateGLData() {
	//glGenBuffers(1, &VBO); // Generate 1 buffer
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float)* 4, 0);
	//glEnableVertexAttribArray(1);
	//glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float)* 8, (void*)(sizeof(float)* 2));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float)* 4, (void*)(sizeof(float)* 2));

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void SpriteAnimated::updateData() {
	/*vertexData[32] = {
	x - (width / 2), y - (height / 2), 0, 1,//bottom left
	x + (width / 2), y - (height / 2), 1, 1,//botom right
	x - (width / 2), y + (height / 2), 0, 0,//top left
	x + (width / 2), y + (height / 2), 1, 0,//top right
	};*/

	frameNormWidth = frameWidth / sheetWidth;
	frameNormHeight = frameHeight / sheetHeight;

	//bottom left
	vertexData[0] = (x - (width / 2)) / 400;
	vertexData[1] = (y - (height / 2)) / 400;
	vertexData[2] = frameNormWidth*(currentFrame-1);//uvs
	vertexData[3] = 1;
	//bottom right
	vertexData[4] = (x + (width / 2)) / 400;
	vertexData[5] = (y - (height / 2)) / 400;
	vertexData[6] = frameNormWidth*currentFrame;//uvs U
	vertexData[7] = 1;//V
	//top left
	vertexData[8] = (x - (width / 2)) / 400;
	vertexData[9] = (y + (height / 2)) / 400;
	vertexData[10] = frameNormWidth*(currentFrame - 1);//uvs U
	vertexData[11] = 0;//V
	//top right
	vertexData[12] = (x + (width / 2)) / 400;
	vertexData[13] = (y + (height / 2)) / 400;
	vertexData[14] = frameNormWidth*currentFrame;//uvs U
	vertexData[15] = 0;//V
}

void SpriteAnimated::Draw() {
	updateData();
	updateGLData();
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
	glBindTexture(GL_TEXTURE_2D, Texture);
	glUseProgram(Shader);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glUseProgram(0);
}

void SpriteAnimated::initializeAnimation(float a_frameWidth, float a_frameHeight, int a_numOfFrames) {
	frameWidth = a_frameWidth;
	frameHeight = a_frameHeight;
	numFrames = a_numOfFrames;
	currentFrame = 1;
}