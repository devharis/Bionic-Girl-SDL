#include <stdio.h>
#include "SDL.h"
#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"

MenuState MenuState::m_MenuState;
SDL_Surface* optimizedSurface;
SDL_Texture* texture;

void MenuState::Init(){
	bmpSurface = SDL_LoadBMP("./assets/background.bmp");
	printf("MenuState Init Successful\n");
}

void MenuState::Clean(){
	// Free surface
	SDL_FreeSurface(bmpSurface);
	SDL_FreeSurface(optimizedSurface);

	printf("MenuState Clean Successful\n");
}

void MenuState::Pause(){
	printf("MenuState Paused\n");
}

void MenuState::Resume(){
	printf("MenuState Resumed\n");
}

void MenuState::HandleEvents(){
	SDL_Event event;

	if (SDL_PollEvent(&event)){
		switch (event.type){
		case SDL_QUIT:
			GameInst::Instance()->Quit();
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym){

			case SDLK_SPACE:
				GameInst::Instance()->ChangeState(PlayState::Instance());
				break;
			}
		}
	}
}

void MenuState::Update(){
}

void MenuState::Draw(){
	// Optimizin'
	optimizedSurface = SDL_ConvertSurface(bmpSurface, GameInst::Instance()->GetScreen()->format, 0);
	texture = SDL_CreateTextureFromSurface(GameInst::Instance()->GetRenderer(), optimizedSurface);

	SDL_RenderCopy(GameInst::Instance()->GetRenderer(), texture, nullptr, nullptr);
}