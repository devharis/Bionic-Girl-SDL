#include "Game.h"
#include "GameState.h"

void Game::Init(const char* title, const char* icon, int width, int height, bool fullscreen){
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
		SDL_WINDOWPOS_UNDEFINED, // initial x position
		SDL_WINDOWPOS_UNDEFINED, // initial y position
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
	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);
	// Get Window surface
	m_pScreen = SDL_GetWindowSurface(m_pWindow);

	m_bRunning = true;

	SDL_Log("Game Initialised Succesfully\n");

}

void Game::ChangeState(GameState* state){
	if (!states.empty()){
		states.back()->Clean();
		states.pop_back();
	}
	states.push_back(state);
	states.back()->Init();
}

void Game::PushState(GameState* state){
	if (!states.empty())
		states.back()->Pause();

	states.push_back(state);
	states.back()->Init();
}

void Game::PopState(){
	if (!states.empty()){
		states.back()->Clean();
		states.pop_back();
	}

	if (!states.empty())
		states.back()->Resume();
}

void Game::HandleEvents(){
	states.back()->HandleEvents();
}

void Game::Update(){
	states.back()->Update();
}

void Game::Draw(){
	states.back()->Draw();
	SDL_RenderPresent(m_pRenderer);
}

void Game::Clean(){
	while (!states.empty()){
		states.back()->Clean();
		states.pop_back();
	}

	// shutdown SDL
	SDL_DestroyWindow(m_pWindow);
	SDL_Quit();
}