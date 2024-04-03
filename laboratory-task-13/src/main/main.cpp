#include "../classFolder/student.hpp"
#include "../classFolder/professor.hpp"
#include "../classFolder/studentBeforeSession.hpp"
#include "../classFolder/studentAfterFirstSession.hpp"
#include "../classFolder/studentAfterSecondSession.hpp"
#include <iomanip>


int main()
{
	try {
		srand(time(NULL));
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

		std::cout << '\n';
		StudentAfterFirstSession obj1("Ber", 4, 6552, 52334324);
		obj1.print(std::cout);
		std::cout << '\n' << obj1.getAverageMark() << '\n';
		StudentAfterSecondSession obj2("Red", 3, 4332, 98644);
		obj2.print(std::cout);
		std::cout << "Average mark after a year: " << std::setprecision(3) << obj2.getAverageMark() << '\n';
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << '\n';
		std::cerr << "Type of exception: " << typeid(e).name() << '\n';
	}
	return 0;
}