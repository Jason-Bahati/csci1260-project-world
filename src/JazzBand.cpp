#include "JazzBand.h"
#include "Band.h"
#include <stdexcept>

JazzBand::JazzBand(const std::string& name, int memberCount,
                   const std::string& leadInstrument)
    : Band(name, memberCount), leadInstrument_(leadInstrument)
{
    if (leadInstrument.empty()) {
        throw std::invalid_argument(
            "A jazz ensemble needs a lead instrument: " + name);
    }
}

std::string JazzBand::getLeadInstrument() const
{
    return leadInstrument_;
}

std::string JazzBand::genre() const
{
    return "Jazz";
}

std::string JazzBand::describe() const
{
    return Band::describe() + " | led by " + leadInstrument_;
}
