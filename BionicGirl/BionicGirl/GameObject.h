#pragma once

#include <SDL.h>
#include "Game.h"
#include "Vector2D.h"

class GameObject {

public:
	GameObject::GameObject() : m_position(0.0f, 0.0f), m_velocity(0.0f, 0.0f) {};
	GameObject::GameObject(Vector2D position, const int width, const int height, const string textureId);

	//void load(Vector2D position, const int width, const int height, const string textureId);

	virtual void update(const float deltaTime);
	virtual void draw();
	virtual void clean();
protected:
	Vector2D m_position;
	Vector2D m_velocity;
	string m_textureId;
	int m_width = 0;
	int m_height = 0;
};

