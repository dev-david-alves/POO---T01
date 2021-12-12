#include <iostream>

class Animal {
    private:
        bool is_alive;
        bool is_multicellular;
        bool is_vertebrate;

    public:
        Animal (bool is_alive, bool is_multicellular, bool is_vertebrate) : is_alive(is_alive), is_multicellular(is_multicellular), is_vertebrate(is_vertebrate) {}

        void move() {
            std::cout << "Animal is moving.\n";
        }

        void eat() {
            std::cout << "Animal is eating.\n";
        }

        void sleep() {
            std::cout << "Animal is sleeping.\n";
        }

        void set_is_alive(bool is_alive) {
            this->is_alive = is_alive;
        }

        void set_is_multicellular(bool is_multicellular) {
            this->is_multicellular = is_multicellular;
        }

        void set_is_vertebrate(bool is_vertebrate) {
            this->is_vertebrate = is_vertebrate;
        }

        bool get_is_alive() {
            return this->is_alive;
        }

        bool get_is_multicellular() {
            return this->is_multicellular;
        }

        bool get_is_vertebrate() {
            return this->is_vertebrate;
        }

        friend std::ostream& operator<<(std::ostream& os, const Animal& animal) {
            os << "Animal is alive: " << animal.is_alive << ".\n";
            os << "Animal is multicellular: " << animal.is_multicellular << ".\n";
            os << "Animal is vertebrate: " << animal.is_vertebrate << ".\n";
            return os;
        }
};

class Ape: public Animal {
    private:
        bool has_long_neck;
        bool has_long_legs;
        bool is_mammal;
        bool is_biped;

    public:
        Ape (bool is_alive, bool is_multicellular, bool is_vertebrate, bool has_long_neck, bool has_long_legs, bool is_mammal, bool is_biped) : Animal(is_alive, is_multicellular, is_vertebrate), has_long_neck(has_long_neck), has_long_legs(has_long_legs), is_mammal(is_mammal), is_biped(is_biped) {}

        void move() {
            if(this->get_is_biped()) {
                std::cout << "Ape is moving.\n";
            } else {
                std::cout << "Ape is crawling.\n";
            }
        }

        void eat() {
            std::cout << "Ape is eating.\n";
        }

        void sleep() {
            std::cout << "Ape is sleeping.\n";
        }

        // Getters and setters

        void set_has_long_neck(bool has_long_neck) {
            this->has_long_neck = has_long_neck;
        }

        void set_has_long_legs(bool has_long_legs) {
            this->has_long_legs = has_long_legs;
        }

        void set_is_mammal(bool is_mammal) {
            this->is_mammal = is_mammal;
        }

        void set_is_biped(bool is_biped) {
            this->is_biped = is_biped;
        }

        bool get_has_long_neck() {
            return this->has_long_neck;
        }

        bool get_has_long_legs() {
            return this->has_long_legs;
        }

        bool get_is_mammal() {
            return this->is_mammal;
        }

        bool get_is_biped() {
            return this->is_biped;
        }

        friend std::ostream& operator<<(std::ostream& os, const Ape& ape) {
            os << "Has long neck: " << ape.has_long_neck << ".\n";
            os << "Has long legs: " << ape.has_long_legs << ".\n";
            os << "Is mammal: " << ape.is_mammal << ".\n";
            os << "Is biped: " << ape.is_biped << ".\n";
            return os;
        }
};

class Human: public Ape {
    private:
        bool has_two_eyes;
        bool has_two_hands;
        bool has_two_legs;

    public:
        Human (bool is_alive, bool is_multicellular, bool is_vertebrate, bool has_long_neck, bool has_long_legs, bool is_mammal, bool is_biped, bool has_two_eyes, bool has_two_hands, bool has_two_legs) : Ape(is_alive, is_multicellular, is_vertebrate, has_long_neck, has_long_legs, is_mammal, is_biped), has_two_eyes(has_two_eyes), has_two_hands(has_two_hands), has_two_legs(has_two_legs) {}

        void move() {
            if(Ape::get_is_biped() && this->get_has_two_legs()) {
                std::cout << "Human is moving with two legs.\n";
            } else {
                std::cout << "Human is using a wheelchair.\n";
            }
        }

        void eat() {
            std::cout << "Human is eating.\n";
        }

        void sleep() {
            std::cout << "Human is sleeping.\n";
        }

        // Getters and setters

        void set_has_two_eyes(bool has_two_eyes) {
            this->has_two_eyes = has_two_eyes;
        }

        void set_has_two_hands(bool has_two_hands) {
            this->has_two_hands = has_two_hands;
        }

        void set_has_two_legs(bool has_two_legs) {
            this->has_two_legs = has_two_legs;
        }

        bool get_has_two_eyes() {
            return this->has_two_eyes;
        }

        bool get_has_two_hands() {
            return this->has_two_hands;
        }

        bool get_has_two_legs() {
            return this->has_two_legs;
        }

        friend std::ostream& operator<<(std::ostream& os, const Human& human) {
            os << "Has two eyes: " << human.has_two_eyes << ".\n";
            os << "Has two hands: " << human.has_two_hands << ".\n";
            os << "Has two legs: " << human.has_two_legs << ".\n";
            return os;
        }
};

int main() {
    Human human(true, true, true, true, true, true, true, true, true, true);
    std::cout << human;
    human.move();
    human.eat();
    human.sleep();
    human.set_has_two_legs(false);
    human.move();
    std::cout << human;

    Ape& ape = human;
    std::cout << ape;
    ape.move();
    ape.eat();
    ape.sleep();

    Animal& animal = ape;
    std::cout << animal;
    animal.move();
    animal.eat();
    animal.sleep();

    std::cout << "End of program.\n";

    return 0;
}