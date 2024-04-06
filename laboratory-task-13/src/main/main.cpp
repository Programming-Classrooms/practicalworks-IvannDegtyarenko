#include "../classFolder/student.hpp"
#include "../classFolder/professor.hpp"
#include "../classFolder/studentBeforeSession.hpp"
#include "../classFolder/studentAfterFirstSession.hpp"
#include "../classFolder/studentAfterSecondSession.hpp"
#include "../classFolder/treeContainer.hpp"
#include <iomanip>
#include <fstream>


bool checkFile(std::ifstream& file, std::string path)
{
	if (!file.good()) {
		std::string mes = "File not found... Path: ";
		mes.append(path);
		throw std::invalid_argument(mes);
	}
	if (!file) {
		std::string mes = "File is bad... Path: ";
		mes.append(path);
		throw std::ios_base::failure(mes);
	}
	if (file.peek() == EOF) {
		std::string mes = "File is empti... Path: ";
		mes.append(path);
		throw std::runtime_error(mes);
	}
	return true;
}

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

//.................STUDENT_SESSION........

		std::cout << '\n';
		StudentAfterFirstSession obj1("Ber", 4, 6552, 52334324);
		obj1.print(std::cout);
		std::cout << '\n' << obj1.getAverageMark() << '\n';
		StudentAfterSecondSession obj2("Red", 3, 4332, 98644);
		obj2.print(std::cout);
		std::cout << "Average mark after a year: " << std::setprecision(3) << obj2.getAverageMark() << '\n';

//..................TREES.........................
		std::cout<<"############################\n";
		TreesContainer trees;
		std::string pathToFile = "src/files/trees.txt";
		std::ifstream fin(pathToFile);
		if (checkFile(fin, pathToFile)) {
			fin >> trees;
		}
		trees.print();
		std::cout << trees.countingByTreeType(treeTypes::Leafy);
		trees.sortTreesVector();
		trees.print();
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << '\n';
		std::cerr << "Type of exception: " << typeid(e).name() << '\n';
	}
	return 0;
}