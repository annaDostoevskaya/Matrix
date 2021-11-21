#include "pch.h"
#include "../Matrix.cpp"
#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS

class MatrixTest : public ::testing::Test { };

#define TEST_MTRX "\
15 26 34 4822 53 \n\
2 3 4 -55555 11 \n\
3 4 5 1 22 \n\
4 5 1 -444 34 \n\
5 1 -5288 3 4 \n"

#define TEST_MTRX_W "\
0 5 34 4822 53 \n\
2 3 4 5 11 \n\
3 4 5 1 22 \n\
4 5 1 2 34 \n\
5 1 288 3 4 \n"


TEST_F(MatrixTest, CheckMatrixLoadMatrix)
{
	if (!fopen("./../TEST.mtrx", "r"))
	{
		FILE* fp = fopen("./../TEST.mtrx", "w");
		for (int i = 0; i < 77; i++)
		{
			fputc(TEST_MTRX[i], stdout);
			fputc(TEST_MTRX[i], fp);
		}
		fclose(fp);
	}

	Matrix m = Matrix();
	FILE* fp_mt = fopen("./../TEST.mtrx", "r");
	EXPECT_EQ(m.loadMatrix(fp_mt), 0);
}

TEST_F(MatrixTest, CheckMatrixSetGetElement)
{
	Matrix m = Matrix(5, 5);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			m.setElement(i, j, 10);
	EXPECT_EQ(m.getElement(0, 0), 10);
}


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}