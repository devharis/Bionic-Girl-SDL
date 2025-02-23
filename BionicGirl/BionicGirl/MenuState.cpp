#include <stdio.h>
#include <SDL.h>
#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"
#include "InputHandler.hpp"
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
    if (InputHandlerInst::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
    {
        GameInst::Instance()->change_state(PlayState::Instance());
    }
    else if (InputHandlerInst::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        GameInst::Instance()->quit();
    } else {
        // Do nothing
    }
}

void MenuState::update(const float deltaTime) {
	// Not impl yet.
}

void MenuState::draw() {
	SDL_RenderCopy(GameInst::Instance()->get_renderer(), texture, nullptr, nullptr);
}
