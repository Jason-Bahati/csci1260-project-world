#include "SetList.h"
#include <sstream>
#include <stdexcept>
#include <string>

SetList::SetList(int seq, std::string title, int minutes)
{
    if (title.empty()) {
        throw std::invalid_argument("A song must have a title.");
    }
    if (minutes <= 0 || minutes > 60) {
        throw std::invalid_argument("A song must be 1 to 60 minutes long.");
    }

    this->seq = seq;
    this->title = title;
    this->minutes = minutes;
}

std::string SetList::Describe()
{
    std::ostringstream os;
    os << "    song " << seq << ": " << title << " (" << minutes << " min)";
    return os.str();
}

int SetList::getSeq() const
{
    return seq;
}
std::string SetList::getTitle() const
{
    return title;
}
int SetList::getMinutes() const
{
    return minutes;
}
