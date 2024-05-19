#include "../NSDeque/deque.hpp"
#include "../Stack/stack.hpp"
#include "../Wagon/wagon.hpp"

void print(int element)
{
    std::cout << element << " ";
}

int main()
{
    try {
        srand(time(NULL));
        TDeque<int> myDeque;
        myDeque.InsertFront(2);
        myDeque.InsertFront(5);
        myDeque.InsertFront(7);
        myDeque.InsertFront(1);
        myDeque.InsertFront(3);
        myDeque.BrowseDnChange(print);
        std::cout << std::endl;
        myDeque.DeleteRear();
        myDeque.BrowseDnChange(print);
        std::cout << std::endl;
        myDeque.InsertRear(100);
        myDeque.BrowseDnChange(print);
        std::cout << '\n' << myDeque.GetInfoByIndex(3) << '\n';
        myDeque.BrowseNChange(print);
        std::cout << std::endl;

        Stack<Wagon> randWagons;
        randWagons.push(Wagon("green"));
        randWagons.push(Wagon("red"));
        randWagons.push(Wagon("red"));
        randWagons.push(Wagon("green"));
        randWagons.push(Wagon("green"));
        randWagons.push(Wagon("red"));
        
        Stack<Wagon> redWagons;
        Stack<Wagon> greenWagons;
        while (!randWagons.isEmpty()) {
            Wagon init = randWagons.pop();
            if (init.getColor() == "red") {
                redWagons.push(Wagon(init));
            }
            else {
                if (init.getColor() == "green") {
                    greenWagons.push(Wagon(init));
                }
            }
        }
        std::cout << "Check green Wagons:\n";
        greenWagons.print();
        std::cout << "Check red Wagons:\n";
        redWagons.print();

        Stack<char*> lines;
        lines.push("sd");
    }
    catch (std::exception& err) {
        std::cerr << "Exception caught: " << err.what() << '\n';
        std::cerr << "Exception type: " << typeid(err).name() << '\n';
    }
    return 0;
}
