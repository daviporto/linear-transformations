#include <matrix.hpp>
#include <limits>
//
// Created by daviaraujo on 26/11/23.
//

Matrix::Matrix() = default;

Matrix::~Matrix() = default;

ostream& operator<<(ostream&os, const Matrix&m) {
    os << m.content[0] << " " << m.content[1] << endl;
    os << m.content[2] << " " << m.content[3] << endl;
    return os;
}

istream& operator>>(istream&is, Matrix&m) {
   is >> m.content[0] >> m.content[1] >> m.content[2] >> m.content[3];
    return is;
}

Matrix operator*(const Matrix&m0, const Matrix&m1) {
    Matrix result;
    result.content[0] = (m0.content[0] * m1.content[0] + m0.content[1] * m1.content[2]) % PRECISION;
    result.content[1] = (m0.content[0] * m1.content[1] + m0.content[1] * m1.content[3]) % PRECISION;
    result.content[2] = (m0.content[2] * m1.content[0] + m0.content[3] * m1.content[2]) % PRECISION;
    result.content[3] = (m0.content[2] * m1.content[1] + m0.content[3] * m1.content[3]) % PRECISION;
    return result;
}

Point::Point(const number x, const number y) {
    this->x = x;
    this->y = y;
}

std::istream& operator>>(istream&is, Point&p) {
    is >> p.x >> p.y;
    return is;
}

Point operator*(const Point&p, const Matrix&m) {
    Point result = Point(0, 0);
    result.x = p.x * m.content[0] + p.y * m.content[1];
    result.y = p.x * m.content[2] + p.y * m.content[3];
    return result;
}

ostream& operator<<(ostream&os, const Point&p) {
    os << p.x % PRECISION << " " << p.y % PRECISION << endl;
    return os;
}
