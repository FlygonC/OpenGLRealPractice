#include "FrameWork.cpp"
#include "Sprite.cpp"

int main() {
	
	FrameWork root;

	Sprite testSprite;
	testSprite.initializeSprite(root.shaderProgram, 0, 0, 100, 200);

	//Sprite testSprite2;
	//testSprite2.initializeSprite(root.shaderProgram, 0, 0, 1, 1);

	//Game Loop #########
	while (!glfwWindowShouldClose(root.window)) {

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		testSprite.Draw();
		
		//testSprite2.Draw();

		if (glfwGetKey(root.window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(root.window, GL_TRUE);
		}
		glfwSwapBuffers(root.window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}