#pragma once

#include "PauseState.h"
#include "GameState.h"
#include "GameObject.h"
#include "Game.h"

class PlayState : public GameState
{
public:
	void Init();
	void Clean();
	void Pause();
	void Resume();
	void HandleEvents();
	void Update();
	void Draw();
	static PlayState* Instance(){
		return &m_PlayState;
	}

protected:
	PlayState() {}

private:
	static PlayState m_PlayState;
	GameObject* testObject;

};

