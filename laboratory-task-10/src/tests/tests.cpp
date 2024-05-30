#include <stdexcept>
#include <gtest/gtest.h>

#include "../functions/functions.hpp"

TEST(TestCheckFile, BadFile) {
	std::ifstream firstBad("NonExisten.txt");
	std::ifstream secondBad("src/info/unopened.txt");
	std::ifstream thirdBad("src/info/empty.txt");
	EXPECT_THROW(checkFile(firstBad), std::ios_base::failure);
	EXPECT_THROW(checkFile(secondBad), std::ios_base::failure);
	EXPECT_THROW(checkFile(thirdBad), std::ios_base::failure);
}

TEST(TestCheckFile, GoodFile) {
	std::ifstream firstGoodFile("src/info/numbers.txt");
	std::ifstream secondGoodFile("src/info/strings.txt");
	EXPECT_NO_THROW(checkFile(firstGoodFile));
	EXPECT_NO_THROW(checkFile(secondGoodFile));
}

TEST(TestCheckPathToFile, WrongPathToFile) {
	std::string firstWrongPath = "TryFind.txt";
	std::string secondWrongPath = "NonExistenFile.txt";
	EXPECT_THROW(getMainText(firstWrongPath), std::ios_base::failure);
	EXPECT_THROW(getMainText(secondWrongPath), std::ios_base::failure);
}

TEST(TestCheckPathToFile, GoodPathToFile) {
	std::string firstGoodPath = "src/info/numbers.txt";
	std::string secondGoodPath = "src/info/strings.txt";
	EXPECT_NO_THROW(getMainText(firstGoodPath));
	EXPECT_NO_THROW(getMainText(secondGoodPath));
}

TEST(TestCheckIsDigit, NotDigit) {
	std::string firstNotDigit = "-RETf";
	std::string secondNotDigit = "%$";
	EXPECT_EQ(isDigit(firstNotDigit), false);
	EXPECT_EQ(isDigit(secondNotDigit), false);
}

TEST(TestCheckIsDigit, IsDigit) {
	std::string firstDigit = "654";
	std::string secondDigit = "0";
	std::string thirdDigit = "-543";
	EXPECT_EQ(isDigit(firstDigit), true);
	EXPECT_EQ(isDigit(secondDigit), true);
	EXPECT_EQ(isDigit(thirdDigit), true);
}

TEST(TestCheckGettingDelimiters, NoDelimiters) {
	std::string firstBadDelims = "src/info/badDelims.txt";
	std::string secondBadDelims = "src/info/empty.txt";
	EXPECT_THROW(getDelimiters(firstBadDelims), std::ios_base::failure);
	EXPECT_THROW(getDelimiters(secondBadDelims), std::ios_base::failure);
}

TEST(TestCheckGettingDelimiters, FileHasDelimiters) {
	std::string firstGoodDelims = "src/info/numbers.txt";
	std::string secondGoodDelims = "src/info/strings.txt";
	EXPECT_NO_THROW(getDelimiters(firstGoodDelims));
	EXPECT_NO_THROW(getDelimiters(secondGoodDelims));
}

TEST(TestCheckSurname, NotSurname) {
	std::string firstNotSurname = "ber";
	std::string secondNotSurname = "TTTTTTTTT";
	std::string thirdNotSurname = "534";
	std::string fourthNotSurname = "D6";
	EXPECT_EQ(isWord(firstNotSurname), false);
	EXPECT_EQ(isWord(secondNotSurname), false);
	EXPECT_EQ(isWord(thirdNotSurname), false);
	EXPECT_EQ(isWord(fourthNotSurname), false);
}

TEST(TestCheckSurname, IsSurname) {
	std::string firstSurname = "Azov";
	std::string secondSurname = "Yoh";
	EXPECT_EQ(isWord(firstSurname), true);
	EXPECT_EQ(isWord(secondSurname), true);
}

TEST(TestCheckSizeNumbers, WrongSize) {
	std::string firstBadSize = "434353 343434";
	std::string delims = "<>?";
	EXPECT_NE(getSizeForArrNumbers(firstBadSize, delims), 2);
	std::string secondBadSize = "GEr?DSDc";
	EXPECT_NE(getSizeForArrNumbers(secondBadSize, delims), 2);
}

TEST(TestCheckSizeNumbers, GoodSize) {
	std::string delims = " -^&*(";
	std::string firstGood = "5 7 3 2";
	EXPECT_EQ(getSizeForArrNumbers(firstGood, delims), 4);
	std::string secondGood = "-43 56 -6 0 -52";
	EXPECT_EQ(getSizeForArrNumbers(secondGood, delims), 5);
}

TEST(TestCheckSizeSurnames, WrongSize) {
	std::string firstBadSize = "DDDDD F434???dcddsd";
	std::string delims = "<   >?";
	EXPECT_NE(getSizeForArrSurenames(firstBadSize, delims), 3);
	std::string secondBadSize = "4343   UUUU<<<>>>D32  vRRR";
	EXPECT_NE(getSizeForArrSurenames(secondBadSize, delims), 4);
}

TEST(TestCheckSizeSurnames, GoodSize) {
	std::string delims = " -^&*(";
	std::string firstGood = "Der  Ferc&&&Ger&&&&bbbb";
	EXPECT_EQ(getSizeForArrSurenames(firstGood, delims), 3);
	std::string secondGood = "-Tboi  Red VVVVV((((545";
	EXPECT_EQ(getSizeForArrSurenames(secondGood, delims), 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}