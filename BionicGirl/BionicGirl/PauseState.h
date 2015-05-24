#pragma once

#include "SDL.h"
#include "GameState.h"

class PauseState : public GameState
{
public:
	void Init();
	void Clean();

	void Pause();
	void Resume();

	void HandleEvents();
	void Update();
	void Draw();

	// Implement Singleton Pattern
	static PauseState* Instance()
	{
		return &m_PauseState;
	}

protected:
	PauseState(){}

private:
	static PauseState m_PauseState;

	SDL_Surface* pauseSprite;

};