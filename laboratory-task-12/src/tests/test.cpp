#include <gtest/gtest.h>
#include <stdexcept>

#include "../Fraction/UsualFraction.hpp"
#include "../Matrix/Matrix.hpp"


//................FRACTION.............
TEST(testFractionConstructors, testDefaultConstructor)
{
    UsualFraction test;
    EXPECT_EQ(test.getNumerator(), 0);
    EXPECT_EQ(test.getDenominator(), 1);
}

TEST(testFractionConstructors, testParameterConstructor)
{
    EXPECT_THROW(UsualFraction(1,0), std::invalid_argument);
    EXPECT_NO_THROW(UsualFraction(1,1));
    UsualFraction test1(34, 5);
    EXPECT_EQ(test1.getNumerator(), 34);
    EXPECT_EQ(test1.getDenominator(), 5);
    UsualFraction test2(5, -7);
    EXPECT_EQ(test2.getNumerator(), -5);
    EXPECT_EQ(test2.getDenominator(), 7);
}

TEST(testFractionConstructors, testCopyConstructor)
{
    UsualFraction test1(8, -9);
    UsualFraction test2(test1);
    EXPECT_EQ(test2.getNumerator(), -8);
    EXPECT_EQ(test2.getDenominator(), 9);
}

TEST(testFractionGetters, testNumeratorGetter)
{
    UsualFraction test1(-7, 9);
    UsualFraction test2(5, -4);
    EXPECT_EQ(test1.getNumerator(), -7);
    EXPECT_NE(test1.getNumerator(), 7);
    EXPECT_EQ(test2.getNumerator(), -5);
    EXPECT_NE(test2.getNumerator(), 5);
}

TEST(testFractionGetters, testDenominatorGetter)
{
    UsualFraction test1(8, -9);
    UsualFraction test2(-7, 15);
    EXPECT_EQ(test1.getDenominator(), 9);
    EXPECT_NE(test1.getDenominator(), -9);
    EXPECT_EQ(test2.getDenominator(), 15);
    EXPECT_NE(test2.getDenominator(), -15);
}

TEST(testFractionSetters, testNumeratorSetter)
{
    UsualFraction test1(4, 7);
    EXPECT_EQ(test1.getNumerator(), 4);
    test1.setNumerator(8);
    EXPECT_EQ(test1.getNumerator(), 8);
}

TEST(testFractionSetters, testDenominatorSetter)
{
    UsualFraction test1(4, -5);
    EXPECT_EQ(test1.getDenominator(), 5);
    EXPECT_THROW(test1.setDenominator(0), std::invalid_argument);
    test1.setDenominator(-9);
    EXPECT_EQ(test1.getDenominator(), 9);
}

TEST(testFractionClassMethod, testSimplifyMethod)
{
    UsualFraction test1(24, 15);
    UsualFraction test2(8, 5);
    EXPECT_NE(test1.getNumerator(), test2.getNumerator());
    EXPECT_NE(test1.getDenominator(), test2.getDenominator());
    test1 = test1.simplifyFraction();
    EXPECT_EQ(test1.getNumerator(), test2.getNumerator());
    EXPECT_EQ(test1.getDenominator(), test2.getDenominator());
}

TEST(testFractionOperators, testOperatorPlus)
{
    UsualFraction test1(-7, 3);
    UsualFraction test2(11, -13);
    UsualFraction checkTest(124, -39);
    EXPECT_NE(test1.getNumerator(), checkTest.getNumerator());
    EXPECT_NE(test2.getNumerator(), checkTest.getNumerator());
    EXPECT_NE(test1.getDenominator(), checkTest.getDenominator());
    EXPECT_NE(test2.getDenominator(), checkTest.getDenominator());
    EXPECT_EQ((test1 + test2).getNumerator(), checkTest.getNumerator());
    EXPECT_EQ((test1 + test2).getDenominator(), checkTest.getDenominator());
}

TEST(testFractionOperators, testOperatorMinus)
{
    UsualFraction test1(-16, 9);
    UsualFraction test2(8, -7);
    UsualFraction checkTest(-40, 63);
    EXPECT_NE(test1.getNumerator(), checkTest.getNumerator());
    EXPECT_NE(test2.getNumerator(), checkTest.getNumerator());
    EXPECT_NE(test1.getDenominator(), checkTest.getDenominator());
    EXPECT_NE(test2.getDenominator(), checkTest.getDenominator());
    EXPECT_EQ((test1 - test2).getNumerator(), checkTest.getNumerator());
    EXPECT_EQ((test1 - test2).getDenominator(), checkTest.getDenominator());
}

TEST(testFractionOperators, testOperatorMultiply)
{
    UsualFraction test1(7, -25);
    UsualFraction test2(-50, 35);
    UsualFraction checkTest(2, 5);
    EXPECT_NE(test1.getNumerator(), checkTest.getNumerator());
    EXPECT_NE(test2.getNumerator(), checkTest.getNumerator());
    EXPECT_NE(test1.getDenominator(), checkTest.getDenominator());
    EXPECT_NE(test2.getDenominator(), checkTest.getDenominator());
    EXPECT_EQ((test1 * test2).getNumerator(), checkTest.getNumerator());
    EXPECT_EQ((test1 * test2).getDenominator(), checkTest.getDenominator());
}

TEST(testFractionOperators, testOperatorDivide)
{
    UsualFraction test1(-6, 13);
    UsualFraction test2(41, -7);
    UsualFraction checkTest(42, 533);
    EXPECT_NE(test1.getNumerator(), checkTest.getNumerator());
    EXPECT_NE(test2.getNumerator(), checkTest.getNumerator());
    EXPECT_NE(test1.getDenominator(), checkTest.getDenominator());
    EXPECT_NE(test2.getDenominator(), checkTest.getDenominator());
    EXPECT_EQ((test1 / test2).getNumerator(), checkTest.getNumerator());
    EXPECT_EQ((test1 / test2).getDenominator(), checkTest.getDenominator());
}

TEST(testFractionOperators, testPrefixIncrement)
{
    UsualFraction test1(5, 7);
    UsualFraction test2(12, 7);
    EXPECT_NE(test1.getNumerator(), test2.getNumerator());
    EXPECT_EQ((++test1).getNumerator(), test2.getNumerator());
}

TEST(testFractionOperators, testPrefixDecrement)
{
    UsualFraction test1(24, 5);
    UsualFraction test2(19, 5);
    EXPECT_NE(test1.getNumerator(), test2.getNumerator());
    EXPECT_EQ((--test1).getNumerator(), test2.getNumerator());
}

TEST(testFractionOperators, testPostfixIncrement)
{
    UsualFraction test1(5, 7);
    UsualFraction test2(12, 7);
    EXPECT_NE((test1++).getNumerator(), test2.getNumerator());
    EXPECT_EQ(test1.getNumerator(), test2.getNumerator());
}

TEST(testFractionOperators, testPostfixDecrement)
{
    UsualFraction test1(24, 5);
    UsualFraction test2(19, 5);
    EXPECT_NE(test1--.getNumerator(), test2.getNumerator());
    EXPECT_EQ(test1.getNumerator(), test2.getNumerator());
}

TEST(testFractionUnaryOperators, testUnaryMinus)
{
    UsualFraction test1(7, -8);
    EXPECT_EQ(-test1.getNumerator(), 7);
    UsualFraction test2(-5, 6);
    EXPECT_NE(-test2.getNumerator(), -5);
    EXPECT_EQ(-test2.getNumerator(), 5);
}

TEST(testFractionUnaryOperators, testInverseFraction)
{
    UsualFraction test1(6, 7);
    UsualFraction test2(7, 6);
    EXPECT_EQ((!test1).getNumerator(), test2.getNumerator());
    EXPECT_EQ((!test1).getDenominator(), test2.getDenominator());
    UsualFraction badFraction;
    EXPECT_THROW((!badFraction), std::invalid_argument);
}

TEST(testFractionBoolOperators, testOperatorNEq)
{
    UsualFraction test1(5, 7);
    UsualFraction test2(test1);
    UsualFraction test3(-21, 15);
    EXPECT_FALSE(test1 != test2);
    EXPECT_TRUE(test1 != test3);
    EXPECT_TRUE(test2 != test3);
}

TEST(testFractionBoolOperators, testOperatorLess)
{
    UsualFraction test1(5, 7);
    UsualFraction test2(6, 7);
    EXPECT_TRUE(test1 < test2);
    EXPECT_FALSE(test2 < test1);
    UsualFraction test3(1, 2);
    UsualFraction test4(1, 8);
    EXPECT_TRUE(test4 < test3);
    EXPECT_FALSE(test3 < test4);
}

TEST(testFractionOperators, testPlusEq)
{
    UsualFraction test1(-7, 3);
    UsualFraction test2(11, -13);
    UsualFraction checkTest(124, -39);
    EXPECT_NE(test1.getNumerator(), checkTest.getNumerator());
    EXPECT_NE(test2.getNumerator(), checkTest.getNumerator());
    EXPECT_NE(test1.getDenominator(), checkTest.getDenominator());
    EXPECT_NE(test2.getDenominator(), checkTest.getDenominator());
    test1 += test2;
    EXPECT_EQ(test1.getNumerator(), checkTest.getNumerator());
    EXPECT_EQ(test1.getDenominator(), checkTest.getDenominator());
}

TEST(testFractionOperators, testMinusEq)
{
    UsualFraction test1(-16, 9);
    UsualFraction test2(8, -7);
    UsualFraction checkTest(-40, 63);
    EXPECT_NE(test1.getNumerator(), checkTest.getNumerator());
    EXPECT_NE(test2.getNumerator(), checkTest.getNumerator());
    EXPECT_NE(test1.getDenominator(), checkTest.getDenominator());
    EXPECT_NE(test2.getDenominator(), checkTest.getDenominator());
    test1 -= test2;
    EXPECT_EQ(test1.getNumerator(), checkTest.getNumerator());
    EXPECT_EQ(test1.getDenominator(), checkTest.getDenominator());
}

TEST(testFractionOperators, testMultiplyEq)
{
    UsualFraction test1(7, -25);
    UsualFraction test2(-50, 35);
    UsualFraction checkTest(2, 5);
    EXPECT_NE(test1.getNumerator(), checkTest.getNumerator());
    EXPECT_NE(test2.getNumerator(), checkTest.getNumerator());
    EXPECT_NE(test1.getDenominator(), checkTest.getDenominator());
    EXPECT_NE(test2.getDenominator(), checkTest.getDenominator());
    test1 *= test2;
    EXPECT_EQ(test1.getNumerator(), checkTest.getNumerator());
    EXPECT_EQ(test1.getDenominator(), checkTest.getDenominator());
}

TEST(testFractionOperators, testDivideEq)
{
    UsualFraction test1(-6, 13);
    UsualFraction test2(41, -7);
    UsualFraction checkTest(42, 533);
    EXPECT_NE(test1.getNumerator(), checkTest.getNumerator());
    EXPECT_NE(test2.getNumerator(), checkTest.getNumerator());
    EXPECT_NE(test1.getDenominator(), checkTest.getDenominator());
    EXPECT_NE(test2.getDenominator(), checkTest.getDenominator());
    test1 /= test2;
    EXPECT_EQ(test1.getNumerator(), checkTest.getNumerator());
    EXPECT_EQ(test1.getDenominator(), checkTest.getDenominator());
}

TEST(testFractionOperators, testEq)
{
    UsualFraction test1;
    UsualFraction test2(6, -13);
    test1 = test2;
    EXPECT_EQ(test1.getNumerator(), -6);
    EXPECT_EQ(test1.getDenominator(), 13);
}

//....................MATRIX...............

TEST(testMatrixConstructors, testDefaultConstructor)
{
    Matrix test1;
    EXPECT_EQ(test1.getColumns(), 1);
    EXPECT_EQ(test1.getRows(), 1);
    EXPECT_THROW(Matrix wrongMtrx1(-4, 7), std::invalid_argument);
    EXPECT_THROW(Matrix wrongMtrx2(5, -32), std::invalid_argument);
    Matrix test2(6, 3);
    EXPECT_EQ(test2.getRows(), 6);
    EXPECT_EQ(test2.getColumns(), 3);
}

TEST(testMatrixConstructors, testCopyConstructor)
{
    Matrix test1(5, 7);
    Matrix test2(test1);
    EXPECT_EQ(test2.getRows(), 5);
    EXPECT_EQ(test2.getColumns(), 7);
}

TEST(testMatrixGetters, testRowsGetter)
{
    Matrix test1(7, 4);
    EXPECT_NE(test1.getRows(), 4);
    EXPECT_EQ(test1.getRows(), 7);
}

TEST(testMatrixGetters, testColumnsGetter)
{
    Matrix test1(5, 8);
    EXPECT_NE(test1.getColumns(), 5);
    EXPECT_EQ(test1.getColumns(), 8);
}

TEST(testMatrixGetters, testMatrixElemGetter)
{
    Matrix test1(1, 1);
    EXPECT_THROW(test1.getMatrixElement(5, 0), std::out_of_range);
    EXPECT_THROW(test1.getMatrixElement(0, -2), std::out_of_range);
    Matrix test2(test1);
    EXPECT_EQ(test1.getMatrixElement(0, 0), test2.getMatrixElement(0, 0));
}

TEST(testMatrixSetters, testRowsSetter)
{
    Matrix test1(5, 4);
    EXPECT_EQ(test1.getRows(), 5);
    EXPECT_NE(test1.getRows(), 8);
    EXPECT_THROW(test1.setRows(-6), std::invalid_argument);
    test1.setRows(8);
    EXPECT_EQ(test1.getRows(), 8);
    EXPECT_NE(test1.getRows(), 5);
}

TEST(testMatrixSetters, testColumnsSetter)
{
    Matrix test1(3, 7);
    EXPECT_EQ(test1.getColumns(), 7);
    EXPECT_NE(test1.getColumns(), 15);
    EXPECT_THROW(test1.setColumns(0), std::invalid_argument);
    test1.setColumns(15);
    EXPECT_NE(test1.getColumns(), 7);
    EXPECT_EQ(test1.getColumns(), 15);
}

TEST(testMatrixSetters, testElemSetter)
{
    Matrix test1(3, 2);
    EXPECT_THROW(test1.setMtrxElement(5, 1, 6), std::out_of_range);
    EXPECT_THROW(test1.setMtrxElement(2, 2, 6), std::out_of_range);
    test1.setMtrxElement(2, 1, 45);
    EXPECT_EQ(test1.getMatrixElement(2, 1), 45);
}

TEST(testMatrixOperators, testEq)
{
    Matrix test1(4, 5);
    Matrix test2(3, 2);
    EXPECT_NE(test1.getColumns(), test2.getColumns());
    EXPECT_NE(test1.getRows(), test2.getRows());

    test1 = test2;
    EXPECT_EQ(test1.getColumns(), test2.getColumns());
    EXPECT_EQ(test1.getRows(), test2.getRows());

    for (size_t i = 0; i < test2.getRows(); ++i) {
        for (size_t j = 0; j < test2.getColumns(); ++j) {
            EXPECT_EQ(test1.getMatrixElement(i, j), test2.getMatrixElement(i, j));
        }
    }
}

TEST(testMatrixOperators, testPlusEq)
{
    Matrix test1(2, 2);
    Matrix test2(4, 6);
    Matrix test3(2, 2);
    Matrix test4(test1);
    EXPECT_THROW((test1 += test2), std::runtime_error);
    test1 += test3;

    for (size_t i = 0; i < test1.getRows(); ++i) {
        for (size_t j = 0; j < test1.getColumns(); ++j) {
            EXPECT_EQ(test1.getMatrixElement(i, j), (test3.getMatrixElement(i, j) + test4.getMatrixElement(i, j)));
        }
    }
}

TEST(testMatrixOperators, testMinusEq)
{
    Matrix test1(2, 2);
    Matrix test2(4, 6);
    Matrix test3(2, 2);
    Matrix test4(test1);
    EXPECT_THROW((test1 -= test2), std::runtime_error);
    test1 -= test3;

    for (size_t i = 0; i < test1.getRows(); ++i) {
        for (size_t j = 0; j < test1.getColumns(); ++j) {
            EXPECT_EQ(test1.getMatrixElement(i, j), (test4.getMatrixElement(i, j) - test3.getMatrixElement(i, j)));
        }
    }
}

TEST(testMatrixOperators, testScalarMultiply)
{
    Matrix test1(1, 1);
    test1.setMtrxElement(0, 0, 7);
    6 * test1;
    EXPECT_EQ(test1.getMatrixElement(0, 0), 42);
    Matrix test2(1, 1);
    test2.setMtrxElement(0, 0, 8);
    test2 * 8;
    EXPECT_EQ(test2.getMatrixElement(0, 0), 64);
}

TEST(testMatrixOperators, testScalarDivide)
{
    Matrix test1(1, 1);
    test1.setMtrxElement(0, 0, 72);
    EXPECT_THROW((test1 / 0), std::invalid_argument);
    test1 / 8;
    EXPECT_EQ(test1.getMatrixElement(0, 0), 9);
}

TEST(testMatrixBoolOperators, testNEq)
{
    Matrix test1(2, 2), test2(test1);
    EXPECT_FALSE(test1 != test2);
    test2.setMtrxElement(1, 0, 54);
    EXPECT_TRUE(test1 != test2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
