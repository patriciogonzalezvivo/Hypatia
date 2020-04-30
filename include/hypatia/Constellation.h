#pragma once

#include "coordinates/Equatorial.h"

#include <vector>

namespace hypatia {

class Constellation {
public:

    static const int TOTAL;

    Constellation();
    Constellation( int _id );
    Constellation( char * _abbr );
    Constellation( const Equatorial &_point );
    Constellation( double _ra, double _dec );

    void        setId( int _id );
    int         getId() const { return m_id; }

    char*       getName() const;
    char*       getAbbreviation() const;

    Equatorial  getEquatorialCentroid() const { return m_centroid; }

    std::vector<int>        getStarIndices() const { return m_sIndices; }
    std::vector<Equatorial> getBoundary() const { return m_boundary; }

protected:
    int                     m_id;
    Equatorial              m_centroid;
    std::vector<int>        m_sIndices;
    std::vector<Equatorial> m_boundary;
};

inline std::ostream& operator<<(std::ostream& strm, const Constellation& c) {
    strm << c.getName() << " (" << c.getAbbreviation() << "), ";
    strm << c.getEquatorialCentroid();
    return strm;
}

}
