#pragma once

#include "SpriteChar.h"

SpriteChar::SpriteChar() {}

void SpriteChar::initializeSprite(char* texturePath, float a_x, float a_y, float a_width, float a_height) {
	x = a_x;
	y = a_y;
	width = a_width;
	height = a_height;
	code = 0;

	glGenBuffers(1, &VBO); // Generate 1 buffer

	glGenTextures(1, &Texture);
	glBindTexture(GL_TEXTURE_2D, Texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	int texWidth, texHeight;
	unsigned char* image = SOIL_load_image("TestFont2.png", &texWidth, &texHeight, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	sheetWidth = texWidth; sheetHeight = texHeight;
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	updateData();
	updateGLData();
}

void SpriteChar::updateGLData() {
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

void SpriteChar::updateData() {
	/*vertexData[32] = {
	x - (width / 2), y - (height / 2), 0, 1,//bottom left
	x + (width / 2), y - (height / 2), 1, 1,//botom right
	x - (width / 2), y + (height / 2), 0, 0,//top left
	x + (width / 2), y + (height / 2), 1, 0,//top right
	};*/
	int tempCode = code;
	row = 0;
	while (tempCode >= 16) {
		row += 1;
		tempCode -= 16;
	}
	column = tempCode;

	//bottom left
	vertexData[0] = (x - (width / 2)) / 400;
	vertexData[1] = (y - (height / 2)) / 400;
	vertexData[2] = ((sheetWidth / 16) / sheetWidth)*(column);//uvs
	vertexData[3] = ((sheetHeight / 16) / sheetHeight)*(row + 1);
	//bottom right
	vertexData[4] = (x + (width / 2)) / 400;
	vertexData[5] = (y - (height / 2)) / 400;
	vertexData[6] = ((sheetWidth / 16) / sheetWidth)*(column + 1);//uvs U
	vertexData[7] = ((sheetHeight / 16) / sheetHeight)*(row + 1);//V
	//top left
	vertexData[8] = (x - (width / 2)) / 400;
	vertexData[9] = (y + (height / 2)) / 400;
	vertexData[10] = ((sheetWidth / 16) / sheetWidth)*(column);//uvs U
	vertexData[11] = ((sheetHeight / 16) / sheetHeight)*(row);//V
	//top right
	vertexData[12] = (x + (width / 2)) / 400;
	vertexData[13] = (y + (height / 2)) / 400;
	vertexData[14] = ((sheetWidth / 16) / sheetWidth)*(column + 1);//uvs U
	vertexData[15] = ((sheetHeight / 16) / sheetHeight)*(row);//V
}

void SpriteChar::Draw() {
	updateGLData();
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindTexture(GL_TEXTURE_2D, Texture);
	glUseProgram(FrameWork::shaderProgramTextured);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glUseProgram(0);
}