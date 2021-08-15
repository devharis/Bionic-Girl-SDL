#include <stdio.h>

#include <SDL.h>
#include "Game.h"
#include "PauseState.h"
#include "PlayState.h"
#include "MenuState.h"
#include "InputHandler.hpp"
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
    if (InputHandlerInst::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
    {
        GameInst::Instance()->pop_state();
    }
    /*else if (InputHandlerInst::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        GameInst::Instance()->quit();
    }*/
    else if (InputHandlerInst::Instance()->isKeyDown(SDL_SCANCODE_M))
    {
        GameInst::Instance()->pop_state();
        GameInst::Instance()->change_state(MenuState::Instance());
    }
    else
    {
        // Do nothing
    }
}

void PauseState::update(const float deltaTime) {
	// Not impl yet.
}

void PauseState::draw() {
	SDL_RenderCopy(GameInst::Instance()->get_renderer(), texture, nullptr, nullptr);
}
