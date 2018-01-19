#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;
const char* PROGRAM_NAME = "SFML Hello World";

const int FRAMES_PER_SECOND = 60;
const int MICROSECS_PER_FRAME = 1000000 / FRAMES_PER_SECOND;

int main(int argc, const char** argv)
{
    // --- WINDOW INITIALIZATION ---
    sf::RenderWindow window(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
        PROGRAM_NAME,
        sf::Style::Titlebar | sf::Style::Close
    );

    window.setVerticalSyncEnabled(true);

    int elapsed = 0;
    sf::Clock clock;
    while (window.isOpen()) {
        // --- UPDATE ELAPSED TIME ---
        elapsed += clock.restart().asMicroseconds();

        // --- DRAWING PHASE ---
        window.clear(sf::Color({100, 200, 100}));
        window.display();

        // --- UPDATING PHASE ---
        while (elapsed > MICROSECS_PER_FRAME) {
            // Perform updates here

            elapsed -= MICROSECS_PER_FRAME;
        }
    
        // --- EVENT PROCESSING PHASE ---
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
        }
    }

    return EXIT_SUCCESS;
}
