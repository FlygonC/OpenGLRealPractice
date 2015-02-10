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

	SpriteString testString = SpriteString();
	testString.InitializeString("String", "TestFont2.png", 100, 100, 224/16);

	SpriteAnimated testAnim = SpriteAnimated();
	testAnim.initializeSprite("kirby2.png", 600, 500, 21*1, 19*1);
	testAnim.makeBasicStructure(10, 1);
	testAnim.setAnimation(0, 0, 9, LOOP);
	testAnim.playAnimation(0);
	testAnim.fps = 10;
	//testAnim.setFrame(2);

	while (!glfwWindowShouldClose(root->window)) {

		glClearColor(0.0f, 0.0f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		testQuad.Draw();

		testSprite.Draw();

		testAnim.Update();
		testAnim.Draw();

		testString.Draw();

		//std::cout << getDeltaTime() << "\n";

		resetTime();

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