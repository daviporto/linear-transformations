//
// Created by daviaraujo on 26/11/23.
//

#ifndef MATRIX_HPP
#define MATRIX_HPP

#define number unsigned int

#define PRECISION 100000000

#include <iostream>
using namespace std;

class Point {
public:
    number x, y;

    Point(number x, number y);

    ~Point() = default;

    friend std::istream& operator>>(istream&is, Point&p);
    friend ostream& operator<<(ostream&os, const Point&p);
};


class Matrix {
public:
    number content[4] = {1, 0, 0, 1} ;

    Matrix();

    ~Matrix();

    friend ostream& operator<<(ostream&os, const Matrix&m);

    friend istream& operator>>(istream&is, Matrix&m);

    friend Matrix operator*(const Matrix&m0, const Matrix&m1);

    friend Point  operator*(const Point&p, const Matrix&m);
    friend Point  operator*(const Point&p, const Matrix&m);
};


#endif //MATRIX_HPP
