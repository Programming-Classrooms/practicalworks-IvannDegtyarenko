#include "functions.hpp"

void checkInputFile(std::ifstream& file)
{
    if (!file.good()) {
        throw std::runtime_error("File does not exist");
    }
    if (!file) {
        throw std::runtime_error("File is not open");
    }
    if (file.peek() == EOF) {
        throw std::runtime_error("File is empty");
    }
}

void checkOutputFile(std::ofstream& file)
{
    if (!file) {
        throw std::runtime_error("File is not open");
    }
    if(file.fail()) {
        throw std::runtime_error("File output operation failed");
    }
}

void readDataFromFile(std::vector<Student>& vector, std::ifstream& file)
{
    std::string studentFIO = "";
    std::string studentSurename = "", studentName = "", studentFathername = "";
    size_t studentCourse = 0, studentGroup = 0;
    while (file >> studentSurename) {
        file >> studentName >> studentFathername >> studentCourse >> studentGroup;
        studentFIO = studentSurename + " " + studentName + " " + studentFathername;
        vector.push_back(Student(studentFIO, studentCourse, studentGroup));
    }
    file.close();
}

void writeDataToFile(const std::vector<Student>& vector, std::ofstream& file)
{
    for (const Student& i : vector) {
        file << i.studentName << " " << i.course << " " << i.group << '\n';
    }
    file.close();
}