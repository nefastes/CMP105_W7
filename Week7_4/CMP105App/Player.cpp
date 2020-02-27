#include "Player.h"

Player::Player()
{
	setPosition(200, 200);
	setSize(sf::Vector2f(100, 100));
	hasFired = false;
}


Player::~Player()
{
}

void Player::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		input->setKeyUp(sf::Keyboard::Space);
		int x = rand() % 600;
		int y = rand() % 400;
		setPosition((float)x, (float)y);
	}

	if (input->isKeyDown(sf::Keyboard::Enter))
	{
		if (!hasFired)
		{
			spawn(getPosition() + sf::Vector2f(getSize().x / 2, getSize().y / 2));
			hasFired = true;
		}
	}
}

void Player::update(float dt) 
{
	if (hasFired)
	{
		bullet->update(dt);
		if (bullet->getPosition().x > 1200)
		{
			hasFired = false;
			delete bullet;
		}
	}
}

void Player::spawn(sf::Vector2f pos)
{
	bullet = new Bullet;
	bullet->setPosition(pos);
}