#include "../classFolder/usualFraction.hpp"
#include <gtest/gtest.h>
#include <stdexcept>


//................FRACTION.............
TEST(testConstructors, testDefaultConstructor)
{
    UsualFraction test;
    EXPECT_EQ(test.getNumerator(), 0);
    EXPECT_EQ(test.getDenominator(), 1);
}

TEST(testConstructors, testParameterConstructor)
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

TEST(testConstructors, testCopyConstructor)
{
    UsualFraction test1(8, -9);
    UsualFraction test2(test1);
    EXPECT_EQ(test2.getNumerator(), -8);
    EXPECT_EQ(test2.getDenominator(), 9);
}

TEST(testGetters, testNumeratorGetter)
{
    UsualFraction test1(-7, 9);
    UsualFraction test2(5, -4);
    EXPECT_EQ(test1.getNumerator(), -7);
    EXPECT_NE(test1.getNumerator(), 7);
    EXPECT_EQ(test2.getNumerator(), -5);
    EXPECT_NE(test2.getNumerator(), 5);
}

TEST(testGetters, testDenominatorGetter)
{
    UsualFraction test1(8, -9);
    UsualFraction test2(-7, 15);
    EXPECT_EQ(test1.getDenominator(), 9);
    EXPECT_NE(test1.getDenominator(), -9);
    EXPECT_EQ(test2.getDenominator(), 15);
    EXPECT_NE(test2.getDenominator(), -15);
}

TEST(testSetters, testNumeratorSetter)
{
    UsualFraction test1(4, 7);
    EXPECT_EQ(test1.getNumerator(), 4);
    test1.setNumerator(8);
    EXPECT_EQ(test1.getNumerator(), 8);
}

TEST(testSetters, testDenominatorSetter)
{
    UsualFraction test1(4, -5);
    EXPECT_EQ(test1.getDenominator(), 5);
    EXPECT_THROW(test1.setDenominator(0), std::invalid_argument);
    test1.setDenominator(-9);
    EXPECT_EQ(test1.getDenominator(), 9);
}

TEST(testClassMethod, testSimplifyMethod)
{
    UsualFraction test1(24, 15);
    UsualFraction test2(8, 5);
    EXPECT_NE(test1.getNumerator(), test2.getNumerator());
    EXPECT_NE(test1.getDenominator(), test2.getDenominator());
    test1 = test1.simplifyFraction();
    EXPECT_EQ(test1.getNumerator(), test2.getNumerator());
    EXPECT_EQ(test1.getDenominator(), test2.getDenominator());
}

TEST(testOperators, testOperatorPlus)
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

TEST(testOperators, testOperatorMinus)
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

TEST(testOperators, testOperatorMultiply)
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

TEST(testOperators, testOperatorDivide)
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

TEST(testOperators, testPrefixIncrement)
{
    UsualFraction test1(5, 7);
    UsualFraction test2(12, 7);
    EXPECT_NE(test1.getNumerator(), test2.getNumerator());
    EXPECT_EQ((++test1).getNumerator(), test2.getNumerator());
}

TEST(testOperators, testPrefixDecrement)
{
    UsualFraction test1(24, 5);
    UsualFraction test2(19, 5);
    EXPECT_NE(test1.getNumerator(), test2.getNumerator());
    EXPECT_EQ((--test1).getNumerator(), test2.getNumerator());
}

TEST(testOperators, testPostfixIncrement)
{
    UsualFraction test1(5, 7);
    UsualFraction test2(12, 7);
    EXPECT_NE((test1++).getNumerator(), test2.getNumerator());
    EXPECT_EQ(test1.getNumerator(), test2.getNumerator());
}

TEST(testOperators, testPostfixDecrement)
{
    UsualFraction test1(24, 5);
    UsualFraction test2(19, 5);
    EXPECT_NE(test1--.getNumerator(), test2.getNumerator());
    EXPECT_EQ(test1.getNumerator(), test2.getNumerator());
}

TEST(testUnaryOperators, testUnaryMinus)
{
    UsualFraction test1(7, -8);
    EXPECT_EQ(-test1.getNumerator(), 7);
    UsualFraction test2(-5, 6);
    EXPECT_NE(-test2.getNumerator(), -5);
    EXPECT_EQ(-test2.getNumerator(), 5);
}

TEST(testUnaryOperators, testInverseFraction)
{
    UsualFraction test1(6, 7);
    UsualFraction test2(7, 6);
    EXPECT_EQ((!test1).getNumerator(), test2.getNumerator());
    EXPECT_EQ((!test1).getDenominator(), test2.getDenominator());
    UsualFraction badFraction;
    EXPECT_THROW((!badFraction), std::invalid_argument);
}

TEST(testBoolOperators, testOperatorNEq)
{
    UsualFraction test1(5, 7);
    UsualFraction test2(test1);
    UsualFraction test3(-21, 15);
    EXPECT_FALSE(test1 != test2);
    EXPECT_TRUE(test1 != test3);
    EXPECT_TRUE(test2 != test3);
}

TEST(testBoolOperators, testOperatorLess)
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

TEST(testOperators, testPlusEq)
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

TEST(testOperators, testMinusEq)
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

TEST(testOperators, testMultiplyEq)
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

TEST(testOperators, testDivideEq)
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

TEST(testOperators, testEq)
{
    UsualFraction test1;
    UsualFraction test2(6, -13);
    test1 = test2;
    EXPECT_EQ(test1.getNumerator(), -6);
    EXPECT_EQ(test1.getDenominator(), 13);
}