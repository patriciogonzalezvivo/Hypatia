#include "Vector.h"

#include "MathOps.h"
#include <math.h>

Vector::Vector() : x(0.0), y(0.0), z(0.0) {
}

//Vector::Vector( const Vector& _parent) {
//    x = _parent.x;
//    y = _parent.y;
//    z = _parent.z;
////    w = _parent.w;
//}

Vector::~Vector() {
}

//Vector& Vector::operator=(const Vector& _parent) {
//    if (this != & _parent){
//        x = _parent.x;
//        y = _parent.y;
//        z = _parent.z;
////        w = _parent.w;
//    }
//    return *this;
//}

Vector Vector::operator+ (const Vector& _vec) const {
    Vector rta;
    rta.x = x + _vec.x;
    rta.y = y + _vec.y;
    rta.z = z + _vec.z;
    return rta;
}

Vector Vector::operator- (const Vector& _vec) const {
    Vector rta;
    rta.x = x - _vec.x;
    rta.y = y - _vec.y;
    rta.z = z - _vec.z;
    return rta;
}

Vector Vector::operator* (const Vector& _vec) const {
    Vector rta;
    rta.x = x * _vec.x;
    rta.y = y * _vec.y;
    rta.z = z * _vec.z;
    return rta;
}

Vector Vector::operator/ (const Vector& _vec) const {
    Vector rta;
    rta.x = x / _vec.x;
    rta.y = y / _vec.y;
    rta.z = z / _vec.z;
    return rta;
}

Vector Vector::operator+ (double _d) const {
    Vector rta;
    rta.x = x + _d;
    rta.y = y + _d;
    rta.z = z + _d;
    return rta;
}

Vector Vector::operator- (double _d) const {
    Vector rta;
    rta.x = x - _d;
    rta.y = y - _d;
    rta.z = z - _d;
    return rta;
}

Vector Vector::operator* (double _d) const {
    Vector rta;
    rta.x = x * _d;
    rta.y = y * _d;
    rta.z = z * _d;
    return rta;
}

Vector Vector::operator/ (double _d) const {
    Vector rta;
    rta.x = x / _d;
    rta.y = y / _d;
    rta.z = z / _d;
    return rta;
}

Vector& Vector::operator+= (const Vector& _vec) {
    x += _vec.x;
    y += _vec.y;
    z += _vec.z;
    return *this;
}

Vector& Vector::operator-= (const Vector& _vec) {
    x -= _vec.x;
    y -= _vec.y;
    z -= _vec.z;
    return *this;
}

Vector& Vector::operator*= (const Vector& _vec) {
    x *= _vec.x;
    y *= _vec.y;
    z *= _vec.z;
    return *this;
}

Vector& Vector::operator/= (const Vector& _vec) {
    x /= _vec.x;
    y /= _vec.y;
    z /= _vec.z;
    return *this;
}

Vector& Vector::operator+= (double _d) {
    x += _d;
    y += _d;
    z += _d;
    return *this;
}
Vector& Vector::operator-= (double _d) {
    x -= _d;
    y -= _d;
    z -= _d;
    return *this;
}

Vector& Vector::operator*= (double _d) {
    x *= _d;
    y *= _d;
    z *= _d;
    return *this;
}

Vector& Vector::operator/= (double _d) {
    x /= _d;
    y /= _d;
    z /= _d;
    return *this;
}

double Vector::dot(const Vector& _vec) const {
    return (x * _vec.x) +
    (y * _vec.y) +
    (z * _vec.z);
}

double Vector::magnitud() const {
    return sqrt(x*x + y*y + z*z);
}
