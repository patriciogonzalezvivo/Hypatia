#pragma once

#include <string>
#include <vector>

#include "Body.h"
#include "Luna.h"
#include "TimeOps.h"
#include "EqPoint.h"

class Constellation : public EqPoint {
public:

    static const int TOTAL;

    Constellation();
    Constellation( int _id );
    Constellation( Body &_body );
    Constellation( Luna &_luna );
    Constellation( char * _abbr );
    Constellation( std::string _abbr );
    Constellation( double _ra, double _dec );

    void setId( int _id );
    int getId() const { return m_id; };
    std::string getName();
    std::string getAbbreviation();

    std::vector<int> getStarsIds() const { return m_starsIds; };

protected:
    std::vector<int> m_starsIds;

    int m_id;
};
