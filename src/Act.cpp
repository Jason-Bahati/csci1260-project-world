#include "Act.h"
#include "SetList.h"
#include <sstream>
#include <stdexcept>

Act::Act(const std::string& name) : name_(name)
{
    if (name.empty()) {
        throw std::invalid_argument("An act must have a name.");
    }
}

std::string Act::describe() const
{
    int people = performerCount();

    std::ostringstream os;
    os << name_ << " | " << genre() << " | " << people
       << (people == 1 ? " performer" : " performers") << " | " << list.size()
       << " songs, " << setLengthMinutes() << " min";
    return os.str();
}

void Act::addSong(const std::string& title, int minute)
{
    list.push_back(SetList(title, minute));
}

int Act::setLengthMinutes() const
{
    int total = 0;
    for (const SetList& song : list) {
        total += song.getMinute();
    }
    return total;
}
std::string Act::getName() const
{
    return name_;
}
