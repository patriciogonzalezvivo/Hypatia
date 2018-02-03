/*****************************************************************************\
 * ObsInf
 *
 * author: mark huss (mark@mhuss.com)
 * Based on Bill Gray's open-source code at projectpluto.com
 *
 \*****************************************************************************/

#pragma once

#include "GeoPoint.h"

// * * * * * Observer's Location Info * * * * *
class Observer {
public:
    // c'tor: lon & lat are passed in DEGREES
    Observer();
    Observer(const GeoPoint& _location, unsigned long _sec = 0);
    Observer(double _lng_deg, double _lat_deg, unsigned long _sec = 0);
    virtual ~Observer();
    
    void    setLocation(const GeoPoint& _location);
    
    void    setTime(unsigned long _sec = 0);
    void    setJuliaDay(double _jd);
    
    GeoPoint getLocation() const { return m_location; };
    
    unsigned long  getTime();
    double  getJulianDate();
    double  getJulianCentury();
    double  getObliquity();
    double  getLST();
    
    Vector  getHeliocentricVector();
    
    void    update();
    
private:
    Vector      m_heliocentricLoc;
    GeoPoint    m_location;
    
    unsigned long m_sec;
    double m_jd;
    double m_jcentury;
    double m_obliquity;
    double m_lst;
    
    bool m_change;
};
