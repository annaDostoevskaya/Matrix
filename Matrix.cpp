#include <stdio.h>

class Matrix
{
private:
    int** Item;
    int Rows, Colums;
public:
    Matrix(int r, int c) : Rows(r), Colums(c)
    {
        Item = new int*[Rows];
        for (int i = 0; i < Rows; i++)
            Item[i] = new int[Colums];
        Item[0][0] = 5;
        printf("%d\n", Item[0][0]);
    }
    ~Matrix()
    {
        for (int i = 0; i < Rows; i++)
            delete[] Item[i];
        delete[] Item;
    }


};

int main()
{
    Matrix m(5, 4);
    return 0;
}