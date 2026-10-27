#include "Band.h"
#include "Act.h"
#include <stdexcept>

Band::Band(const std::string& name, int memberCount)
    : Act(name), memberCount_(memberCount)
{
    if (memberCount_ < 2) {
        throw std::invalid_argument("A Band needs to have atleast 2 members");
    }
}
std::string Band::Describe() const
{
    return Act::Describe() + " | full band lineup";
}

int Band::getMemberCount() const
{
    return memberCount_;
}

int Band::performerCount() const
{
    return memberCount_;
}
