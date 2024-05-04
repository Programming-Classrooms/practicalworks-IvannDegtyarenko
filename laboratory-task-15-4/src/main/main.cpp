#include "../functions/functions.hpp"

int main()
{
    try {
        std::vector<Student> toFIOFile;
        std::vector<Student> toGroupsFile;
        std::ifstream fileIn("src/files/Students.txt");
        readDataFromFile(toFIOFile, fileIn);
        fileIn.close();
        toGroupsFile = toFIOFile;
        std::sort(toFIOFile.begin(), toFIOFile.end(),
        [](const Student& lhs, const Student& rhs) {
            for (auto i : lhs.studentName) {
                i = toupper(i);
            }
            for (auto i : rhs.studentName) {
                i = toupper(i);
            }
            return lhs.studentName < rhs.studentName;
        });
        std::ofstream fileFIO("src/files/Fio.txt");
        writeDataToFile(toFIOFile, fileFIO);

        std::sort(toGroupsFile.begin(), toGroupsFile.end(),
        [](const Student& lhs, const Student& rhs) {
            if (lhs.course != rhs.course) {
                return lhs.course < rhs.course;
            }
            
            if (lhs.group != rhs.group) {
                return lhs.group < rhs.group;
            }
            for (auto i : lhs.studentName) {
                i = toupper(i);
            }
            for (auto i : rhs.studentName) {
                i = toupper(i);
            }
            return lhs.studentName < rhs.studentName;
        });

        std::ofstream fileGroups("src/files/Groups.txt");
        writeDataToFile(toGroupsFile, fileGroups);
    }
    catch (std::exception& err) {
        std::cerr << "Exception caught: " << err.what() << '\n';
        std::cerr << "Type of exception: " << typeid(err).name() << '\n';
    }
    return 0;
}