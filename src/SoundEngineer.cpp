#include "SoundEngineer.h"
#include "IAmplified.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

SoundEngineer::SoundEngineer(std::string name, int maxWatts)
{
    if (name.empty()) {
        throw std::invalid_argument("A sound engineer must have a name.");
    }
    if (maxWatts <= 0) {
        throw std::invalid_argument(
            "The PA circuit must supply more than 0 watts.");
    }

    this->name = name;
    this->maxWatts = maxWatts;
}

std::string SoundEngineer::Prepare(IAmplified& act)
{
    std::ostringstream os;
    int watts = act.WattsRequired();

    os << name << " patches in " << act.rigDescribe() << " -> " << watts
       << " W";

    if (watts <= maxWatts) {
        os << " (OK)";
    }
    else {
        os << " (OVER " << maxWatts << " W, needs a second circuit)";
    }

    return os.str();
}

std::string SoundEngineer::getName() const
{
    return name;
}
int SoundEngineer::getMaxWatts() const
{
    return maxWatts;
}
