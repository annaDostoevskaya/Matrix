// For using std lib in C Run Time.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


#include <stdio.h>

class Matrix
{
private:
    int** Item;
    int Rows, Colums;
    void loadMatrixSize(FILE *fp);
    void setRows(int r);
    void setColums(int c);
    void itemMemAllocate();
public:
    Matrix(void) {};
    Matrix(int r, int c);
    ~Matrix();
    int getElement(int r, int c);
    void setElement(int r, int c, int arg);
    void loadMatrix(FILE* fp);
};

Matrix::Matrix(int r, int c) : Rows(r), Colums(c)
{
    itemMemAllocate();
}

Matrix::~Matrix()
{
    delete[] Item;
}

int Matrix::getElement(int r, int c)
{
    /* well, in reality we can build class Item, and then 
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

void Matrix::loadMatrix(FILE *fp)
{
    loadMatrixSize(fp);
    itemMemAllocate();

    // TODO: set arguments from .mtrx

    /*
    char c;
    int r, c;
    while ((c = fgetc(fp)) != EOF)
    {

    }*/
}

void Matrix::loadMatrixSize(FILE *fp)
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

void Matrix::itemMemAllocate()
{
    Item = new int* [Rows];
    for (int i = 0; i < Rows; i++)
        Item[i] = new int[Colums];
}

void Matrix::setRows(int r)
{
    Rows = r;
}

void Matrix::setColums(int c)
{
    Colums = c;
}

int main()
{

    Matrix m;
    FILE* fp = fopen("TEST.mtrx", "r");
    m.loadMatrix(fp);
    m.setElement(0, 0, 5);
    printf("%d\n", m.getElement(0, 0));
    /*
    FILE* f = fopen("test.txt", "w");
    char c = 'h';
    fputc(c, f);
    */

    return 0;
}