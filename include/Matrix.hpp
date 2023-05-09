/*
Author: github.com/annadostoevskaya
File: Matrix.h
Date: 09/05/23 18:33:16

Description: <empty>
*/

#pragma once
#include <iostream>
#include <iterator>
#include <cassert>

template <typename T>
class Matrix
{
private:
    T *items;
    int w, h;

public:
    class Row;
    class Iter;

    Matrix() : items(nullptr), w(0), h(0) {}
    Matrix(int _w, int _h) : w(_w), h(_h), items(new T[w*h]) {}
    ~Matrix() { delete[] items; }
    T& get(int i) const { return items[i]; }
    inline int getSize() const { return w*h; }
    inline int getWidth() const { return w; }
    inline int getHeight() const { return h; }
    Row operator[](int hidx)
    {
        assert(hidx*w < h*w && "Error: Out of range");
        return Row(&items[hidx*w], w);
    }

    Matrix(const Matrix<T>& other);
    Matrix<T>& operator=(const Matrix<T>& other);
    Matrix<T>& operator+=(const Matrix<T>& other);
    Matrix<T>& operator-=(const Matrix<T>& other);

    friend Matrix<T> operator+(Matrix<T> lhs, const Matrix<T>& rhs) { return lhs += rhs; }
    friend Matrix<T> operator-(Matrix<T> lhs, const Matrix<T>& rhs) { return lhs -= rhs; }
    friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& rhs) 
    {
        Matrix<T>::Iter iter(rhs);
        while (iter.more())
        {
            os << iter.next() << ' ';
            if (iter.current() % rhs.w == 0) os << '\n';
        }

        return os;
    }

    friend Matrix<T> operator*(const Matrix<T>& lhs, const Matrix<T>& rhs)
    {
        Matrix<T> result(rhs.h, lhs.w);
        if (lhs.w == rhs.h)
        {
            for(int y = 0; y < lhs.h; y++)
            {
                for(int x = 0; x < rhs.w; x++)
                {
                    result.items[y * rhs.w + x] = 0;
                    for(int i = 0; i < lhs.w; i++)
                        result.items[y * rhs.w + x] += lhs.items[y * lhs.w + i] * rhs.items[i * rhs.w + x];
                }
            }
        }

        return result;
    }
};

template <typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& other)
{
    Iter src(other); 
    Iter dst(*this);
    while (src.more() && dst.more())
        dst.next() += src.next();

    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& other)
{
    Iter src(other); 
    Iter dst(*this);
    while (src.more() && dst.more())
        dst.next() -= src.next();

    return *this;
}


template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other)
{
    if (this == &other) return *this;
    delete[] items;
    
    w = other.w;
    h = other.h;
    items = new T[w*h];
    Iter src(other); 
    Iter dst(*this);
    while (src.more() && dst.more())
        dst.next() = src.next();

    return *this;
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& other) : w(other.w), h(other.h), items(new T[w*h])
{
    Iter src(other); 
    Iter dst(*this);
    while (src.more() && dst.more())
        dst.next() = src.next();
}

template <typename T>
class Matrix<T>::Row
{
private:
    T *items;
    int size;
public:
    Row(T *_items, int _size) : items(_items), size(_size) {}
    ~Row() {}
    T& operator[](int widx) 
    {
        assert(widx < size && "Error: Out of range");
        return items[widx];
    }
};

template <typename T>
class Matrix<T>::Iter
{
private:
    const Matrix<T>& m;
    int i;
public:
    Iter(const Matrix<T>& _m) : m(_m), i(0) {}
    ~Iter() {}
    inline int current() { return i; }
    bool more() { return i < m.w * m.h; }
    T& next() { return m.get(i++); }
    T& tnext() 
    {
        // TODO(annad): Refactoring mb?..
        int x = (i+1) % m.w - 1;
        if (x == -1) x = m.w - 1;
        int y = i / m.w;
        if (y == m.h) y = m.h - 1;
        i++;
        int index = x * m.w + y;
        assert(index < m.getSize() && "Error: Out of range");
        return m.get(index); 
    }
    
    inline void reset() { i = 0; }
};

