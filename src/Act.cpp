#include "Act.h"
#include "SetList.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

Act::Act(std::string name)
{
    if (name.empty()) {
        throw std::invalid_argument("An act must have a name.");
    }

    this->name = name;
    nextSeq = 1;
}

std::string Act::Describe() const
{
    std::ostringstream os;
    os << name << " (" << Genre() << "), " << SetLength() << " min set";
    return os.str();
}

std::string Act::ToString()
{
    return Describe();
}

bool Act::AddSong(std::string title, int minutes)
{
    if (title.empty() || minutes <= 0 || minutes > 60) {
        return false;
    }
    else {
        SetList s(nextSeq, title, minutes);
        setlist.push_back(s);
        nextSeq++;
        return true;
    }
}

int Act::SetLength() const
{
    int total = 0;
    for (int i = 0; i < static_cast<int>(setlist.size()); i++) {
        total = total + setlist[i].getMinutes();
    }
    return total;
}

std::string Act::SetlistLines()
{
    std::string str;

    for (int i = 0; i < static_cast<int>(setlist.size()); i++) {
        if (str.empty()) {
            str.append(setlist[i].Describe());
        }
        else {
            str.append("\n");
            str.append(setlist[i].Describe());
        }
    }

    return str;
}

std::string Act::getName() const
{
    return name;
}
int Act::getSongCount() const
{
    return static_cast<int>(setlist.size());
}
