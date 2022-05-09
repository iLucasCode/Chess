
#include "Handler.h"

Handler::Handler() {

	init();
}

void Handler::init() {

	window.create(sf::VideoMode(screen_widht, screen_height), "Chess");

}