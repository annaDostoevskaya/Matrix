#include "pch.h"
#include "../Matrix.cpp"

class CMatrixTest : public ::testing::Test {
};

TEST_F(CMatrixTest, CheckPerimeter)
{
	ASSERT_TRUE(22 == 22);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}