#pragma once
#include "pch/pch.h"
class player {
public:
	player();
	void handleKeyPressed(sf::Keyboard::Key);
	void handleKeyReleased(sf::Keyboard::Key);
	void draw(sf::RenderWindow& window);
	void update(float deltaTime);
	void move(float offsetX, float offsetY);
private:
	sf::Texture texture;
	sf::Sprite sprite;
	std::unordered_map<sf::Keyboard::Key, bool> key_states;
	float speed = 100;
};
