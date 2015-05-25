#pragma once

#include "SDL.h"
#include "GameState.h"

class PauseState : public GameState{
public:
	void Init() override;
	void Clean() override;

	void Pause() override;
	void Resume() override;

	void HandleEvents() override;
	void Update() override;
	void Draw() override;

	// Implement Singleton Pattern
	static PauseState* Instance(){
		return &m_PauseState;
	}

protected:
	~PauseState(){
	}

	PauseState(){
	}

private:
	static PauseState m_PauseState;

	SDL_Surface* pauseSprite;

};