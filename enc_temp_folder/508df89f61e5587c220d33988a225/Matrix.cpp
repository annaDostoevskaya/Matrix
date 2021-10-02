﻿// For using std lib in C Run Time.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

class Matrix
{
private:
    int** Item = nullptr;
    int Rows, Colums;
    void loadMatrixSize(FILE *fp);
    int loadMatrixElement(FILE *fp);
    void itemMemAllocate()
    {
        Item = new int*[Rows];
        for (int i = 0; i < Rows; i++)
            Item[i] = new int[Colums];
    };
public:
    Matrix() : Rows(0), Colums(0), Item(NULL) {};
    Matrix(int r, int c);
    ~Matrix();
    int getElement(int r, int c);
    void setElement(int r, int c, int arg);
    /* 
    When we extented Matrix to delate Rows or Colums,
    we can use it.
    */
    void setRows(int r) { Rows = r; };
    void setColums(int c) { Colums = c; };
    int getRows() { return Rows; };
    int getColums() { return Colums; };
    void loadMatrix(FILE* fp);
    void saveMatrix(FILE* fp);
    void displayMatrix();
};

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

int Matrix::getElement(int r, int c)
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

void Matrix::loadMatrix(FILE *fp)
{
    loadMatrixSize(fp);
    itemMemAllocate();
    for (int i = 0; i < Rows; i++)
        for (int j = 0; j < Colums; j++)
            Item[i][j] = loadMatrixElement(fp);
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

void Matrix::saveMatrix(FILE* fp)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colums; j++)
            fprintf(fp, "%d ", Item[i][j]);
        putc('\n', fp);
    }
}

void Matrix::displayMatrix()
{
    saveMatrix(stdout);
}

int main()
{

    Matrix *m = new Matrix(5, 5);

    delete m;

    return 0;
}