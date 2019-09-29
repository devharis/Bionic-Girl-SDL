#pragma once
#include <vector>
#include <SDL.h>
#include "Singleton.h"
#include "TextureManager.h"

using namespace std;

class GameState;

class Game {
public:
	void init(const char* title, const char* icon, int width, int height, bool fullscreen);
	void change_state(GameState* state); // new function
	void push_state(GameState* state); // new function
	void pop_state(); // new function
	void handle_events(); // remove pointer to game class
	void update(double deltaTime);
	void draw();
	void clean();

	bool running() {
		return m_running;
	}

	void quit() {
		m_running = false;
	}

	SDL_Surface* get_screen() {
		return m_pScreen;
	}

	SDL_Renderer* get_renderer() {
		return m_pRenderer;
	}

private:
	friend class Singleton<Game>;
	SDL_Window* m_pWindow = nullptr;
	SDL_Renderer* m_pRenderer = nullptr;
	SDL_Surface* m_pScreen = nullptr;
	vector<GameState*> m_states;
	bool m_fullscreen = false;
	bool m_running = false;
};

typedef Singleton<Game> GameInst;

