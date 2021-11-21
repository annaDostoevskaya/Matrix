#include "pch.h"
#include "../Matrix.cpp"
#include <stdio.h>

class MatrixTest : public ::testing::Test { };

TEST_F(MatrixTest, CheckMatrixSetGetElement)
{
	Matrix m = Matrix(5, 5);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			m.setElement(i, j, 10);
		}
	}

	EXPECT_EQ(m.getElement(0, 0), 10);
}


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}