#pragma once
#include "SDL.h"
#include "GameState.h"

class MenuState : public GameState{
public:
	void Init() override;
	void Clean() override;

	void Pause() override;
	void Resume() override;

	void HandleEvents() override;
	void Update() override;
	void Draw() override;

	static MenuState* Instance(){
		return &m_MenuState;
	}

protected:
	~MenuState(){
	}

	MenuState(){
	}

private:
	static MenuState m_MenuState;
	SDL_Surface* bmpSurface;
};

