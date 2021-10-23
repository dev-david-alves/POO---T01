#include <SFML/Graphics.hpp>
#include <iostream>

struct Pincel {
    sf::Font font;
    sf::Text text;
    sf::RenderWindow& window;

    Pincel(sf::RenderWindow& window) : window(window) {
        if(!font.loadFromFile("./fonts/arial.ttf"))
            std::cout << "Fail not loaded";
        text.setFont(font);
    }

    void write(std::string str, int x, int y, int size, sf::Color color) {
        text.setString(str);
        text.setCharacterSize(size);
        text.setPosition(x, y);
        text.setFillColor(color);
        window.draw(text);
    }
};

struct Game {
    sf::RenderWindow window;

    Game() : window(sf::VideoMode(800, 600), "Bubbles") {
        window.setFramerateLimit(30);
    }

    void process_events() {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

    void draw() {
        window.clear(sf::Color::Black);

        static Pincel pincel(window);
        pincel.write("Teste", 100, 100, 50, sf::Color::White);

        window.display();
    }

    void main_loop() {
        while(window.isOpen()) {
            process_events();
            draw();
        }
    }
};

int main() {

    Game game;
    game.main_loop();
 
    return 0;
}

// Rodar SFML

// g++ -IC:\SFML-2.5.1\include -c main.cpp -o main.o
// g++ -LC:\SFML-2.5.1\lib .\main.o -o app.exe -lmingw32 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-main -mwindows