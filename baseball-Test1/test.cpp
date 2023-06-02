#include "pch.h"
#include "../baseball/baseball.cpp"

using namespace std;

TEST(BaseballGame, TestName)
{
	Baseball baseball("123");	

	EXPECT_THROW(baseball.guess(""), invalid_argument);
	EXPECT_THROW(baseball.guess("1543"), invalid_argument);
	EXPECT_THROW(baseball.guess("1v3"), invalid_argument);
	EXPECT_THROW(baseball.guess("121"), invalid_argument);
}

TEST(BaseballGame, PerfectMatch)
{
	Baseball baseball("123");
	Result result = baseball.guess("123");

	EXPECT_EQ(true, result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST(BaseballGame, MisMatch)
{
	Baseball baseball("123");
	Result result = baseball.guess("789");

	EXPECT_EQ(false, result.solved);
	EXPECT_EQ(0, result.strikes);
	EXPECT_EQ(0, result.balls);
}

