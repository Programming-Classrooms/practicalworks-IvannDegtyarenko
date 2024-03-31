#include <stdexcept>
#include <gtest/gtest.h>
#include "../classFolder/person.hpp"
#include "../classFolder/student.hpp"
#include "../classFolder/professor.hpp"

TEST(testPersonConstructors, testParameterConstructor)
{
    EXPECT_THROW(Person test1(""), std::runtime_error);
    Person test2("Gert");
    EXPECT_STREQ(test2.getPersonFullName(), "Gert");
}

TEST(testPersonConstructors, testCopyConstructor)
{
    Person test1("Ager"), test2(test1);
    EXPECT_STREQ(test1.getPersonFullName(), test2.getPersonFullName());
    EXPECT_STREQ("Ager", test2.getPersonFullName());
}

TEST(testPersonSetters, testFullNameSetter)
{
    Person test1("Todo");
    EXPECT_STRNE(test1.getPersonFullName(), "Izu");
    EXPECT_THROW(test1.setPersonFullName(""), std::runtime_error);
    test1.setPersonFullName("Izu");
    EXPECT_STREQ(test1.getPersonFullName(), "Izu");
}

TEST(testPersonGetters, testFullNameGetter)
{
    Person test1("Itadori");
    EXPECT_STREQ(test1.getPersonFullName(), "Itadori");
    EXPECT_STRNE(test1.getPersonFullName(), "S");
}

TEST(testStudentConstructors, testDefaultConstructor)
{
    Student test1;
    EXPECT_STREQ(test1.getPersonFullName(), "Student's Name");
    EXPECT_EQ(test1.getCourse(), 1);
    EXPECT_EQ(test1.getGroup(), 7121);
}

TEST(testStudentConstructors, testParameterConstructor)
{
    EXPECT_THROW(Student test1("", 3, 7422), std::runtime_error);
    EXPECT_THROW(Student test2("TEST", 54324, 7422), std::invalid_argument);
    Student test3("TEST", 3, 7101);
    EXPECT_STREQ(test3.getPersonFullName(), "TEST");
    EXPECT_EQ(test3.getCourse(), 3);
    EXPECT_EQ(test3.getGroup(), 7101);
}

TEST(testStudentConstructors, testCopyConstructor)
{
    Student test1("TEST", 4, 7091), test2(test1);
    EXPECT_STREQ(test1.getPersonFullName(), test2.getPersonFullName());
    EXPECT_EQ(test1.getCourse(), test2.getCourse());
    EXPECT_EQ(test1.getGroup(), test2.getGroup());
}

TEST(testStudentGetters, testCourseGetter)
{
    Student test1, test2("TEST", 3, 4322), test3(test2);
    EXPECT_EQ(test1.getCourse(), 1);
    EXPECT_EQ(test2.getCourse(), 3);
    EXPECT_EQ(test3.getCourse(), 3);
}

TEST(testStudentGetters, testGroupGetter)
{
    Student test1, test2("TEST", 2, 52432), test3(test1);
    EXPECT_EQ(test1.getGroup(), 7121);
    EXPECT_EQ(test2.getGroup(), 52432);
    EXPECT_EQ(test3.getGroup(), 7121);
}

TEST(testStudentSetters, testCourseSetter)
{
    Student test1;
    EXPECT_EQ(test1.getCourse(), 1);
    EXPECT_THROW(test1.setCourse(10), std::invalid_argument);
    test1.setCourse(5);
    EXPECT_EQ(test1.getCourse(), 5);
}

TEST(testStudentSetters, testGroupSetter)
{
    Student test1;
    EXPECT_EQ(test1.getGroup(), 7121);
    test1.setGroup(1217);
    EXPECT_EQ(test1.getGroup(), 1217);
}

TEST(testProfessorConstructors, testDefaultConstructor)
{
    Professor test1;
    EXPECT_STREQ(test1.getPersonFullName(), "Professor's Name");
    EXPECT_STREQ(test1.getDepartment(), "Dekanat");
}

TEST(testProfessorConstructors, testParameterConstructor)
{
    EXPECT_THROW(Professor test1("", "TEST"), std::runtime_error);
    EXPECT_THROW(Professor test2("TEST", ""), std::runtime_error);
    Professor test3("TEST", "MORE");
    EXPECT_STREQ(test3.getPersonFullName(), "TEST");
    EXPECT_STREQ(test3.getDepartment(), "MORE");
}

TEST(testProfessorConstructors, testCopyConstructor)
{
    Professor test1("MORE", "TEST"), test2(test1);
    EXPECT_STREQ(test2.getPersonFullName(), "MORE");
    EXPECT_STREQ(test2.getDepartment(), "TEST");
}

TEST(testProfessorGetters, testDepartmentGetter)
{
    Professor test1, test2("TEST", "MORE");
    EXPECT_STREQ(test1.getDepartment(), "Dekanat");
    EXPECT_STREQ(test2.getDepartment(), "MORE");
}

TEST(testProfessorSetters, testDepartmentSetter)
{
    Professor test1;
    EXPECT_STREQ(test1.getDepartment(), "Dekanat");
    EXPECT_THROW(test1.setDepartment(""), std::runtime_error);
    test1.setDepartment("FPMI");
    EXPECT_STREQ(test1.getDepartment(), "FPMI");
}