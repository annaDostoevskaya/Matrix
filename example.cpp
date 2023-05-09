/*
Author: github.com/annadostoevskaya
File: main.cpp
Date: 09/05/23 18:11:30

Description: <empty>
*/

#include <Matrix.hpp>
#include <iostream>
#include <vector>

int main()
{
    Matrix<int> m(3, 3);
    Matrix<int>::Iter iter(m);
    int i = 0;
    while (iter.more())
    {
        i++;
        iter.next() = i;
    }

    std::cout << "1) Create and display matrix:\n"<< m << '\n';
    std::cout << "3) Add matrix m + m:\n" << m + m << '\n';
    std::cout << "4) Multiplication matrices m*m:\n" << m * m << '\n';

    iter.reset();
    std::cout << "2) Transpose matrix by iterator:\n";
    while (iter.more())
    {
        std::cout << iter.tnext() << ' ';
        if (iter.current() % m.getHeight() == 0) std::cout << '\n';
    } std::cout << '\n';
#if 0
    Matrix<int> m(5, 5);
    for (int hi = 0; hi < m.getHeight(); hi++)
    {
        for (int wi = 0; wi < m.getWidth(); wi++)
        {
            m[hi][wi] = hi * wi;
        }
    }

    Matrix<int> m1(3, 3);
    for (int hi = 0; hi < m1.getHeight(); hi++)
    {
        for (int wi = 0; wi < m1.getWidth(); wi++)
        {
            m1[hi][wi] = wi;
        }
    }

    Matrix<int> m2(m);
    std::cout << m2;
    Matrix<int> madd = m2 + m2;
    std::cout << madd;
    Matrix<int> msub = madd - m2;
    msub[0][2] = 42;
    std::cout << msub;
    std::cout << "Transposed Matrix:\n";
    Matrix<int>::Iter iter(msub);
    while (iter.more())
    {
        std::cout << iter.tnext() << ' ';
        if (iter.current() % msub.getHeight() == 0) std::cout << '\n';
    }

    std::cout << '\n' << madd;
    Matrix<int>::Iter iter2(madd);
    while (iter2.more())
    {
        std::cout << iter2.tnext() << ' ';
        if (iter2.current() % madd.getHeight() == 0) std::cout << '\n';
    }

    std::cout << "\nmultiplication\n";
    std::cout << madd << '\n' << msub << '\n';
    Matrix<int> mmul = madd * msub;
    std::cout << mmul;

    return 0;
#endif
}
