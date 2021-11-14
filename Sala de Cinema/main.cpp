#include "client.cpp"
#include "room.cpp"

int main() {

    Room room(10);

    room.reserve("David", "1278", 5);
    room.reserve("Breno", "2478", 11);
    room.reserve("Bruno", "3678", 3);
    room.reserve("Lucas", "4478", 2);
    room.reserve("Cris", "5758", 1);
    room.reserve("Glaucio", "6578", 4);
    room.reserve("Nay", "7578", 3);
    room.reserve("David", "1668", 5);

    room.cancel("Jose");
    room.cancel("David");

    return 0;
}