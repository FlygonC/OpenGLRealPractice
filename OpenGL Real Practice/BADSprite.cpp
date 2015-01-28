#pragma once

#include <GL/glew.h>
#include <GL/wglew.h>
//GLEW includes must precede anything else
#include <GLFW/glfw3.h>

#include <SOIL.h>

//#include "MLLS/Matrix4.h"

class Sprite {
public:
	Sprite() {}

	void initializeSprite(GLuint a_Shader, float a_x, float a_y, float a_width, float a_height) {
		Shader = a_Shader;
		x = a_x;
		y = a_y;
		width = a_width;
		height = a_height;

		updateGL();
		updateGLData();
	}

	void Draw() {
		updateGLData();
		//glBindBuffer(GL_ARRAY_BUFFER, VBO);
		//glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
		glUseProgram(Shader);

		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glUseProgram(0);
	}

	void updateGL() {
		glGenBuffers(1, &VBO); // Generate 1 buffer
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float)* 8, 0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float)* 8, (void*)(sizeof(float)* 2));
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float)* 8, (void*)(sizeof(float)* 6));

		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void updateGLData() {
		/*vertexData[32] = {
			x - (width / 2), y - (height / 2), 1, 1, 1, 1, 0, 1,//bottom left
			x + (width / 2), y - (height / 2), 1, 1, 1, 1, 1, 1,//botom right
			x - (width / 2), y + (height / 2), 1, 1, 1, 1, 0, 0,//top left
			x + (width / 2), y + (height / 2), 1, 1, 1, 1, 1, 0,//top right
		};*/
		//bottom left
		vertexData[0] = (x - (width / 2))/800;
		vertexData[1] = (y - (height / 2))/800;
		vertexData[2] = 1;//color
		vertexData[3] = 1;
		vertexData[4] = 1;
		vertexData[5] = 1;
		vertexData[6] = 0;//uvs
		vertexData[7] = 1;
		//bottom right
		vertexData[8] = (x + (width / 2))/800;
		vertexData[9] = (y - (height / 2))/800;
		vertexData[10] = 1;//color R
		vertexData[11] = 0;//G
		vertexData[12] = 0;//B
		vertexData[13] = 1;//A
		vertexData[14] = 1;//uvs U
		vertexData[15] = 1;//V
		//top left
		vertexData[16] = (x - (width / 2))/800;
		vertexData[17] = (y + (height / 2))/800;
		vertexData[18] = 0;//color R
		vertexData[19] = 1;//G
		vertexData[20] = 0;//B
		vertexData[21] = 1;//A
		vertexData[22] = 0;//uvs U
		vertexData[23] = 0;//V
		//top right
		vertexData[24] = (x + (width / 2))/800;
		vertexData[25] = (y + (height / 2))/800;
		vertexData[26] = 0;//color R
		vertexData[27] = 0;//G
		vertexData[28] = 1;//B
		vertexData[29] = 1;//A
		vertexData[30] = 1;//uvs U
		vertexData[31] = 0;//V

	
		//glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	float width, height, x, y = 0;
	//Matrix4 Vertecies, Colors, UVs;
	float vertexData[32];
	GLuint VBO, IBO, Shader;
};