#ifndef CONTANTS_HPP__
#define CONTANTS_HPP__

#include "units.hpp"

namespace physics {
namespace units {
namespace constants {

extern const double                       pi; ///< PI, non SI but useful
extern const Frequency                    HyperfineTransitionFreqOfCs;
extern const Velocity                     c;   ///< Speed of light in vacuum
extern const ElectricCharge               e;   ///< Elementary charge
extern const Units<-1, -2, 3, 0, 0, 1, 0> Kcd; ///< luminous efficacy

/**
 * \name Atomic Units
 * \{
 */
extern const Energy eV; ///< Electronvolt
extern const Units<1, 2, -1, 0, 0, 0, 0>  h;  ///< Planck constant
extern const Units<0, 0, 0, 0, 0, 0, -1>  NA;  ///< Avogadro constant
/** \} */

/// \name Accepted units
/// \{
/// Non-SI units that are accepted for use with the SI
extern const Time   min, hour, day, week, year;
extern const Length au; ///< Astronomical unit

extern const Angle  degree, minute, second;
extern const Area   ha; ///< Hectare
extern const Volume l;  ///< Liter
extern const Mass   t,  ///< Tonne
    Da;                 ///< Dalton
/// \}

} // namespace constants
} // namespace units
} // namespace physics
#endif  // CONTANTS_HPP__
