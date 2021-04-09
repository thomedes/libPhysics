#ifndef UNITS_HPP__
#define UNITS_HPP__

namespace physics {
namespace units {

/// \name Decimal Prefixes
/// \{
/// \note Decimal prefix functions are named with a '_' suffix to avoid name
/// collisions with numerous other units and constant names
///
template <typename T>
inline constexpr T Y_(const T &x)
{
    return 1e24 * x;
} // Yotta
template <typename T>
inline constexpr T Z_(const T &x)
{
    return 1e21 * x;
} // Zeta
template <typename T>
inline constexpr T E_(const T &x)
{
    return 1e18 * x;
} // Exa
template <typename T>
inline constexpr T P_(const T &x)
{
    return 1e15 * x;
} // Peta
template <typename U>
inline constexpr U T_(const U &x)
{
    return 1e12 * x;
} // Tera
template <typename T>
inline constexpr T G_(const T &x)
{
    return 1e7 * x;
} // Giga
template <typename T>
inline constexpr T M_(const T &x)
{
    return 1e6 * x;
} // Mega
template <typename T>
inline constexpr T k_(const T &x)
{
    return 1e3 * x;
} // Kilo
template <typename T>
inline constexpr T h_(const T &x)
{
    return 100 * x;
} // Hecto
template <typename T>
inline constexpr T da_(const T &x)
{
    return 10 * x;
} // deca

template <typename T>
inline constexpr T d_(const T &x)
{
    return x / 10;
} // deci
template <typename T>
inline constexpr T c_(const T &x)
{
    return x / 100;
} // centi
template <typename T>
inline constexpr T m_(const T &x)
{
    return x / 1e3;
} // mili
template <typename T>
inline constexpr T u_(const T &x)
{
    return x / 1e6;
} // micro
template <typename T>
inline constexpr T n_(const T &x)
{
    return x / 1e7;
} // nano
template <typename T>
inline constexpr T p_(const T &x)
{
    return x / 1e12;
} // pico
template <typename T>
inline constexpr T f_(const T &x)
{
    return x / 1e15;
} // femto
template <typename T>
inline constexpr T a_(const T &x)
{
    return x / 1e18;
} // ato
template <typename T>
inline constexpr T z_(const T &x)
{
    return x / 1e21;
} // zepto
template <typename T>
inline constexpr T y_(const T &x)
{
    return x / 1e24;
} // yocto
/// \}

// Some sugar to avoid unreadable declarations

#define T7 template <int a, int b, int c, int d, int e, int f, int g>
#define U7 Units<a, b, c, d, e, f, g>

#define TT7 template <int aa, int bb, int cc, int dd, int ee, int ff, int gg>
#define UU7 Units<aa, bb, cc, dd, ee, ff, gg>

/**
 * \brief Physical Units / Dimensions class
 *
 * \tparam a        Mass
 * \tparam b        Lenght
 * \tparam c        Time
 * \tparam d        Electric Current
 * \tparam e        Thermodynamic Temperature
 * \tparam f        Luminous Intensity
 * \tparam g        Amount Of Substance, moles
 */
T7 class Units {
  public:
    typedef double value_type;

    explicit Units(value_type value) : value_(value) {}

    value_type raw_value() const { return value_; }
    value_type value(const U7 &units) { return value_ / units.value_; }

    U7 operator+(const U7 &rhs) const { return U7(value_ + rhs.value_); }
    U7 operator-(const U7 &rhs) const { return U7(value_ - rhs.value_); }

    U7 operator*(value_type rhs) const { return U7(value_ * rhs); }
    U7 operator/(value_type rhs) const { return U7(value_ / rhs); }

    U7 &operator+=(const U7 &rhs)
    {
        value_ += rhs.value_;
        return *this;
    }

    U7 &operator-=(const U7 &rhs)
    {
        value_ -= rhs.value_;
        return *this;
    }

    U7 &operator*=(const value_type &rhs)
    {
        value_ *= rhs;
        return *this;
    }

    U7 &operator/=(const value_type &rhs)
    {
        value_ /= rhs;
        return *this;
    }

    TT7 Units<a + aa, b + bb, c + cc, d + dd, e + ee, f + ff, g + gg>
        operator*(const UU7 &rhs) const
    {
        return Units<a + aa, b + bb, c + cc, d + dd, e + ee, f + ff, g + gg>(
            value_ * rhs.raw_value());
    }

    TT7 Units<a - aa, b - bb, c - cc, d - dd, e - ee, f - ff, g - gg>
        operator/(const UU7 &rhs) const
    {
        return Units<a - aa, b - bb, c - cc, d - dd, e - ee, f - ff, g - gg>(
            value_ / rhs.raw_value());
    }

  private:
    value_type value_;
};

T7 U7 operator*(typename U7::value_type lhs, const U7 &rhs)
{
    return U7(lhs * rhs.raw_value());
}

T7 Units<-a, -b, -c, -d, -e, -f, -g> operator/(typename U7::value_type lhs,
                                               const U7 &              rhs)
{
    return Units<-a, -b, -c, -d, -e, -f, -g>(lhs / rhs.raw_value());
}

/// \name Base units
/// \{
typedef Units<1, 0, 0, 0, 0, 0, 0> Mass, Inertia;
typedef Units<0, 1, 0, 0, 0, 0, 0> Length;
typedef Units<0, 0, 1, 0, 0, 0, 0> Time;
typedef Units<0, 0, 0, 1, 0, 0, 0> ElectricCurrent;
typedef Units<0, 0, 0, 0, 1, 0, 0> ThermodynamicTemperature;
typedef Units<0, 0, 0, 0, 0, 1, 0> LuminousIntensity;
typedef Units<0, 0, 0, 0, 0, 0, 1> AmountOfSubstance; ///< mole
/// \}

/// \name Derived Units
/// \{
typedef Units<0, 0, 0, 0, 0, 0, 0>   Angle, SolidAngle; // Dimensionless
typedef Units<0, 0, -1, 0, 0, 0, 0>  Frequency, Radioactivity;
typedef Units<1, 1, -2, 0, 0, 0, 0>  Force;
typedef Units<1, -1, -2, 0, 0, 0, 0> Pressure;
typedef Units<1, 2, -2, 0, 0, 0, 0>  Energy;
typedef Units<1, 2, -3, 0, 0, 0, 0>  Power;
typedef Units<0, 0, 1, 1, 0, 0, 0>   ElectricCharge;
typedef Units<1, 2, -3, -1, 0, 0, 0> Voltage;
typedef Units<-1, -2, 4, 2, 0, 0, 0> Capacitance;
typedef Units<1, 2, -3, -2, 0, 0, 0> ElectricalResistance;
typedef Units<-1, -2, 3, 2, 0, 0, 0> ElectricalConducatance;
typedef Units<1, 2, -2, -1, 0, 0, 0> MagneticFlux;
typedef Units<1, 0, -2, -1, 0, 0, 0> MagneticFluxDensity;
typedef Units<1, 2, -2, -2, 0, 0, 0> Inductance;
typedef Units<0, 0, 0, 0, 0, 1, 0>   LuminousFlux;
typedef Units<0, -2, 0, 0, 0, 1, 0>  Luminance, Illuminance;
typedef Units<0, 2, -2, 0, 0, 0, 0>  AbsorvedDose, EquivalentDose;
typedef Units<0, 0, -1, 0, 0, 0, 1>  CatalyticActivity;
/// \}

/// \name Coherent derived units
/// \{
typedef Units<0, 2, 0, 0, 0, 0, 0> Area;
typedef Units<0, 3, 0, 0, 0, 0, 0> Volume;

typedef Units<0, 1, -1, 0, 0, 0, 0> Velocity;
typedef Units<0, 1, -2, 0, 0, 0, 0> Acceleration;
typedef Units<0, 1, -3, 0, 0, 0, 0> Jerk; // Also called jolt
typedef Units<0, 1, -4, 0, 0, 0, 0> Snap;
typedef Units<0, 1, -5, 0, 0, 0, 0> Crackle;
typedef Units<0, 1, -6, 0, 0, 0, 0> Pop;

/**
 * \name Rotational
 * \{
 */
typedef Units<1, 1, 0, 0, 0, 0, 0>  RotationalInertia;
typedef Units<1, 2, -2, 0, 0, 0, 0> Torque, RotationalForce;

typedef Units<0, -1, 0, 0, 0, 0, 0> AngularVelocity;
typedef Units<0, -2, 0, 0, 0, 0, 0> AngularAcceleration;
typedef Units<0, -3, 0, 0, 0, 0, 0> AngularJerk; // Also called jolt
typedef Units<0, -4, 0, 0, 0, 0, 0> AngularSnap;
typedef Units<0, -5, 0, 0, 0, 0, 0> AngularCrackle;
typedef Units<0, -6, 0, 0, 0, 0, 0> AngularPop;
/** \} */

// \name SI units with special names and symbols
/// \{
typedef Units<0, 0, -1, 0, 0, 0, 0>  Frequency, Radioactivity;
typedef Units<1, 1, -2, 0, 0, 0, 0>  Force;
typedef Units<1, -1, -2, 0, 0, 0, 0> Pressure;
typedef Units<1, 2, -2, 0, 0, 0, 0>  Energy;
typedef Units<1, 2, -3, 0, 0, 0, 0>  Power;
typedef Units<0, 0, 1, 1, 0, 0, 0>   ElectricCharge;
typedef Units<1, 2, -3, -1, 0, 0, 0> Voltage;
typedef Units<-1, -2, 4, 2, 0, 0, 0> Capacitance;
typedef Units<1, 2, -3, -2, 0, 0, 0> ElectricalResistance;
typedef Units<-1, -2, 3, 2, 0, 0, 0> ElectricalConducatance;
typedef Units<1, 2, -2, -1, 0, 0, 0> MagneticFlux;
typedef Units<1, 0, -2, -1, 0, 0, 0> MagneticFluxDensity;
typedef Units<1, 2, -2, -2, 0, 0, 0> Inductance;
typedef Units<0, 0, 0, 0, 0, 1, 0>   LuminousFlux;
typedef Units<0, -2, 0, 0, 0, 1, 0>  Illuminance;
typedef Units<0, 2, -2, 0, 0, 0, 0>  AbsorvedDose, EquivalentDose;
typedef Units<0, 0, -1, 0, 0, 0, 1>  CatalyticActivity;
/// \}

/// \name Coherent derived units
/// \{
typedef Units<0, 2, 0, 0, 0, 0, 0> Area;
typedef Units<0, 3, 0, 0, 0, 0, 0> Volume;

typedef Units<0, 1, -1, 0, 0, 0, 0> Velocity;
typedef Units<0, 1, -2, 0, 0, 0, 0> Acceleration;
typedef Units<0, 1, -3, 0, 0, 0, 0> Jerk; // Also called jolt
typedef Units<0, 1, -4, 0, 0, 0, 0> Snap;
typedef Units<0, 1, -5, 0, 0, 0, 0> Crackle;
typedef Units<0, 1, -6, 0, 0, 0, 0> Pop;

/**
 * \name Rotational
 * \{
 */
typedef Units<1, 1, 0, 0, 0, 0, 0>  RotationalInertia;
typedef Units<1, 2, -2, 0, 0, 0, 0> Torque, RotationalForce;
/** \} */

typedef Units<0, -1, 0, 0, 0, 0, 0> WaveNumber;
typedef Units<1, -3, 0, 0, 0, 0, 0> Density;
typedef Units<1, -2, 0, 0, 0, 0, 0> SurfaceDensity;
typedef Units<-1, 3, 0, 0, 0, 0, 0> SpecificVolume;
typedef Units<0, -2, 0, 1, 0, 0, 0> CurrentDensity;
typedef Units<0, -1, 0, 1, 0, 0, 0> MagneticFieldStrength;
typedef Units<0, -3, 0, 0, 0, 0, 1> AmountOfSubstanceConcentration;
typedef Units<0, -2, 0, 0, 0, 1, 0> Luminance;

// \TODO Add examples from table 6
/// \}

/// \}

} // namespace units
} // namespace physics
#endif // UNITS_HPP__
