#include "SetList.h"
#include <stdexcept>

SetList::SetList(const std::string& title, int minutes)
    : title_(title), minutes_(minutes)
{
    if (title.empty()) {
        throw std::invalid_argument("A song must have a title.");
    }
    if (minutes < 1 || minutes > 60) {
        throw std::invalid_argument(
            "Song length must be between 1 and 60 minutes: " + title);
    }
}

std::string SetList::getTitle() const
{
    return title_;
}

int SetList::getMinute() const
{
    return minutes_;
}

std::string SetList::toString() const
{
    return title_ + " (" + std::to_string(minutes_) + " min)";
}
