#pragma once

#include "Framework/GameObject.h"

class Companion : public GameObject
{
public:
	Companion();
	~Companion();

	void update(float dt);
	void moveToPlayer(sf::Vector2f pos);
};