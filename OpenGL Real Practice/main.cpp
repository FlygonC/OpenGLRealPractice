#include "FrameWork.h"
#include "Sprite.h"
#include "SpriteAnimated.h"
#include "SpriteString.h"
#include "Quad.h"

#include <iostream>

int main() {
	
	FrameWork* root = new FrameWork();

	Quad testQuad;

	Sprite testSprite = Sprite();
	testSprite.initializeSprite("plane1.png", 600, 400, 40, 40);

	while (!glfwWindowShouldClose(root->window)) {

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		testQuad.Draw();
		testSprite.Draw();

		if (glfwGetKey(root->window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(root->window, GL_TRUE);
		}
		glfwSwapBuffers(root->window);
		glfwPollEvents();
	}
	delete root;
	//glfwTerminate();
	return 0;
}