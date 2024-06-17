#include "functions.hpp"

void fillLakeWithFishes(std::set<std::string>& lake)
{
    std::string fish = "";
    std::cout << "Enter fishes that will be in the lake\nTo stop entering type in 'stop'\n";
    std::cin >> fish;
    while (fish != "stop") {
        lake.insert(fish);
        std::cin >> fish;
    }
}

void fillFishermanInfo(std::set<std::string>& fisherman, const std::set<std::string>& lake)
{
    std::string fish = "";
    std::cout << "Fishes in the lake are shown below:\n";
    for (const auto& i : lake) {
        std::cout << i << " ";
    }
    std::cout << '\n';
    std::cout << "Enter at least one fish that fisherman catched: ";
    std::cin >> fish;
    while (lake.find(fish) != lake.end()) {
        fisherman.insert(fish);
        std::cout << "Enter fish that fisherman can catch: ";
        std::cin >> fish;
    }
}
