#pragma once

#include <iomanip>

class Polar {
public:
    Polar();
    Polar(const double _phi, const double _theta, bool _radians = false);
    virtual ~Polar();
    
    virtual double& operator[]( int _n );
    virtual double  operator[]( int _n ) const;
    
private:
    virtual double * getPtr();
    virtual const double * getPtr() const;
    
    double m_phi, m_theta;
};

inline std::ostream& operator<<(std::ostream& strm, const Polar& p) {
    strm << std::setprecision(3);
    strm << "phi: " << std::setw(8) << p[0];
    strm << ", theta: " << std::setw(8) << p[1];
    return strm;
}

