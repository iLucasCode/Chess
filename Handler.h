#pragma once
#include <SFML/Graphics.hpp>

class Handler
{
public:
	const int screen_height = 520;
	const int screen_widht = 520;

	sf::RenderWindow window;

	sf::Event event;

	Handler();

	void init();
};
