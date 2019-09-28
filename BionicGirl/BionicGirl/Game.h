#pragma once
#include <vector>
#include <SDL.h>
#include "Singleton.h"
#include "TextureManager.h"

using namespace std;

class GameState;

class Game{
public:
	~Game(){
	};

	void Init(const char* title, const char* icon, int width, int height, bool fullscreen);
	void ChangeState(GameState* state); // new function
	void PushState(GameState* state); // new function
	void PopState(); // new function
	void HandleEvents(); // remove pointer to game class
	void Update(double deltaTime);
	void Draw();
	void Clean();

	bool Running(){
		return m_bRunning;
	}

	void Quit(){
		m_bRunning = false;
	}

	SDL_Surface* GetScreen(){
		return m_pScreen;
	}

	SDL_Renderer* GetRenderer(){
		return m_pRenderer;
	}


private:
	Game(){
	} // add private constructor
	friend class Singleton<Game>;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	vector<GameState*> states;
	SDL_Surface* m_pScreen;
	bool m_bFullscreen;
	bool m_bRunning;
};

typedef Singleton<Game> GameInst;

