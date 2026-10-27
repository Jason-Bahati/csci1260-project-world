#include "Venue.h"
#include "Act.h"
#include <cctype>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

Venue::Venue(std::string name, int capacity)
{
    if (name.empty()) {
        throw std::invalid_argument("A venue must have a name.");
    }
    if (capacity <= 0) {
        throw std::invalid_argument(
            "A venue's capacity must be greater than 0: " + name);
    }

    this->name = name;
    this->capacity = capacity;
}

bool Venue::Add(Act* act)
{
    if (act != nullptr && Find(act->getName()) == nullptr) {
        acts.push_back(act);
        return true;
    }
    else {
        return false;
    }
}

Act* Venue::Find(std::string name)
{
    for (int i = 0; i < static_cast<int>(acts.size()); i++) {
        if (acts[i]->getName().compare(name) == 0) {
            return acts[i];
        }
    }
    return nullptr;
}

int Venue::TotalMinutes()
{
    int total = 0;
    for (int i = 0; i < static_cast<int>(acts.size()); i++) {
        total = total + acts[i]->SetLength();
    }
    return total;
}

void Venue::PrintReport()
{
    std::cout << std::string(60, '=') << std::endl;

    // Title
    std::string upper = this->name;
    for (int i = 0; i < static_cast<int>(upper.size()); i++) {
        upper[i] = toupper(upper[i]);
    }
    std::cout << "  " << upper << " : LINEUP REPORT" << std::endl;

    std::cout << std::string(60, '=') << std::endl;

    // heading row
    std::cout << " " << std::left << std::setw(20) << "ACT"
              << " " << std::setw(10) << "GENRE" << std::right << std::setw(9)
              << "PEOPLE" << std::setw(8) << "SONGS" << std::setw(8) << "MIN"
              << std::endl;

    std::cout << std::string(60, '-') << std::endl;

    for (int i = 0; i < static_cast<int>(acts.size()); i++) {
        std::cout << " " << std::left << std::setw(20) << acts[i]->getName()
                  << " " << std::setw(10) << acts[i]->genre() << std::right
                  << std::setw(9) << acts[i]->PerformerCount() << std::setw(8)
                  << acts[i]->getSongCount() << std::setw(8)
                  << acts[i]->SetLength() << std::endl;
    }

    std::cout << std::string(60, '-') << std::endl;

    // Summary
    std::cout << " " << std::left << std::setw(46) << "Acts booked:"
              << " " << std::right << std::setw(11) << acts.size() << std::endl;

    std::cout << " " << std::left << std::setw(46) << "Capacity:"
              << " " << std::right << std::setw(11) << capacity << std::endl;

    std::cout << " " << std::left << std::setw(46) << "Minutes of music:"
              << " " << std::right << std::setw(11) << TotalMinutes()
              << std::endl;

    std::cout << std::string(60, '=') << std::endl;
}

std::string Venue::getName() const
{
    return name;
}
int Venue::getCapacity() const
{
    return capacity;
}
int Venue::getCount() const
{
    return static_cast<int>(acts.size());
}
