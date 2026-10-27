#include "RockBand.h"
#include "Band.h"
#include <stdexcept>
#include <string>

namespace {
const int WATTS_PER_AMP = 800;
const int BASE_PA_WATTS = 1000;
} // namespace

RockBand::RockBand(const std::string& name, int memberCount, int ampCount)
    : Band(name, memberCount), ampCount_(ampCount)
{
    if (ampCount < 1) {
        throw std::invalid_argument("A rock band needs atleast 1 amp: " + name);
    }
}

int RockBand::getAmpCount() const
{
    return ampCount_;
}

std::string RockBand::genre() const
{
    return "Rock";
}

int RockBand::WattsRequired() const
{
    return BASE_PA_WATTS + ampCount_ * WATTS_PER_AMP;
}

std::string RockBand::rigDescribe() const
{
    return getName() + ": " + std::to_string(ampCount_) +
           " amp stacks, full drumkit, vocal mics";
}

std::string RockBand::describe() const
{
    return Band::describe() + " | " + std::to_string(ampCount_) + " amps";
}
