#include <stdexcept>
#include <gtest/gtest.h>

#include "../TreesContainer/TreeContainer.hpp"
#include "../Professor/Professor.hpp"
#include "../Student/Student.hpp"
#include "../StudentSecondSession/StudentSecondSession.hpp"


//.................STUDENT_PROFESSOR...........
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

//.............STUDENT_SESSION.........
TEST(testStudentBeforeSessionConstructors, testParameterConstructor)
{
    EXPECT_THROW(StudentBeforeSession("", 3, 324, 5452), std::invalid_argument);
    EXPECT_THROW(StudentBeforeSession("TEST", 7, 4532, 432442), std::logic_error);
    StudentBeforeSession test("TEST", 1, 7121, 43432);
    EXPECT_EQ(test.getName(), "TEST");
    EXPECT_EQ(test.getCourse(), 1);
    EXPECT_EQ(test.getGroup(), 7121);
    EXPECT_EQ(test.getBookNumber(), 43432);
}

TEST(testStudentBeforeSessionConstructors, testCopyConstructor)
{
    StudentBeforeSession test1("TEST", 2, 3442, 7), test2(test1, 56);
    EXPECT_EQ(test2.getName(), "TEST");
    EXPECT_EQ(test2.getCourse(), 2);
    EXPECT_EQ(test2.getGroup(), 3442);
    EXPECT_NE(test2.getBookNumber(), test1.getBookNumber());
    EXPECT_EQ(test2.getBookNumber(), 56);
}

TEST(testStudentBeforeSessionSetters, testNameSetter)
{
    StudentBeforeSession test("TEST", 1, 45, 5343);
    EXPECT_EQ(test.getName(), "TEST");
    EXPECT_THROW(test.setNewName(""), std::invalid_argument);
    test.setNewName("EQ");
    EXPECT_NE(test.getName(), "TEST");
    EXPECT_EQ(test.getName(), "EQ");
}

TEST(testStudentBeforeSessionSetters, testGroupSetter)
{
    StudentBeforeSession test("TEST", 1, 533, 5524);
    EXPECT_EQ(test.getGroup(), 533);
    test.setNewGroup(4);
    EXPECT_NE(test.getGroup(), 533);
    EXPECT_EQ(test.getGroup(), 4);
}

TEST(testStudentBeforeSessionSetters, testCourseSetter)
{
    StudentBeforeSession test("TEST", 5, 4, 545);
    EXPECT_THROW(test.setNewCourse(5353), std::logic_error);
    test.setNewCourse(3);
    EXPECT_EQ(test.getCourse(), 3);
}

TEST(testSudentFirstSessionConstructor, testParameterConstructor)
{
    EXPECT_THROW(StudentFirstSession ("", 4, 56, 7656), std::invalid_argument);
    EXPECT_THROW(StudentFirstSession ("TEST", 65, 56, 7656), std::logic_error);
    StudentFirstSession test("TEST", 4, 654, 333);
    EXPECT_EQ(test.getName(), "TEST");
    EXPECT_EQ(test.getCourse(), 4);
    EXPECT_EQ(test.getGroup(), 654);
    EXPECT_EQ(test.getBookNumber(), 333);
}

TEST(testSudentFirstSessionConstructor, testCopyConstructor)
{
    StudentFirstSession test1("TEST", 2, 768, 777), test2(test1, 696);
    EXPECT_EQ(test2.getName(), "TEST");
    EXPECT_EQ(test2.getCourse(), 2);
    EXPECT_EQ(test2.getGroup(), 768);
    EXPECT_NE(test2.getBookNumber(), test1.getBookNumber());
    EXPECT_EQ(test2.getBookNumber(), 696); 
}

TEST(testStudentFirstSessionMethods, testMarksWork)
{
    StudentFirstSession test("TEST", 1, 7554, 5425);
    EXPECT_THROW(test[8], std::invalid_argument);
    EXPECT_THROW(test.changeMark(8, 5), std::invalid_argument);
    EXPECT_THROW(test.changeMark(3, 15), std::invalid_argument);
    test.changeMark(0, 7);
    EXPECT_EQ(test[0], 7);
    test.changeMark(1, 9);
    test.changeMark(2, 6);
    test.changeMark(3, 4);
    EXPECT_DOUBLE_EQ(test.getAverageMark(), 6.5);
}

//.................TREES...............
TEST(testTrees, testConstructorsAndGetters)
{
    FruitTree testTree1("Test", 45, treeTypes::Leafy, 5.7, 53);
    EXPECT_EQ(testTree1.getTreeAge(), 45);
    EXPECT_EQ(testTree1.getTreeName(), "Test");
    EXPECT_EQ(testTree1.getTreeType(), treeTypes::Leafy);
    EXPECT_DOUBLE_EQ(testTree1.getCropMass(), 5.7);
    EXPECT_EQ(testTree1.getStorageDration(), 53);

    ForestTree testTree2("Test", 2, treeTypes::Coniferous, 12.4);
    EXPECT_EQ(testTree2.getTreeName(), "Test");
    EXPECT_EQ(testTree2.getTreeAge(), 2);
    EXPECT_EQ(testTree2.getTreeType(), treeTypes::Coniferous);
    EXPECT_DOUBLE_EQ(testTree2.getWoodAmount(), 12.4);
}

TEST(testTreeContainer, testWork)
{
    TreesContainer testContainer;
    EXPECT_EQ(testContainer.getContainerSize(), 0);

    FruitTree* testTree1 = new FruitTree("Test", 45, treeTypes::Leafy, 5.7, 53);
    ForestTree* testTree2 = new ForestTree("Test", 2, treeTypes::Coniferous, 12.4);
    FruitTree* testTree3 = new FruitTree("Test", 81, treeTypes::Leafy, 6.12, 32);

    testContainer.pushBack(testTree1);
    EXPECT_EQ(testContainer.getContainerSize(), 1);
    testContainer.pushBack(testTree2);
    EXPECT_EQ(testContainer.getContainerSize(), 2);
    testContainer.pushBack(testTree3);
    
    EXPECT_EQ(testContainer.countingByTreeType(treeTypes::Coniferous), 1);
    EXPECT_EQ(testContainer.countingByTreeType(treeTypes::Leafy), 2);
    delete testTree1;
    delete testTree2;
    delete testTree3;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
