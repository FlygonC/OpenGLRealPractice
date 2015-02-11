#include "FrameWork.h"
#include "Sprite.h"
#include "SpriteAnimated.h"
#include "SpriteString.h"
#include "Quad.h"

#include "Player.h"
#include "Bomb.h"
#include "Heart.h"

#include <iostream>
#include <time.h>
#include <cstring>
#include <sstream>

int main() {
	
	FrameWork* root = new FrameWork();
	float FDeltaTime = getDeltaTime();
	srand(time(NULL));
	
	Player* player = new Player();
	player->lives = 10;

	SpriteString livesString;
	livesString.InitializeString("Lives: --", "TestFont2.png", 10, 390, 14);

	float timeCounter = 0;
	int timeTotal = 0;
	SpriteString timeTotalString;
	timeTotalString.InitializeString("Time: 0", "TestFont2.png", 10, 10, 14);

	Bomb testBomb[10];
	Heart heart;

	while (!glfwWindowShouldClose(root->window)) {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		FDeltaTime = getDeltaTime();
		if (FDeltaTime >= 0.1) {
			FDeltaTime = 0.1;
		}

		player->Update(FDeltaTime);
		for (int i = 0; i < 10; i++) {
			testBomb[i].Update(player, FDeltaTime);
		}

		heart.Update(player, FDeltaTime);

		std::stringstream livesStringBuffer;
		livesStringBuffer << "Health: " << player->lives;
		livesString.changeInput(livesStringBuffer.str().c_str());
		livesString.Draw();

		timeCounter += FDeltaTime;
		if (timeCounter >= 1) {
			timeTotal++;
			timeCounter -= 1;
			std::stringstream timeStringBuffer;
			timeStringBuffer << "Time: " << timeTotal;
			timeTotalString.changeInput(timeStringBuffer.str().c_str());
		}
		timeTotalString.Draw();

		resetTime();

		if (glfwGetKey(root->window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(root->window, GL_TRUE);
		}
		glfwSwapBuffers(root->window);
		glfwPollEvents();
	}
	delete player;
	delete root;
	//glfwTerminate();
	return 0;
}