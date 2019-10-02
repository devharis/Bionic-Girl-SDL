#include <iostream>
#include "MenuState.h"


int main(int argc, char* argv[]){
	float currentFrame = SDL_GetTicks();
	float lastFrame = 0;
	float deltaTime = 0;
	Uint32 frameStart, frameTime;

	GameInst::Instance()->init("Bionic Girl", "./assets/icon.png", 1024, 720, false);
	GameInst::Instance()->change_state(MenuState::Instance());

	while (GameInst::Instance()->running()){
		lastFrame = currentFrame;
		currentFrame = SDL_GetTicks();

		GameInst::Instance()->handle_events();

		deltaTime = (currentFrame - lastFrame);
		GameInst::Instance()->update(deltaTime);
		GameInst::Instance()->draw();
		
		cout << deltaTime;
		cout << "\n";
	}

	GameInst::Instance()->clean();

	return 0;
}
