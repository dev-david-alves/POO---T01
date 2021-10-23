#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

struct Pencil {
    sf::Font font;
    sf::Text text;
    sf::RenderWindow& window;

    Pencil(sf::RenderWindow& window) : window(window) {
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

struct Bubble {
    int x;
    int y;
    char letter;
    int speed;
    bool alive {true};
    
    static const int radius {10};

    Bubble(int x, int y, char letter, int speed) : x(x), y(y), letter(letter), speed(speed) {
    }

    void update() {
        this->y += this->speed;
    }

    void draw(sf::RenderWindow& window) {
        sf::CircleShape circle(Bubble::radius);
        circle.setPosition(this->x, this->y);
        circle.setFillColor(sf::Color::White);
        window.draw(circle);

        static Pencil pencil(window);
        pencil.write(std::string(1, this->letter), x + 0.4 * Bubble::radius, y, Bubble::radius * 1.5, sf::Color::Blue);
    }

};

struct Board {
    sf::RenderWindow& window;
    std::vector<Bubble> bubbles;
    int hits {0};
    int misses {0};

    Board(sf::RenderWindow& window) : window(window) {
        bubbles.push_back(Bubble(100, 100, 'A', 1));
        bubbles.push_back(Bubble(200, 100, 'B', 2));
        bubbles.push_back(Bubble(300, 100, 'C', 3));
    }

    void add_new_bubble() {
        int x = rand() %  ((int) this->window.getSize().x - 2 * Bubble::radius);
        int y = 2 * Bubble::radius;
        int speed = rand() % 5 + 1;
        char letter = rand() % 26 + 'A';
        bubbles.push_back(Bubble(x, y, letter, speed));
    }

    void update() {
        if(check_new_bubble())
            add_new_bubble();

        for(Bubble& bubble: bubbles) {
            bubble.update();
        }
    }

    bool check_new_bubble() {
        static const int new_bubble_timeout {30};
        static int new_bubble_timer {0};

        new_bubble_timer--;
        if(new_bubble_timer <= 0) {
            new_bubble_timer = new_bubble_timeout;
            return true;
        }

        return false;
    }

    void draw() {
        for(Bubble& bubble: bubbles) {
            bubble.draw(window);
        }
    }

};

struct Game {
    sf::RenderWindow window;
    Board board;

    Game() : window(sf::VideoMode(800, 600), "Bubbles"), board(window) {
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
        board.update();
        window.clear(sf::Color::Black);
        board.draw();
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