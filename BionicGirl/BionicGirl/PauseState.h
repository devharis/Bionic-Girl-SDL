#pragma once

#include <SDL.h>
#include "GameState.h"

class PauseState : public GameState {
public:
	void init() override;
	void clean() override;

	void pause() override;
	void resume() override;

	void handle_events() override;
	void update(const float deltaTime) override;
	void draw() override;

	// Implement Singleton Pattern
	static PauseState* Instance() {
		return &m_PauseState;
	}

private:
	static PauseState m_PauseState;
	SDL_Surface* bmpSurface;
	SDL_Surface* optimizedSurface;
	SDL_Texture* texture;
};
