#include "Game.h"
#include "GameState.h"
#include "InputHandler.hpp"

void Game::init(const char* title, const char* icon, int width, int height, bool fullscreen){
	int flags = SDL_WINDOW_OPENGL;

	SDL_Init(SDL_INIT_VIDEO); // Initialize SDL2

	if (fullscreen){
		flags = SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN;
		width = 1920;
		height = 1200;
	}
	
	// Create an application window with the following settings:
	m_pWindow = SDL_CreateWindow(
		title, // window title
		SDL_WINDOWPOS_CENTERED, // initial x position
		SDL_WINDOWPOS_CENTERED, // initial y position
		width, // width, in pixels
		height, // height, in pixels
		flags // flags - see below
	);

	// Check that the window was successfully made
	if (m_pWindow == NULL){
		// In the event that the window could not be made...
		printf("Could not create window: %s\n", SDL_GetError());
	}

	SDL_Surface* iconSurface = IMG_Load(icon);
	// Set icon
	SDL_SetWindowIcon(m_pWindow, iconSurface);
	// Free surface
	SDL_FreeSurface(iconSurface);

	// Create a render target
	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_SOFTWARE);
	// Get Window surface
	m_pScreen = SDL_GetWindowSurface(m_pWindow);
    
    printf("SDL_Init failed: %s\n", SDL_GetError());
    
    //initialise joysticks
    InputHandlerInst::Instance()->init();
    InputHandlerInst::Instance()->initialiseJoysticks();

    std::cout << "init success\n";

	m_running = true;

	SDL_Log("Game Initialised Succesfully\n");

}

void Game::change_state(GameState* state){
	if (!m_states.empty()){
		m_states.back()->clean();
		m_states.pop_back();
	}
	m_states.push_back(state);
	m_states.back()->init();
}

void Game::push_state(GameState* state){
	if (!m_states.empty())
		m_states.back()->pause();

	m_states.push_back(state);
	m_states.back()->init();
}

void Game::pop_state(){
	if (!m_states.empty()){
		m_states.back()->clean();
		m_states.pop_back();
	}

	if (!m_states.empty())
		m_states.back()->resume();
}

void Game::handle_events(){
	m_states.back()->handle_events();
}

void Game::update(const float deltaTime){
	m_states.back()->update(deltaTime);
}

void Game::draw(){
	SDL_RenderClear(m_pRenderer);
	m_states.back()->draw();
	SDL_RenderPresent(m_pRenderer);
}

void Game::clean(){
	while (!m_states.empty()){
		m_states.back()->clean();
		m_states.pop_back();
	}
    
    InputHandlerInst::Instance()->clean();

	// shutdown SDL
	SDL_DestroyWindow(m_pWindow);
	SDL_Quit();
}
