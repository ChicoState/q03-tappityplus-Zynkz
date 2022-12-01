/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"

class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){}
		virtual ~tappityTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(tipityTest, LengthDifferenceNoInputOrReference){
  tappity test = tappity("");
  int result = test.length_difference();
  ASSERT_EQ(result, 0);
}

TEST(tipityTest, LengthDifferenceNoInput){
  tappity test = tappity("Love");
  int result = test.length_difference();
  ASSERT_EQ(result, 4);
}

TEST(tipityTest, LengthDifferenceLongConstructor){
  tappity test = tappity("Death");
  test.entry("love");
  int result = test.length_difference();
  ASSERT_EQ(result, 1);
}

TEST(tipityTest, LengthDifferenceLongInput){
  tappity test = tappity("Love");
  test.entry("Death");
  int result = test.length_difference();
  ASSERT_EQ(result, 1);
}

TEST(tipityTest, LengthDifferenceSame){
  tappity test = tappity("Love");
  test.entry("Love");
  int result = test.length_difference();
  ASSERT_EQ(result, 0);
}

TEST(tipityTest, AccuracyNoReference){
  tappity test = tappity("");
  test.entry("Death");
  double result = test.accuracy();
  ASSERT_EQ(result, 0);
}

TEST(tipityTest, AccuracyNoInput){
  tappity test = tappity("Love");
  test.entry("");
  double result = test.accuracy();
  ASSERT_EQ(result, 0);
}

TEST(tipityTest, AccuracyOffset){
  tappity test = tappity("The worst is on it's way");
  test.entry(" The worst is on it's way");
  double result = test.accuracy();
  ASSERT_EQ(result, 0);
}
TEST(tipityTest, AccuracyCorrect){
  tappity test = tappity("The worst is on it's way");
  test.entry("The worst is on it's way");
  double result = test.accuracy();
  ASSERT_EQ(result, 100);
}

TEST(tipityTest, AccuracyCorrectSymbols){
  tappity test = tappity("*^&%)()@(><~`=-+_{}'""\"[]''><'`)");
  test.entry("*^&%)()@(><~`=-+_{}'""\"[]''><'`)");
  double result = test.accuracy();
  ASSERT_EQ(result, 100);
}

TEST(tipityTest, AccuracyCorrectSpaces){
  tappity test = tappity("                ");
  test.entry("                ");
  double result = test.accuracy();
  ASSERT_EQ(result, 100);
}

TEST(tipityTest, AccuracyLongReference){
  tappity test = tappity("This is a test!");
  test.entry("This is a");
  double result = test.accuracy();
  ASSERT_EQ(result, 60);
}

TEST(tipityTest, AccuracyLongInput){
  tappity test = tappity("This is a");
  test.entry("This is a test!");
  int result = test.accuracy();
  ASSERT_EQ(result, 60);
}

TEST(tipityTest, AccuracyDecimals){
  tappity test = tappity("Thi");
  test.entry("This is ");
  double result = test.accuracy();
  ASSERT_EQ(result, 37.5);
}

TEST(tipityTest, AccuracyDecimalsRepeating){
  tappity test = tappity("T");
  test.entry("Thi");
  double result = test.accuracy();
  double expected = 1;
  expected = expected/3*100;
  ASSERT_EQ(result, expected);
}
