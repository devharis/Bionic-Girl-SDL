#include <stdio.h>

#include <SDL.h>
#include "Game.h"
#include "PauseState.h"
#include "PlayState.h"
#include "MenuState.h"
#include <iostream>

PauseState PauseState::m_PauseState;

void PauseState::init() {
	bmpSurface = SDL_LoadBMP("./assets/pause-state.bmp");
	// Optimizin'
	optimizedSurface = SDL_ConvertSurface(bmpSurface, GameInst::Instance()->get_screen()->format, 0);
	texture = SDL_CreateTextureFromSurface(GameInst::Instance()->get_renderer(), optimizedSurface);

	if (!texture) {
		auto error = SDL_GetError();
		cout << error;
	}

	printf("PauseState Init Successful\n");
}

void PauseState::clean() {
	// Free surface
	SDL_FreeSurface(bmpSurface);
	SDL_FreeSurface(optimizedSurface);
	SDL_RenderClear(GameInst::Instance()->get_renderer());

	printf("PauseState Clean Successful\n");
}

void PauseState::resume() {
	printf("PauseState Resumed\n");
}

void PauseState::pause() {
	printf("PauseState Paused\n");
}

void PauseState::handle_events() {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			GameInst::Instance()->quit();
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_SPACE: // resume play
				GameInst::Instance()->pop_state();
				break;
			case SDLK_m: // back to main menu
				GameInst::Instance()->pop_state();
				GameInst::Instance()->change_state(MenuState::Instance());
				break;
			}
		}
	}
}

void PauseState::update(const float deltaTime) {
	// Not impl yet.
}

void PauseState::draw() {
	SDL_RenderCopy(GameInst::Instance()->get_renderer(), texture, nullptr, nullptr);
}
