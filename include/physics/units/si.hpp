#ifndef PHYSICS_UNITS_SI_HPP__
#define PHYSICS_UNITS_SI_HPP__

#include "../units.hpp"

namespace physics {
namespace units {
namespace si {

/// \name Dimension Symbols
/// \{
// typedef Mass                     M;
// typedef Length                   L;
// typedef Time                     T;
// typedef ElectricCurrent          I;
// typedef ThermodynamicTemperature Th; /// \note Th for Theta
// typedef LuminousIntensity        J;
// typedef AmountOfSubstance        N;
/// \}

/// \name Base Units
/// \{
extern const Mass                     kg;  ///< kilogram
extern const Length                   m;   ///< metro
extern const Time                     s;   ///< second
extern const ElectricCurrent          A;   ///< Ampere
extern const ThermodynamicTemperature K;   ///< Kelvin
extern const LuminousIntensity        cd;  ///< candela
extern const AmountOfSubstance        mol; ///< mole
/// \}

/// \name Derived quantities units
/// \{
extern const Units<0, 0, 2, 0, 0, 0, 0> s2;  ///< squared second
extern const Angle                      rad; ///< radian
extern const SolidAngle                 sr;  ///< steradian
extern const Area                       m2;  ///< squared meter
extern const Volume                     m3;  ///< cubic meter
extern const Frequency                  Hz;  ///< Hertz
extern const Radioactivity              Bq;  ///< Becquerel
extern const Force                      N;   ///< Newton
extern const Pressure                   Pa;  ///< Pascal
extern const Energy                     J;   ///< Joule
extern const Power                      W;   ///< Watt
extern const ElectricCharge             C;   ///< Coulomb
extern const Voltage                    V;   ///< Volt
extern const Capacitance                F;   ///< Farad
extern const ElectricalResistance       Ohm; ///< Ohm
extern const ElectricalConducatance     S;   ///< Siemens
extern const MagneticFlux               Wb;  ///< Weber
extern const MagneticFluxDensity        T;   ///< Tesla
extern const Inductance                 H;   ///< Henry
extern const LuminousFlux               lm;  ///< lumen
extern const Illuminance                lx;  ///< lux
extern const AbsorvedDose               Gy;  ///< Gray
extern const EquivalentDose             Sv;  ///< Sievert
extern const CatalyticActivity          kat; ///< katal
/// \}

/// \name Common units
/// \{
extern const Length micra, mm, cm, dm, hm, km;
extern const Area   mm2, cm2, dm2, hectare, km2;
extern const Mass   g, tonne;
/// \}

} // namespace si
} // namespace units
} // namespace physics
#endif // PHYSICS_UNITS_SI_HPP__
