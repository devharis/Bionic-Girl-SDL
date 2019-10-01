#include <iostream>
#include "MenuState.h"


int main(int argc, char* argv[]){
	Uint32 currentFrame = SDL_GetTicks();
	Uint32 lastFrame = 0;
	float deltaTime = 0;
	Uint32 frameStart, frameTime;

	GameInst::Instance()->init("Bionic Girl", "./assets/icon.png", 1024, 720, false);
	GameInst::Instance()->change_state(MenuState::Instance());

	while (GameInst::Instance()->running()){
		frameStart = SDL_GetTicks();
		frametime

		GameInst::Instance()->handle_events();

		//lastFrame = currentFrame;
		//currentFrame = SDL_GetTicks();

		//deltaTime = ((currentFrame - lastFrame) * 1000.0f / SDL_GetTicks());
		GameInst::Instance()->update(0);
		GameInst::Instance()->draw();

		frameTime = SDL_GetTicks() - frameStart;

		cout << SDL_GetTicks();
		cout << "\n";
	}

	GameInst::Instance()->clean();

	return 0;
}
