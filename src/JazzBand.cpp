#include "JazzBand.h"
#include "Band.h"
#include <stdexcept>

JazzBand::JazzBand(std::string name, int memberCount,
                   std::string leadInstrument)
    : Band(name, memberCount), leadInstrument(leadInstrument)
{
    if (leadInstrument.empty()) {
        throw std::invalid_argument(
            "A jazz ensemble needs a lead instrument: " + name);
    }
}

std::string JazzBand::getLeadInstrument() const
{
    return leadInstrument;
}

std::string JazzBand::Genre() const
{
    return "Jazz";
}

std::string JazzBand::Describe() const
{
    return Band::Describe() + " | led by " + leadInstrument;
}
