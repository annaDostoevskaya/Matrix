#pragma once

// For using std lib in C Run Time.
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
    void setRows(int r) { Rows = r; };
    void setColums(int c) { Colums = c; };
public:
    Matrix() : Rows(0), Colums(0), Item(NULL) {};
    Matrix(int r, int c);
    ~Matrix();
    int getElement(int r, int c) const;
    void setElement(int r, int c, int arg);
    int getRows() const { return Rows; };
    int getColums() const { return Colums; };
    int saveMatrix(FILE* fp) const;
    void displayMatrix() const;
    int loadMatrix(FILE* fp);
    void deleteRow(int index);
    //TODO(annad): operator[]() {}
};

namespace Utils
{
    int getIndexRowMinimumValueFromRange(const Matrix& m, int r1, int r2, int c1, int c2);
    void getArrayFromMatrixRange(const Matrix& m, int* array,
        int r1, int r2, int c1, int c2);
    int cmpfunc(const int* a, const int* b);
}