#include "FrameWork.h"
#include "Sprite.h"
#include "SpriteAnimated.h"

int main() {
	
	FrameWork* root = new FrameWork();

	Sprite testSprite = Sprite();
	testSprite.initializeSprite("kirby2.png", root->shaderProgramTextured, 0, 250, 420, 38);

	SpriteAnimated testAnim = SpriteAnimated();
	testAnim.initializeAnimation(21, 19, 10);
	testAnim.initializeSprite("kirby2.png", root->shaderProgramTextured, 0, 0, 21, 19);

	int testanimvar = 0;
	//Game Loop #########
	while (!glfwWindowShouldClose(root->window)) {

		glClearColor(0.0f, 0.0f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		testSprite.Draw();

		testanimvar++;
		if (testanimvar >= 100) {
			testAnim.currentFrame++;
			testanimvar -= 100;
		}
		testAnim.Draw();

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