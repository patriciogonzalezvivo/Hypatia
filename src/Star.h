#pragma once

#include "EqPoint.h"

class Star : public EqPoint {
public:

    static const int TOTAL;

    Star();
    Star( int _id );
    Star( double _ra, double _dec, double _mag );

    virtual int getId() const { return m_id; };
    virtual double getMagnitud() const { return m_mag; };
    
    virtual std::string getString() const;

protected:
    double m_mag;
    int m_id;
};
