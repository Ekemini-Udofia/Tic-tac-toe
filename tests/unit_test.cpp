#include <iostream>

#include <gtest/gtest.h>
#include "..//src//core//game.hpp"

TEST(PlayerTest, PlayerId_EQ_0)
{
	player player1;
	EXPECT_EQ(0, player1.player_id);
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
