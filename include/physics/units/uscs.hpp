#ifndef PHYSICS_UNITS_AMERICAN_HPP__
#define PHYSICS_UNITS_AMERICAN_HPP__

#include "../units.hpp"

namespace physics {
namespace units {
namespace uscs {

extern const Length point, pica, inch, foot, yard, mile;
extern const Area   square_foot, yard, mile;

namespace survey {
    // US Survey feet and miles are slightly different
    extern const Length link, foot, rod, chain, furlong, mile, league;
    extern const Area link, square_foot, rod, chain, furlong, mile, league;

}
namespace nautical {
    // US Survey feet and miles are slightly different
    extern const Length fathom, cable, mile;
}

} // namespace uscs
} // namespace units
} // namespace physics
#endif // PHYSICS_UNITS_AMERICAN_HPP__
