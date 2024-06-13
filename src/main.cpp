#include "pch/pch.h"
#include "player.h"

int main()
{
    auto window = sf::RenderWindow{ { 1920u, 1080u }, "Game Of Shalk" };
    window.setFramerateLimit(144);

    player player1;
    sf::Clock clock;
    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                player1.handleKeyPressed(event.key.code);
            }
            if (event.type == sf::Event::KeyReleased) {
                player1.handleKeyReleased(event.key.code);
            }
        }
        sf::Time elapsed = clock.restart();
        float deltaTime = elapsed.asSeconds();

        player1.update(deltaTime);

        window.clear();
        player1.draw(window);
        window.display();
    }
}
