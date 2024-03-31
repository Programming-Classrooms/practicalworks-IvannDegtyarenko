#include "../classFolder/student.hpp"
#include "../classFolder/professor.hpp"


int main()
{
	try {
		Student a("Refer T.R.", 2, 5634);
		std::cout << a << '\n';
		Professor b("Bert G.K.", "Mechanichs");
		std::cout << b << '\n';
		Student c, d, e, f;
		Student* studArr[4] = { &c, &d, &e, &f };
		for (size_t i = 0; i < 4; ++i) {
			studArr[i]->print(std::cout);
			std::cout << '\n';
		}
		
		Professor i("Kursov V.I.", "FPMI");
		Professor o("Gerty U.I.", "Philology");
		Professor* profArr[3] = { &b, &i, &o };
		for (size_t i = 0; i < 3; ++i) {
			profArr[i]->print(std::cout);
			std::cout << '\n';
		}
	}
	catch (std::runtime_error& e) {
		std::cerr << e.what() << '\n';
	}
	catch (std::invalid_argument& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}