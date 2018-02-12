#include "Vector.h"

#include "../MathOps.h"
#include <math.h>

Vector::Vector() : x(0.0), y(0.0), z(0.0) {
}

Vector::Vector(const Polar& _polar) {
    const double cosLat = cos( _polar[1] );
    x = cos( _polar[0] ) * cosLat;
    y = sin( _polar[0] ) * cosLat;
    z = sin( _polar[1] );
}

Vector::Vector(const double _x, const double _y, const double _z): x(_x), y(_y), z(_z) {
}

Vector::~Vector() {
}

Vector Vector::getNormalized() const {
    double length = getMagnitud();
    if ( length > 0 ) {
        return Vector( x/length, y/length, z/length );
    } 
    else {
        return Vector();
    }
}

double Vector::getMagnitud() const {
    return sqrt(x*x + y*y + z*z);
}

double Vector::getLongitude(ANGLE_TYPE _type) const {
    double lng = atan2(y, x);
    if ( _type == DEGS ) {
        return MathOps::toDegrees( lng );
    }
    else {
        return lng;
    }
    
};
double Vector::getLatitude(ANGLE_TYPE _type) const {
//    double lat = asin(z);
    double lat = atan2(z, sqrt(x * x + y * y));
    if ( _type == DEGS ) {
        return MathOps::toDegrees( lat );
    }
    else {
        return lat;
    }
};

double Vector::dot(const Vector& _vec) const {
    return (x * _vec.x) + (y * _vec.y) + (z * _vec.z);
}

Vector& Vector::normalize() {
    double length = getMagnitud();
    if ( length > 0 ) {
        x /= length;
        y /= length;
        z /= length;
    }
    return *this;
}

Vector& Vector::rotate ( double _angle, int _axis, bool _radians ) {
    if (!_radians) {
        _angle = MathOps::toRadians(_angle);
    }
    const double sinAng = sin( _angle );
    const double cosAng = cos( _angle );
    const int a = (_axis + 1) % 3;
    const int b = (_axis + 2) % 3;
    
    double temp = getPtr()[a] * cosAng - getPtr()[b] * sinAng;
    getPtr()[b] = getPtr()[b] * cosAng + getPtr()[a] * sinAng;
    getPtr()[a] = temp;
    
    return *this;
}

Vector& Vector::rotate ( double _lng, double _lat, bool _radians ) {
    if (!_radians) {
        _lng = MathOps::toRadians(_lng);
        _lat = MathOps::toRadians(_lat);
    }

    double cosLng = cos(_lng);
    double sinLng = sin(_lng);
    double cosLat = cos(_lat);
    double sinLat = sin(_lat);

    double x_tmp = cosLat * cosLng * x + sinLng * y + sinLat * cosLng * z;
    double y_tmp = -cosLat * sinLng * x + cosLng * y - sinLat * sinLng * z;
    z = -sinLat * x + cosLat * z;
    y = y_tmp;
    x = x_tmp;
    
    return *this;
}

Vector& Vector::rotate(double _angle, const Vector& _axis, bool _radians ) {
    if (!_radians) {
        _angle = MathOps::toRadians(_angle);
    }

    Vector ax = _axis.getNormalized();

    double sina = sin( _angle );
    double cosa = cos( _angle );
    double cosb = 1.0f - cosa;
    
    x = x * (ax.x*ax.x*cosb + cosa)
        + y * (ax.x*ax.y*cosb - ax.z*sina)
        + z * (ax.x*ax.z*cosb + ax.y*sina);

    y = x * (ax.y*ax.x*cosb + ax.z*sina)
        + y * (ax.y*ax.y*cosb + cosa)
        + z * (ax.y*ax.z*cosb - ax.x*sina);

    z = x * (ax.z*ax.x*cosb - ax.y*sina)
        + y * (ax.z*ax.y*cosb + ax.x*sina)
        + z * (ax.z*ax.z*cosb + cosa);
    
    return *this;
}

double * Vector::getPtr() {
    return (double*)&x;
}
const double * Vector::getPtr() const {
    return (const double *)&x;
}

double& Vector::operator[]( int _n ){
    return getPtr()[_n];
}

double Vector::operator[]( int _n ) const {
    return getPtr()[_n];
}

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
