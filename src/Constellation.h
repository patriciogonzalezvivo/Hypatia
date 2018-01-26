#pragma once

#include <vector>

#include "TimeOps.h"
#include "EqPoint.h"

class Constellation : public EqPoint {
public:

    static const int TOTAL;

    Constellation();
    Constellation( int _id );
    Constellation( char * _abbr );
    Constellation( const EqPoint &_point );
    Constellation( double _ra, double _dec );

    void setId( int _id );
    int getId() const { return m_id; };

    char * getName();
    char * getAbbreviation();

    std::vector<int> getStarIndices() const { return m_sIndices; };
    std::vector<EqPoint> getBoundary() const { return m_boundary; };

protected:
    std::vector<int>        m_sIndices;
    std::vector<EqPoint>    m_boundary;
    int m_id;
};
