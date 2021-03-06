/*
 * Copyright 2013 Daniel Warner <contact@danrw.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "TLE.h"
#include "Orbit.h"
#include "../coordinates/ECI.h"

/**
 * @brief The simplified perturbations model 4 propagater.
 */
class SGP4 {
public:
    SGP4();
    virtual ~SGP4();
    virtual void    setTLE(const TLE& _tle);
    
    virtual Orbit   getOrbit() const { return m_elements; };
    virtual ECI     getECI(double _jd) const;
    
private:
    struct CommonConstants {
        double cosio;
        double sinio;
        double eta;
        double t2cof;
        double a3ovk2;
        double x1mth2;
        double x3thm1;
        double x7thm1;
        double aycof;
        double xlcof;
        double xnodcf;
        double c1;
        double c4;
        double omgdot; // secular rate of omega (radians/sec)
        double xnodot; // secular rate of xnode (radians/sec)
        double xmdot;  // secular rate of xmo   (radians/sec)
    };
    
    struct NearSpaceConstants {
        double c5;
        double omgcof;
        double xmcof;
        double delmo;
        double sinmo;
        double d2;
        double d3;
        double d4;
        double t3cof;
        double t4cof;
        double t5cof;
    };
    
    struct DeepSpaceConstants {
        double gsto;
        double zmol;
        double zmos;
        
        /*
         * lunar / solar constants for epoch
         * applied during DeepSpaceSecular()
         */
        double sse;
        double ssi;
        double ssl;
        double ssg;
        double ssh;
        /*
         * lunar / solar constants
         * used during DeepSpaceCalculateLunarSolarTerms()
         */
        double se2;
        double si2;
        double sl2;
        double sgh2;
        double sh2;
        double se3;
        double si3;
        double sl3;
        double sgh3;
        double sh3;
        double sl4;
        double sgh4;
        double ee2;
        double e3;
        double xi2;
        double xi3;
        double xl2;
        double xl3;
        double xl4;
        double xgh2;
        double xgh3;
        double xgh4;
        double xh2;
        double xh3;
        /*
         * used during DeepSpaceCalcDotTerms()
         */
        double d2201;
        double d2211;
        double d3210;
        double d3222;
        double d4410;
        double d4422;
        double d5220;
        double d5232;
        double d5421;
        double d5433;
        double del1;
        double del2;
        double del3;
        /*
         * whether the deep space orbit is
         * geopotential resonance for 12 hour orbits
         */
        bool resonance_flag;
        /*
         * whether the deep space orbit is
         * 24h synchronous resonance
         */
        bool synchronous_flag;
    };
    
    struct IntegratorValues {
        double xndot;
        double xnddt;
        double xldot;
    };
    
    struct IntegratorConstants {
        /*
         * integrator constants
         */
        double xfact;
        double xlamo;
        
        /*
         * integrator values for epoch
         */
        struct IntegratorValues values_0;
    };
    
    struct IntegratorParams {
        /*
         * integrator values
         */
        double xli;
        double xni;
        double atime;
        /*
         * itegrator values for current d_atime_
         */
        struct IntegratorValues values_t;
    };
    
    ECI findPositionSDP4(const double _jd) const;
    ECI findPositionSGP4(const double _jd) const;
    ECI calculateFinalPositionVelocity(const double tsince,
                                       const double e,
                                       const double a,
                                       const double omega,
                                       const double xl,
                                       const double xnode,
                                       const double xincl,
                                       const double xlcof,
                                       const double aycof,
                                       const double x3thm1,
                                       const double x1mth2,
                                       const double x7thm1,
                                       const double cosio,
                                       const double sinio) const;
    /**
     * Deep space initialisation
     */
    void deepSpaceInitialise(
                             const double eosq,
                             const double sinio,
                             const double cosio,
                             const double betao,
                             const double theta2,
                             const double betao2,
                             const double xmdot,
                             const double omgdot,
                             const double xnodot);
    /*
     * Calculate lunar / solar terms
     */
    void deepSpaceCalculateLunarSolarTerms(
                                           const double tsince,
                                           double& pe,
                                           double& pinc,
                                           double& pl,
                                           double& pgh,
                                           double& ph) const;
    /**
     * Calculate lunar / solar periodics and apply
     */
    void deepSpacePeriodics(
                            const double tsince,
                            double& em,
                            double& xinc,
                            double& omgasm,
                            double& xnodes,
                            double& xll) const;
    /**
     * Deep space secular effects
     */
    void deepSpaceSecular(
                          const double tsince,
                          double& xll,
                          double& omgasm,
                          double& xnodes,
                          double& em,
                          double& xinc,
                          double& xn) const;
    /**
     * Calculate dot terms
     * @param[in,out] values the integrator values
     */
    void deepSpaceCalcDotTerms(struct IntegratorValues& values) const;
    /**
     * Deep space integrator for time period of delt
     */
    void deepSpaceIntegrator(
                             const double delt,
                             const double step2,
                             const struct IntegratorValues& values) const;
    void reset();
    
    /*
     * the constants used
     */
    struct CommonConstants          m_commonConsts;
    struct NearSpaceConstants       m_nearspaceConsts;
    struct DeepSpaceConstants       m_deepspaceConsts;
    struct IntegratorConstants      m_integratorConsts;
    mutable struct IntegratorParams m_integratorParams;
    Orbit                           m_elements;
    bool                            m_useSimpleModel;
    bool                            m_useDeepSpace;
    
    static const struct SGP4::CommonConstants Empty_CommonConstants;
    static const struct SGP4::NearSpaceConstants Empty_NearSpaceConstants;
    static const struct SGP4::DeepSpaceConstants Empty_DeepSpaceConstants;
    static const struct SGP4::IntegratorConstants Empty_IntegratorConstants;
    static const struct SGP4::IntegratorParams Empty_IntegratorParams;
};

inline std::ostream& operator<<(std::ostream& strm, const SGP4& s) {
    strm << std::right << std::fixed;
    strm << "Satelite:         " << std::endl;
    return strm;
}
