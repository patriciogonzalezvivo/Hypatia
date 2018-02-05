#include "HorPoint.h"

#include <math.h>

HorPoint::HorPoint() :  m_alt(0.0), m_az(0.0) {
}

HorPoint::HorPoint(const Vector& _parent) {
    m_alt = atan2(_parent.y, _parent.x);
    m_az = atan2(_parent.z, sqrt(_parent.x * _parent.x + _parent.y * _parent.y));
}

HorPoint::HorPoint( double _alt, double _az, bool _radians ) {
     setHorizontalAngles(_alt, _az, _radians);
}

HorPoint::~HorPoint() {
}

void HorPoint::setHorizontalAngles( double _alt, double _az, bool _radians ) {
    if (_radians) {
        m_alt = _alt;
        m_az = _az;
    }
    else {
        m_alt = MathOps::toRadians( _alt );
        m_az = MathOps::toRadians( _az );
    }
}

Vector HorPoint::getHorizontalVector() const {
    const double cosLat = cos(m_az);
    
    Vector v;
    v.x = cos(m_alt) * cosLat;
    v.y = sin(m_alt) * cosLat;
    v.z = sin(m_az);
    
    return v;
}
