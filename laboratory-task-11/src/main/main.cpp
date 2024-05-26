#include "../myString/myString.hpp"


int main()
{
	try {
		MyString a("fer");
		std::cout << a;
		a = "red";
		a += "der";
		a.toUpperCase();
		std::cout << a;
		a.toLowerCase();
		std::cout << a;
		std::cout << a[0] << '\n';
		a.printString();
		std::cin >> a;
		a.toUpperCase();
		std::cout << a;
		MyString c;
		std::cout << c.getSize() << '\n';
		MyString b("FER");
		if (a == b) {
			std::cout << "Strings are equal\n";
		}
		else {
			std::cout << "Strings are not equal\n";
		}
		MyString v("abcr");
		MyString n("abf");
		if (v < n) {
			std::cout << "Left is less\n";
		}
		else {
			std::cout<<"Right is less\n";
		}
	}
	catch (std::invalid_argument& e) {
		std::cerr << e.what();
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
	catch (std::out_of_range& e) {
		std::cerr << e.what();
	}
	return 0;
}
