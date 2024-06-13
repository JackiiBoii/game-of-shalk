#include "pch/pch.h"
#include "player.h"
const std::string resource_path = RESOURCES_DIR;

player::player()
{
	texture.loadFromFile(resource_path + "/smile.png");

	sprite.setTexture(texture);
}

void player::handleKeyPressed(sf::Keyboard::Key key)
{
    key_states[key] = true;
}

void player::handleKeyReleased(sf::Keyboard::Key key)
{
    key_states[key] = false;
}

void player::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void player::update(float deltaTime)
{
    float offsetX = 0.0f;
    float offsetY = 0.0f;

    if (key_states[sf::Keyboard::Left]) {
        offsetX -= speed * deltaTime;
    }
    if (key_states[sf::Keyboard::Right]) {
        offsetX += speed * deltaTime;
    }
    if (key_states[sf::Keyboard::Up]) {
        offsetY -= speed * deltaTime;
    }
    if (key_states[sf::Keyboard::Down]) {
        offsetY += speed * deltaTime;
    }

    move(offsetX, offsetY);
}

void player::move(float offsetX,float offsetY)
{
    sprite.move(offsetX, offsetY);
}
