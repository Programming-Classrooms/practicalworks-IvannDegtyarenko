#include "../functions/functions.hpp"


int main()
{
    try {
        std::set<std::string> lake;
        fillLakeWithFishes(lake);
        
        std::set<std::string> firstFisherman;
        fillFishermanInfo(firstFisherman, lake);
        
        std::set<std::string> secondFisherman;
        fillFishermanInfo(secondFisherman, lake);
        
        std::set<std::string> thirdFisherman;
        fillFishermanInfo(thirdFisherman, lake);

        std::ofstream fout("src/info/data.txt");   

        fout << "First Fisherman catched: ";
        for (const auto& i : firstFisherman) {
            fout << i << " ";
        }
        fout << '\n';

        fout << "Second Fisherman catched: ";
        for (const auto& i : secondFisherman) {
            fout << i << " ";
        }
        fout << '\n';

        fout << "Third Fisherman catched: ";
        for (const auto& i : thirdFisherman) {
            fout << i << " ";
        }
        fout << '\n';

        std::set<std::string> sameFishes;
        std::set_intersection(firstFisherman.begin(), firstFisherman.end(), secondFisherman.begin(), secondFisherman.end(), std::inserter(sameFishes, sameFishes.begin()));
        std::set_intersection(sameFishes.begin(), sameFishes.end(), thirdFisherman.begin(), thirdFisherman.end(), std::inserter(sameFishes, sameFishes.begin()));
        fout << "Fishes that every Fisherman has: ";
        for (const auto& i : sameFishes) {
            fout << i << " ";
        }
        fout << '\n';

        std::set<std::string> catchedFishes;
        std::set_union(firstFisherman.begin(), firstFisherman.end(), secondFisherman.begin(), secondFisherman.end(), std::inserter(catchedFishes, catchedFishes.begin()));
        std::set_union(catchedFishes.begin(), catchedFishes.end(), thirdFisherman.begin(), thirdFisherman.end(), std::inserter(catchedFishes, catchedFishes.begin()));
        fout << "Fish present in at least one fisherman: ";
        for (const auto& i : catchedFishes) {
            fout << i << " ";
        }
        fout << '\n';

        std::set<std::string> leftFishes;
        std::set_difference(lake.begin(), lake.end(), catchedFishes.begin(), catchedFishes.end(), std::inserter(leftFishes, leftFishes.begin()));
        fout << "Fishes that are left in the lake: ";
        for (const auto& i : leftFishes) {
            fout << i << " ";
        }
        fout << '\n';
    }
    catch (std::exception& err) {
        std::cerr << "Exception caught: " << err.what() << '\n';
        std::cerr << "Exception type: " << typeid(err).name() << '\n';
    }
    return 0;
}
