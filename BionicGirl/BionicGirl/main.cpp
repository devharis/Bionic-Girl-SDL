#include <iostream>
#include "MenuState.h"

const int FPS = 60; 
const int DELAY_TIME = 1000 / FPS;

int main(int argc, char* argv[]){
	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;
	Uint32 frameStart, frameTime;

	GameInst::Instance()->init("Bionic Girl", "./assets/icon.png", 1024, 720, false);
	GameInst::Instance()->change_state(MenuState::Instance());

	while (GameInst::Instance()->running()){
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		frameStart = SDL_GetTicks();

		deltaTime = (double)((NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());

		GameInst::Instance()->handle_events();
		GameInst::Instance()->update(deltaTime);
		GameInst::Instance()->draw();

		/*frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < DELAY_TIME) { 
			SDL_Delay((int)(DELAY_TIME - frameTime)); 
		}
		cout << DELAY_TIME;
		cout << "\n";*/
	}

	GameInst::Instance()->clean();

	return 0;
}
