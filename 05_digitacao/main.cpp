#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <functional>

sf::Texture loadTexture(std::string path) {
    sf::Texture texture;
    if(!texture.loadFromFile(path)) {
        std::cout << "Error loading texture\n";
        exit(1);
    }

    return texture;
}

void setSize(sf::Sprite& sprite, int width, int height) {
    auto dim = sprite.getLocalBounds();
    sprite.setScale((float) width / dim.width, (float) height / dim.height);
}

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
    int radius;
    bool alive {true};

    sf::Texture bubble_texture { loadTexture("./images/meteor.png") };
    sf::Sprite sprite;

    Bubble(int x, int y, char letter, int speed, int radius) : x(x), y(y), letter(letter), speed(speed), radius(radius) {
    }

    void update() {
        this->y += this->speed;
    }

    void draw(sf::RenderWindow& window) {
        // sf::CircleShape circle(this->radius);
        // circle.setPosition(this->x, this->y);
        // circle.setFillColor(sf::Color::White);
        // window.draw(circle);

        this->sprite.setTexture(bubble_texture);
        setSize(this->sprite, this->radius * 4, this->radius * 5);
        this->sprite.setPosition(this->x, this->y);
        window.draw(this->sprite);

        static Pencil pencil(window);
        pencil.write(std::string(1, this->letter), x + this->radius * 1.5, y + this->radius * 3, this->radius * 1.5, sf::Color::White);
    }

};

struct Board {
    sf::RenderWindow& window;
    std::vector<Bubble> bubbles;
    Pencil pencil;
    int hits {0};
    int misses {0};

    Board(sf::RenderWindow& window) : window(window), pencil(window) {
    }

    void add_new_bubble() {
        int radius = rand() % 20 + 10;
        int x = rand() %  ((int) this->window.getSize().x - 2 * radius);
        int y = -4 * radius;
        int speed = (rand() % (10 + this->misses)) + 1 + this->misses;
        char letter = rand() % 26 + 'A';
        bubbles.push_back(Bubble(x, y, letter, speed, radius));
    }

    void update() {
        if(check_new_bubble())
            add_new_bubble();

        for(Bubble& bubble: bubbles) {
            bubble.update();
        }

        this->mark_outside_bubbles();
        this->remove_dead_bubbles();
    }

    void mark_outside_bubbles() {
        for(Bubble& bubble: bubbles) {
            if(bubble.y + 2 * bubble.radius > (int) this->window.getSize().y) {
                if(bubble.alive) {
                    bubble.alive = false;
                    this->misses++;
                }
            }
        }
    }

    void mark_by_hit(char letter) {
        for(Bubble& bubble: bubbles) {
            if(bubble.letter == letter) {
                bubble.alive = false;
                this->hits++;
                break;
            }
        }
    }

    void remove_dead_bubbles() {
        std::vector<Bubble> alive;

        for(Bubble& bubble: bubbles) {
            if(bubble.alive)
                alive.push_back(bubble);
        }

        this->bubbles = alive;
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
        pencil.write("Hits: " + std::to_string(this->hits) + "\t\tMisses: " + std::to_string(this->misses), 10, 10, 20, sf::Color::White);
        pencil.write("Size: " + std::to_string(bubbles.size()), 10, 30, 20, sf::Color::White);

        for(Bubble& bubble: bubbles) {
            bubble.draw(window);
        }
    }

};

struct Game {
    sf::RenderWindow window;
    Board board;
    std::function<void()> on_update;

    const int maximum_misses {10};

    Game() : window(sf::VideoMode(800, 600), "Bubbles"), board(window) {
        this->on_update = [&]() {
            this->gameplay();
        };
        window.setFramerateLimit(30);
    }

    void process_events() {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            } else if(event.type == sf::Event::TextEntered) {
                char code = static_cast<char>(event.text.unicode);
                code = toupper(code);
                board.mark_by_hit(code);
            } else if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Enter && board.misses >= maximum_misses) {
                    board.misses = 0;
                    board.hits = 0;
                    board.bubbles = {};
                    this->on_update = [&]() {
                        this->gameplay();
                    };
                }
            }
        }
    }

    void gameplay() {
        board.update();
        window.clear(sf::Color::Black);
        board.draw();
        window.display();

        if(board.misses >= maximum_misses) {
            this->on_update = [&]() {
                this->gameover();
            };
        }
    }

    void gameover() {
        static Pencil pencil(window);
        window.clear(sf::Color::Black);
        pencil.write("Game Over", 250, 250, 50, sf::Color::White);
        pencil.write("Press Enter to Play Again", 240, 310, 25, sf::Color::Cyan);
        window.display();
    }

    void main_loop() {
        while(window.isOpen()) {
            process_events();
            on_update();
        }
    }
};

int main() {
    Game game;
    game.main_loop();
 
    return 0;
}

// Run SFML

// g++ -IC:\SFML-2.5.1\include -c main.cpp -o main.o
// g++ -LC:\SFML-2.5.1\lib .\main.o -o app.exe -lmingw32 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-main -mwindows