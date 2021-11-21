#include "Matrix.h"


Matrix::Matrix(int r, int c) : Rows(r), Colums(c)
{
    itemMemAllocate();
}

Matrix::~Matrix()
{
    for (int i = 0; i < Rows; i++)
        delete[] Item[i];
    delete[] Item;
}

int Matrix::getElement(int r, int c) const
{
    /*
    well, in reality we can build class Item, and then
    overload operator[], and then we can make as:
    Matrix[x][y];
    but i'm so lazy...
    */
    return Item[r][c];
}

void Matrix::setElement(int r, int c, int arg)
{
    Item[r][c] = arg;
}

void Matrix::loadMatrix(FILE* fp)
{
    loadMatrixSize(fp);
    itemMemAllocate();
    for (int i = 0; i < Rows; i++)
        for (int j = 0; j < Colums; j++)
            Item[i][j] = loadMatrixElement(fp);
}

void Matrix::loadMatrixSize(FILE* fp)
{
    char c;
    int row = 1;
    int col = 0;
    while ((c = fgetc(fp)) != '\n')
        if (c == ' ')
            col++;
    while ((c = fgetc(fp)) != EOF)
        if (c == '\n')
            row++;
    setRows(row);
    setColums(col);
    rewind(fp);
}

int Matrix::loadMatrixElement(FILE* fp)
{
#define BUFFER_SIZE 8
    /*
    This method must be work just for elements with 8 digits.
    If you are want work with numbers over million, you must rewrite
    realization this method.
    */

    char c;
    int size_number = 0;
    char buffer[BUFFER_SIZE];
    while ((c = fgetc(fp)) != ' ')
    {
        buffer[size_number] = c;
        size_number++;
    }
    buffer[size_number] = '\0';
    return atoi(buffer);
}


void Matrix::saveMatrix(FILE* fp) const
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colums; j++)
            fprintf(fp, "%d ", Item[i][j]);
        putc('\n', fp);
    }
}

void Matrix::deleteRow(int index)
{
    delete[] Item[index];
    for (int i = index; i < (Rows - 1); i++)
        Item[i] = Item[i + 1];
    setRows(Rows - 1);
}

void Matrix::displayMatrix() const
{
    saveMatrix(stdout);
    putc('\n', stdout);
}

namespace Utils
{

    int getIndexRowMinimumValueFromRange(const Matrix& m, int r1, int r2, int c1, int c2)
    {
        int imin = r1;
        int min = m.getElement(r1, c1);
        for (int i = r1; i < r2; i++)
        {
            for (int j = c1; j < c2; j++)
            {
                if (min > m.getElement(i, j))
                {
                    min = m.getElement(i, j);
                    imin = i;
                }
            }
        }
        return imin;
    }

    void getArrayFromMatrixRange(const Matrix& m, int* array,
        int r1, int r2, int c1, int c2)
    {
        int idx_a = 0;
        for (int i = r1; i < r2; i++)
        {
            for (int j = c1; j < c2; j++)
            {
                array[idx_a] = m.getElement(i, j);
                idx_a++;
            }
            printf("\n");
        }
    }

    int cmpfunc(const int* a, const int* b)
    {
        return *a - *b;
    }
}