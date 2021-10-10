#include <SFML/Graphics.hpp>
#include <iostream>
#include<windows.h>

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

struct Entity {
    int x {0};
    int y {0};
    int step {0};
    sf::Sprite sprite;

    bool is_idle {true};
    bool is_mirrored {false};

    std::vector<sf::Texture> idle_frames;

    std::vector<sf::Texture> walk_frames;

    int idle_frame_count {0};
    int walk_frame_count {0};

    Entity (int x, int y, int step, sf::Texture& texture, std::vector<sf::Texture> idle_frames, std::vector<sf::Texture> walk_frames):
        x {x}, y {y}, step {step}, sprite(texture), idle_frames {idle_frames}, walk_frames{walk_frames} {
        this->sprite.setPosition(x * step, y * step);    
    }

    void draw(sf::RenderWindow& window) {
        if(is_idle) {
            walk_frame_count = 0;

            this->sprite.setTexture(this->idle_frames[idle_frame_count]);
            idle_frame_count = (idle_frame_count + 1) % idle_frames.size();
        } else {
            idle_frame_count = 0;

            this->sprite.setTexture(this->walk_frames[walk_frame_count]);
            walk_frame_count = (walk_frame_count + 1) % walk_frames.size();
        }

        this->sprite.setPosition(x * step / 5, y * step / 5);
        if(is_mirrored) {
            setSize(this->sprite, -step, step);
            this->sprite.setPosition(x * step / 5 + step, y * step / 5);
        } else {
            setSize(this->sprite, step, step);
        }

        window.draw(this->sprite);
    }
};

struct Board {
    int nc {0};
    int nl {0};
    int step {0};
    sf::Sprite sprite;
    sf::RectangleShape rect;
    Board(int nc, int nl, int step, sf::Texture& texture) {
        this->nc = nc;
        this->nl = nl;
        this->step = step;
        this->sprite.setTexture(texture);
        setSize(this->sprite, nc * step, nl * step);
        this->sprite.setPosition(0, 0);

        // this->rect.setSize(sf::Vector2f(step, step));
        // this->rect.setFillColor(sf::Color::Transparent);

        // this->rect.setOutlineColor(sf::Color::Black);
        // this->rect.setOutlineThickness(2);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(this->sprite);

        // for(int i = 0; i < nc; i++) {
        //     for(int j = 0; j < nl; j++) {
        //         this->rect.setPosition(i * step, j * step);
        //         window.draw(this->rect);
        //     }
        // }
    }
};

void moveEntity(sf::Keyboard::Key key, Entity& entity, std::vector<sf::Keyboard::Key> move_keys) {
    if(key == move_keys[0]) {
        entity.x--;
        entity.is_idle = false;

        if(!entity.is_mirrored) {
            entity.is_mirrored = true;
        }
    } else if(key == move_keys[1]) {
        entity.y--;
        entity.is_idle = false;
    } else if(key == move_keys[2]) {
        entity.x++;
        entity.is_idle = false;

        if(entity.is_mirrored) {
            entity.is_mirrored = false;
        }
    } else if(key == move_keys[3]) {
        entity.y++;
        entity.is_idle = false;
    } else {
        entity.is_idle = true;
    }
}

int main() {

    sf::Texture background_tex { loadTexture("./images/background.png") };
    sf::Texture ground_tex { loadTexture("./images/ground.png") };
    sf::Texture zombie_tex { loadTexture("./images/Walk (1).png") };
    sf::Texture cat_tex { loadTexture("./images/Cat_Idle.png") };

    const int STEP {100};

    std::vector<sf::Texture> idle_frames { loadTexture("./images/Idle (1).png"), loadTexture("./images/Idle (2).png"), loadTexture("./images/Idle (3).png"), loadTexture("./images/Idle (4).png"), loadTexture("./images/Idle (5).png")};

    std::vector<sf::Texture> walk_frames { loadTexture("./images/Walk (1).png"), loadTexture("./images/Walk (2).png"), loadTexture("./images/Walk (3).png"), loadTexture("./images/Walk (4).png"), loadTexture("./images/Walk (5).png"), loadTexture("./images/Walk (6).png"), loadTexture("./images/Walk (7).png"), loadTexture("./images/Walk (8).png"), loadTexture("./images/Walk (9).png"), loadTexture("./images/Walk (10).png") };

    Entity zombie(1, 6, STEP, zombie_tex, idle_frames, walk_frames);
    Entity cat(55, 3, STEP, cat_tex, {cat_tex}, {cat_tex});
    Board board(13, 5, STEP, background_tex);

    cat.is_mirrored = true;

    sf::Sprite ground_sp;
    ground_sp.setTexture(ground_tex);


    sf::RenderWindow window(sf::VideoMode(board.nc * STEP, board.nl * STEP), "O Lobo e o Coelho na Floresta!", sf::Style::Close);

    char ground_matrix[board.nl][board.nc] = {
        {'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e'},
        {'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e'},
        {'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'g', 'g', 'g'},
        {'e', 'e', 'e', 'e', 'e', 'g', 'g', 'e', 'e', 'e', 'g', 'g', 'g', 'g'},
        {'g', 'g', 'g', 'g', 'g', 'g', 'g', 'e', 'g', 'g', 'g', 'g', 'g', 'g'}
    };

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if(event.type == sf::Event::KeyPressed) {
                moveEntity(event.key.code, zombie, {sf::Keyboard::Left, sf::Keyboard::Up, sf::Keyboard::Right, sf::Keyboard::Down});
            } else if(event.type == sf::Event::KeyReleased) {
                zombie.is_idle = true;
            }
        }

        window.clear();

        board.draw(window);
        zombie.draw(window);
        cat.draw(window);
        // rabbit.draw(window);

        for(int i = 0; i < board.nl; i++) {
            for(int j = 0; j < board.nc; j++) {
                if(ground_matrix[i][j] != 'e') {
                    ground_sp.setPosition(j * STEP, i * STEP);
                    window.draw(ground_sp);
                }
            }
        }

        window.display();

        Sleep(80);
    }

    return 0;
}

// Rodar SFML

// g++ -IC:\SFML-2.5.1\include -c main.cpp -o main.o
// g++ -LC:\SFML-2.5.1\lib .\main.o -o app.exe -lmingw32 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-main -mwindows