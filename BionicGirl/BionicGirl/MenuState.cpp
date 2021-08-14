#include <stdio.h>
#include <SDL.h>
#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"
#include <iostream>

MenuState MenuState::m_MenuState;

void MenuState::init() {
	bmpSurface = SDL_LoadBMP("./assets/menu-state.bmp");
    
	// Optimizin'
	optimizedSurface = SDL_ConvertSurface(bmpSurface, GameInst::Instance()->get_screen()->format, 0);
	texture = SDL_CreateTextureFromSurface(GameInst::Instance()->get_renderer(), optimizedSurface);

	if (!texture) {
		auto error = SDL_GetError();
		cout << error;
	}

	printf("MenuState Init Successful\n");
}

void MenuState::clean() {
	// Free surface
	SDL_FreeSurface(bmpSurface);
	SDL_FreeSurface(optimizedSurface);
	SDL_RenderClear(GameInst::Instance()->get_renderer());

	printf("MenuState Clean Successful\n");
}

void MenuState::pause() {
	printf("MenuState Paused\n");
}

void MenuState::resume() {
	printf("MenuState Resumed\n");
}

void MenuState::handle_events() {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			GameInst::Instance()->quit();
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {

			case SDLK_SPACE:
				GameInst::Instance()->change_state(PlayState::Instance());
				break;
			}
		}
	}
}

void MenuState::update(const float deltaTime) {
	// Not impl yet.
}

void MenuState::draw() {
	SDL_RenderCopy(GameInst::Instance()->get_renderer(), texture, nullptr, nullptr);
}
