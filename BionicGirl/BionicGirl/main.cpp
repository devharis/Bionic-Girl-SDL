#include <iostream>
#include "MenuState.h"

int main(int argc, char* argv[]){
	GameInst::Instance()->Init("Bionic Girl", "./assets/icon.png", 640, 480, false);
	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;

	GameInst::Instance()->ChangeState(MenuState::Instance());

	while (GameInst::Instance()->Running()){
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();

		deltaTime = (double)((NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());

		GameInst::Instance()->HandleEvents();
		GameInst::Instance()->Update(deltaTime);
		GameInst::Instance()->Draw();
	}

	GameInst::Instance()->Clean();

	return 0;
}
