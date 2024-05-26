#include "../classFolder/UsualFraction.hpp"
#include "../classFolder/Matrix.hpp"


int main()
{
    try {
		srand(time(NULL));
		std::cout << ".............FRACTION..............\n";

		UsualFraction fraction1;
		std::cout << fraction1 << '\n';
		UsualFraction fraction2(7, -13);
		UsualFraction fraction3(fraction2);

		std::cout << fraction3 << '\n';

		std::cout << fraction1.getNumerator() << " " << fraction2.getNumerator() << " " << fraction3.getNumerator() << '\n';
		std::cout << fraction1.getDenominator() << " " << fraction2.getDenominator() << " " << fraction3.getDenominator() << '\n';

		fraction1.setNumerator(6);
		fraction2.setNumerator(43);
		fraction3.setNumerator(-41);
		std::cout << fraction1 << " " << fraction2 << " " << fraction3 << '\n';

		std::cout << "...........MATRIX........\n";
		Matrix matrix1(1, 1);
		std::cout << matrix1;
		matrix1.setMtrxElement(0, 0, 15);
		std::cout << matrix1 << '\n';
		std::cout<< 2 * matrix1;
	}
	catch (std::invalid_argument& e) {
		std::cerr << e.what() << '\n';
	}
	catch (std::out_of_range& e){
		std::cerr << e.what() << '\n';
	}
	catch (std::runtime_error& e){
		std::cerr << e.what() << '\n';
	}
    return 0;
}
