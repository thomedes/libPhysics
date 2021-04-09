#include "physics/units/si.hpp"

namespace physics {
namespace units {
namespace si {

/// \name Base Units
/// \{
const Mass                     kg(1);  ///< kilogram
const Length                   m(1);   ///< metro
const Time                     s(1);   ///< second
const ElectricCurrent          A(1);   ///< Ampere
const ThermodynamicTemperature K(1);   ///< Kelvin
const LuminousIntensity        cd(1);  ///< candela
const AmountOfSubstance        mol(1); ///< mole
/// \}

/// \name Derived quantities units
/// \{
const Units<0, 0, 2, 0, 0, 0, 0> s2(1);             ///< squared second
const Angle                      rad(1);            ///< radian
const SolidAngle                 sr(1);             ///< steradian
const Area                       m2  = m * m;       ///< squared meter
const Volume                     m3  = m2 * m;      ///< cubic meter
const Frequency                  Hz  = 1 / s;       ///< Hertz
const Radioactivity              Bq  = 1 / s;       ///< Becquerel
const Force                      N   = kg * m / s2; ///< Newton
const Pressure                   Pa  = N / m2;      ///< Pascal
const Energy                     J   = N * m;       ///< Joule
const Power                      W   = J / s;       ///< Watt
const ElectricCharge             C   = A * s;       ///< Coulomb
const Voltage                    V   = W / A;       ///< Volt
const Capacitance                F   = C / V;       ///< Farad
const ElectricalResistance       Ohm = V / A;       ///< Ohm
const ElectricalConducatance     S   = 1 / Ohm;     ///< Siemens
const MagneticFlux               Wb  = V * s;       ///< Weber
const MagneticFluxDensity        T   = Wb / m2;     ///< Tesla
const Inductance                 H   = Wb / A;      ///< Henry
const LuminousFlux               lm  = cd * sr;     ///< lumen
const Illuminance                lx  = lm / m2;     ///< lux
const AbsorvedDose               Gy  = J / kg;      ///< Gray
const EquivalentDose             Sv  = J / kg;      ///< Sievert
const CatalyticActivity          kat = mol / s;     ///< katal
/// \}

/// \name Common units
/// \{
extern const Length micra, mm, cm, dm, hm, km;
extern const Area mm2, cm2, dm2, hectare, km2;
extern const Mass g, tonne;
/// \}

}
} // namespace units
} // namespace physics
