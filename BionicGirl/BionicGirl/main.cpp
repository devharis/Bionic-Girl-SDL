#include <iostream>
#include "MenuState.h"

const int FPS = 60; 
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* argv[]){
	Uint64 currentFrame = SDL_GetPerformanceCounter();
	Uint64 lastFrame = 0;
	Uint32 startclock, currentFPS = 0;
	float deltaTime = 0;

	GameInst::Instance()->init("Bionic Girl", "./assets/icon.png", 1024, 720, false);
	GameInst::Instance()->change_state(MenuState::Instance());

	while (GameInst::Instance()->running()){
		startclock = SDL_GetTicks();

		lastFrame = currentFrame;
		currentFrame = SDL_GetPerformanceCounter();

		deltaTime = ((currentFrame - lastFrame) * 1000.0f / (float)SDL_GetPerformanceFrequency());

		GameInst::Instance()->handle_events();
		GameInst::Instance()->update(deltaTime);
		GameInst::Instance()->draw();

		startclock = SDL_GetTicks();

		if (deltaTime != 0)
			currentFPS = 1000 / deltaTime;

		cout << currentFPS;
		cout << "\n";
	}

	GameInst::Instance()->clean();

	return 0;
}
