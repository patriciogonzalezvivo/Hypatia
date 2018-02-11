/*****************************************************************************\
 * MathOps  defines misc. handy constants & mathematical fns
 *
 * author: mark huss (mark@mhuss.com)
 * Based on Bill Gray's open-source code at projectpluto.com
 *
 \*****************************************************************************/

#pragma once
#undef PI

enum ANGLE_FMT {
    Dd,        // 16.294°
    D_Mm,      // 12° 36.1'
    D_M_Ss,    // 12° 36' 59.1"
    Hs,        // 15.1h
    H_Mm,      // 15h 15,3m
    H_M_Ss     // 15h 15m 32.9s
};

enum ANGLE_TYPE {
    DEGS, RADS
};

struct MathOps {
    static const double PI;
    static const double TAU;
    static const double PI_OVER_TWO;
    static const double TWO_OVER_PI;
    static const double DEG_PER_CIRCLE;
    static const double RAD_PER_CIRCLE;
    
    static const double MINUTES_PER_DEGREE;
    static const double SECONDS_PER_DEGREE;
    static const double RADS_PER_DEGREE;
    
    static const double RADS_TO_DEGS;
    static const double DEGS_TO_RADS;
    static const double DEGS_TO_HRS;

    static const double RADS_TO_ARCS;
    static const double ARCS_TO_RADS;

    static const double RADIAN;
    
    static const double ROUND;
    static const double INVALID;

    /**
     * toDegrees(): convert radians to degrees
     *
     * @param an angle in radians
     *
     * @return an angle in degrees
     */
    static double toDegrees( double _rad );

    /**
     * toDegrees(): convert radians to degrees
     *
     * @param an degrees
     * @param an minutes
     * @param an seconds
     *
     * @return an angle in degrees
     */
    static double toDegrees( int _deg, int _min, double _sec );
    
    /**
     * toRadians(): convert degrees to radians
     *
     * @param an angle in degrees
     *
     * @return an angle in radians
     */
    static double toRadians( double _deg );
    
    /**
     * secToRadians(): convert arcseconds to radians
     *
     * @param an angle in arcseconds
     *
     * @return an angle in radians
     */
    static double secToRadians( double _sec );
    
    /**
     * toHrs(): convert arcseconds to radians
     *
     * @param degrees
     *
     * @return hours double
     */
    static double toHrs( double _angle, ANGLE_TYPE _type );
    
    /**
     * toDMS(): convert degress to degrees, minutes and seconds
     *
     * @param degrees in
     *
     * @param degrees out
     * @param minutes out
     * @param seconds out
     *
     */
    static void toDMS ( double deg, int &_deg, int &_min, double &_sec );
    
    /**
     * toHMS(): convert degress to degrees, minutes and seconds
     *
     * @param degrees in
     *
     * @param hours out
     * @param minutes out
     * @param seconds out
     *
     */
    static void toHMS ( double deg, int &_hrs, int &_min, double &_sec );
    
    /**
     * formatDegrees(): format degrees into a string
     *
     * @param degrees in
     * @param format type
     *
     * @return formated string
     *
     */
    static char* formatDegrees ( double _deg, ANGLE_FMT _format );
    
    /**
     * formatRadians(): format radiants into a string
     *
     * @param radians in
     * @param format type
     *
     * @return formated string
     *
     */
    static char* formatRadians ( double _rad, ANGLE_FMT _format );
      
    /**
     * normalizeDegrees(): reduce an angle in degrees to the range (0 <= d < 360)
     *
     * @param degrees
     *
     * @return degrees
     */
    static double normalizeDegrees( double _deg );
    
    /**
     * normalizeRadians(): reduce an angle in radians to the range (0 <= r < 2PI)
     *
     * @param radians
     *
     * @return radians
     */
    static double normalizeRadians( double _rad );
    
    // reduce (0 < d < 360) a positive angle in degreesand convert to radians
    //
    /**
     * normalizeDeg2Rad(): reduce an angle in degrees to the range (0 <= d < 360),
     *                     then convert to radians
     *
     * @param degrees
     *
     * @return radians
     */
    static double normalizeDeg2Rad( double _deg );
    
    /**
     *  quadrant(): returns the quadrant ( 0, 1, 2, or 3 ) of the spec'd angle
     *
     * @param angle - in radians
     *
     * @return quadrant of angle
     */
    static int quadrant( double _rad );
    
    /**
     * acose(): "safe" acos which prevents overflow errors
     *
     * @param angle
     *
     * @return acos (0 ... PI)
     */
    static double acose( double _rad );
    
    /**
     * asine(): "safe" asine which prevents overflow errors
     *
     * @param angle
     *
     * @return asin (PI/2 ... -PI/2)
     */
    static double asine( double _rad );

    /**
     * fract(): gives the fractional part of a number
     *
     * @param number
     *
     * @return fractional part of it 
 */
    static double fract (double _x);

    /**
     * mod(): calculates x modulus y
     *
     * @param base
     *
     * @return modulus of
     */
    static long mod ( long x, long y );
    static double mod ( double _x, double _y );
};
