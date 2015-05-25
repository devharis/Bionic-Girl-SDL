#include <stdio.h>

#include "SDL.h"
#include "Game.h"
#include "PauseState.h"

PauseState PauseState::m_PauseState;

void PauseState::Init(){
	// Not used yet.
	printf("PauseState Init Successful\n");
}

void PauseState::Clean(){
	// Not used yet.
	printf("PauseState Clean Successful\n");
}

void PauseState::Resume(){
	// Not used yet.
}

void PauseState::Pause(){
	// Not used yet.
}

void PauseState::HandleEvents(){
	SDL_Event event;

	if (SDL_PollEvent(&event)){
		switch (event.type){
		case SDL_QUIT:
			GameInst::Instance()->Quit();
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym){
			case SDLK_SPACE:
				GameInst::Instance()->PopState();
				break;
			}
		}
	}
}

void PauseState::Update(){
	// Not used yet.
}

void PauseState::Draw(){
	// Not used yet.
}
