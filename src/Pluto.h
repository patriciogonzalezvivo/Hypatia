/*****************************************************************************\
 * Pluto.h
 *
 * Pluto is a class that can calculate the orbit of Pluto.
 * It currently requires data from the file 'vsop.bin'.
 *
 * author: mark huss (mark@mhuss.com)
 * Based on Bill Gray's open-source code at projectpluto.com
 *
\*****************************************************************************/

#pragma once

#define N_COEFFS 36

struct PlutoCoeffs {
   short j, s, p, dummyToMaintainAlignment;
   short lon_a, lon_b, lat_a, lat_b, rad_a, rad_b;
};

class Pluto {
public:
    static void calcAllLocs (double& lon, double& lat, double& r, const double t);
};
