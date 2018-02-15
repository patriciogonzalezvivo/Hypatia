/*****************************************************************************\
 * ObsInf
 *
 * author: mark huss (mark@mhuss.com)
 * Based on Bill Gray's open-source code at projectpluto.com
 *
 \*****************************************************************************/

#pragma once

#include "TimeOps.h"
#include "coordinates/Geodetic.h"

// * * * * * Observer's Location Info * * * * *
class Observer {
public:
    // c'tor: lon & lat are passed in DEGREES
    Observer();
    Observer(const Geodetic& _location, double _jd = 0);
    Observer(double _lng_deg, double _lat_deg, double _jd = 0);
    virtual ~Observer();
    
    virtual void    setJD(double _jd);
    virtual void    setLocation(const Geodetic& _location);
    
    virtual double  getJD() const { return m_jd; }
    virtual double  getJC() const { return m_jcentury; }
    virtual double  getLST() const { return m_lst; }
    virtual double  getObliquity() const { return m_obliquity; }
    virtual Geodetic getLocation() const { return m_location; }
    
    virtual Vector  getHeliocentricVector();
    
    virtual void    update();

private:
    Vector      m_heliocentricLoc;
    Geodetic    m_location;
    
    double      m_jd;
    double      m_jcentury;
    double      m_obliquity;
    double      m_lst;
    
    bool        m_changed;
};

inline std::ostream& operator<<(std::ostream& strm, const Observer& o) {
    strm << "Observer, " << o.getLocation();
    strm << ", jd:" << std::setw(8) << o.getJD();
    strm << ", time:" << std::setw(8) << TimeOps::formatDateTime(o.getJD(), Y_M_D_HM);
    strm << ", obliq:" << std::setw(8) << MathOps::formatAngle(o.getObliquity(), RADS, Dd);
    strm << ", lst:" << std::setw(8) << MathOps::formatAngle(o.getLST(), DEGS, Dd);
    return strm;
}
