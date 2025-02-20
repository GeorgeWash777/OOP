#include "include/World.h"
#include "include/ObserverFile.h"
#include "include/ObserverConsole.h"
#include "include/Visitor.h"
#include <random>
#include "include/Bear.h"
#include "include/Elf.h"

int main() {
    // Bear bear("Bear", 123.4, 123.4, 10.0);
    // Elf elf("Bear", 123.0, 123.0, 10.0);
    // bear.KillOtherNPC(elf);
    // std::cout << elf.Alive();


    World world;
    Visitor visitor;
    ObserverConsole consoleObserver;
    ObserverFile fileObserver("log.txt");

    visitor.AddObserver(&consoleObserver);
    visitor.AddObserver(&fileObserver);

    double x, y, range;

    const char* types[] = { "Bear", "Elf", "Robber" };
    for (int i = 0; i < 50; ++i) {
        range = (rand() % 2500);
        x = (rand() % 5000);
        y = (rand() % 5000);
        range /= 10;
        x /= 10;
        y /= 10;

        std::string type = types[i % 3];
        world.AddNPC(type, type + "_" + std::to_string(i), x, y, range);
    }

    //world.Deserialize("dungeon.txt");
    std::cout << "Fighters in dungeon:\n";
    std::cout << "------------------------------------------------------------------" << std::endl;
    world.AllNPC();
    std::cout << "------------------------------------------------------------------" << std::endl;

    world.Engage(visitor);

    std::cout << "\nRemaining Fighters:\n";
    std::cout << "------------------------------------------------------------------" << std::endl;
    world.AllNPC();
    std::cout << "------------------------------------------------------------------" << std::endl;

    world.Serialize("dungeon.txt");

    return 0;
}