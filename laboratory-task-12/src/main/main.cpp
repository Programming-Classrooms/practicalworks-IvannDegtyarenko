#include "../classFolder/usualFraction.hpp"


int main()
{
    try {
		std::cout << ".............FRACTION..............\n";

		UsualFraction main1;
		std::cout << main1 << '\n';
		UsualFraction main2(7, -13);
		UsualFraction main3(main2);

		std::cout << main3 << '\n';

		std::cout << main1.getNumerator() << " " << main2.getNumerator() << " " << main3.getNumerator() << '\n';
		std::cout << main1.getDenominator() << " " << main2.getDenominator() << " " << main3.getDenominator() << '\n';

		main1.setNumerator(6);
		main2.setNumerator(43);
		main3.setNumerator(-41);
		std::cout << main1 << " " << main2 << " " << main3 << '\n';
	}
	catch (std::invalid_argument& e) {
		std::cerr << e.what() << '\n';
	}
    return 0;
}