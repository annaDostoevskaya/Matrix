#include "Matrix.h"

using namespace Utils;

int main()
{
    /*
    // Task 2:
    Matrix* m = new Matrix;
    FILE* fp = fopen("TEST.mtrx", "r");
    m->loadMatrix(fp);
    m->displayMatrix();
    int i = getIndexRowMinimumValueFromRange(*m, 1, 4, 1, 4);
    m->deleteRow(i);
    m->displayMatrix();
    fclose(fp);
    delete m;
    */

    /*
    // Task 3:
    Matrix* m = new Matrix();
    FILE* fp = fopen("TEST.mtrx", "r");
    m->loadMatrix(fp);
    m->displayMatrix();
    int size = (3 - 1) * (4 - 1);
    int* a = new int[size];
    printf("%d\n", size);
    getArrayFromMatrixRange(*m, a, 1, 3, 1, 4);
    qsort(a, size, sizeof(int), (int(*) (const void*, const void*)) cmpfunc);
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
    */

    return 0;
}