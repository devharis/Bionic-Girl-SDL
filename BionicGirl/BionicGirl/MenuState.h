#pragma once

#include "SDL.h"
#include "GameState.h"

class MenuState : public GameState {
public:
	void init() override;
	void clean() override;

	void pause() override;
	void resume() override;

	void handle_events() override;
	void update(const double deltaTime) override;
	void draw() override;

	static MenuState* Instance() {
		return &m_MenuState;
	}

private:
	static MenuState m_MenuState;
	SDL_Surface* bmpSurface = nullptr;
	SDL_Surface* optimizedSurface = nullptr;
	SDL_Texture* texture = nullptr;
};

