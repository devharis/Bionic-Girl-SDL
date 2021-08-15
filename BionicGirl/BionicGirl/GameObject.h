#pragma once

#include <SDL.h>
#include "Game.h"
#include "Vector2D.h"

class GameObject {

public:
    GameObject() : m_position(0.0f, 0.0f), m_velocity(0.0f, 0.0f), m_acceleration(0.0f, 0.0f) {};
    GameObject(Vector2D position, const int width, const int height, const string textureId);

	//void load(Vector2D position, const int width, const int height, const string textureId);

	virtual void update(const float deltaTime);
	virtual void draw();
	virtual void clean();
protected:
	Vector2D m_position;
	Vector2D m_velocity;
    Vector2D m_acceleration;
    SDL_RendererFlip m_flip;
	string m_textureId;
	int m_width = 0;
	int m_height = 0;
    
    int m_currentRow;
    int m_currentFrame;
};
