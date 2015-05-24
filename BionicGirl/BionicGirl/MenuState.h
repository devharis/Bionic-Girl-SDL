#pragma once
#include "SDL.h"
#include "GameState.h"

class MenuState : public GameState{
public:
	void Init();
	void Clean();
	void Pause();
	void Resume();
	void HandleEvents();
	void Update();
	void Draw();
	static MenuState* Instance(){
		return &m_MenuState;
	}
protected:
	MenuState() {}
private:
	static MenuState m_MenuState;
	SDL_Surface* bmpSurface;
};

