#include "physics/constants.hpp"

#include "physics/units/si.hpp"

using namespace physics::units;
using namespace physics::units::si;

namespace physics {
namespace units {
namespace constants {

const double pi = 3.14159265358979323846; ///< PI, non SI but useful
const Units<1, 2, -1, 0, 0, 0, 0> h
    = 6.62607015e-34 * J * s; ///< Planck constant
const Frequency      HyperfineTransitionFreqOfCs = 9192631770.0 * Hz;
const Velocity       c = 299792458 * m / s;   ///< Speed of light in vacuum
const ElectricCharge e = 1.602176634e-19 * C; ///< Elementary charge
const Units<0, 0, 0, 0, 0, 0, -1> NA
    = 6.02214076e23 / mol;                             ///< Avogadro constant
const Units<-1, -2, 3, 0, 0, 1, 0> Kcd = 683 * lm / W; ///< luminous efficacy

const Time   min = 60 * s, hour = 60 * min, day = 24 * hour;
const Length au = 149597870700 * m; ///< Astronomical unit

namespace angle {
const Angle degree = pi / 180 * rad, minute = degree / 60,
            second = minute / 60;
}
const Area   ha = 1e4 * m2;             ///< Hectare
const Volume l  = m3 / 1000;            ///< Liter
const Mass   t  = 1000 * kg,            ///< Tonne
    Da          = 1.660539040e-27 * kg; ///< Dalton
const Energy eV = 1.602176634e-19 * J;  ///< Electronvolt

} // namespace constants

namespace si {

const Length mm = m / 1000, //
    km          = 1000 * m;
const Area  //
    cm2 = cm * cm,
    dm2 = dm * dm,
    m2 = m * m,
    km2 = km * km;

const Volume
    cm3 = cm * cm * cm,
    ml = cm3,
    dm3 = dm * dm * dm,
    liter = dm3,
    m3 = m * m * m;
} // namespace si

namespace uscs {

const Length inch = 25.4 * si::mm, //
    foot          = 12 * inch,     //
    yard          = 3 * foot,      //
    mile          = 1760 * yard,   //
    pica          = inch / 6,      //
    point         = pica / 12;
} // namespace uscs

} // namespace units
} // namespace physics
