#include "Performance.h"
#include <cctype>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

Performance::Performance(std::string actName, std::string date, int attendance)
{
    if (actName.empty()) {
        throw std::invalid_argument("a performance must name its act");
    }

    // date must look like YYYY-MM-DD
    bool goodDate = date.size() == 10 && date[4] == '-' && date[7] == '-';
    for (int i = 0; i < static_cast<int>(date.size()) && goodDate; i++) {
        if (i != 4 && i != 7 && !isdigit(static_cast<unsigned char>(date[i]))) {
            goodDate = false;
        }
    }
    if (goodDate) {
        int month = std::stoi(date.substr(5, 2));
        int day = std::stoi(date.substr(8, 2));
        goodDate = month >= 1 && month <= 12 && day >= 1 && day <= 31;
    }
    if (!goodDate) {
        throw std::invalid_argument("'" + date +
                                    "' is not a date in YYYY-MM-DD form");
    }

    if (attendance < 0 || attendance > 100000) {
        throw std::invalid_argument("attendance must be between 0 and 100000");
    }

    this->actName = actName;
    this->date = date;
    this->attendance = attendance;
}

Performance Performance::FromLine(std::string line)
{
    std::vector<std::string> parts;
    std::stringstream ss(line);
    std::string part;

    while (std::getline(ss, part, ',')) {
        parts.push_back(part);
    }

    if (parts.size() != 3) {
        throw std::invalid_argument("expected 3 fields but found " +
                                    std::to_string(parts.size()));
    }

    // attendance must be a whole number, so "sold out" or "12abc" is rejected
    std::string number = parts[2];
    if (number.empty()) {
        throw std::invalid_argument("attendance is missing");
    }
    for (int i = 0; i < static_cast<int>(number.size()); i++) {
        if (!isdigit(static_cast<unsigned char>(number[i]))) {
            throw std::invalid_argument("attendance '" + number +
                                        "' is not a number");
        }
    }

    return Performance(parts[0], parts[1], std::stoi(number));
}

bool Performance::operator==(const Performance& other) const
{
    return actName == other.actName && date == other.date;
}

bool Performance::operator!=(const Performance& other) const
{
    return !(*this == other);
}

bool Performance::operator<(const Performance& other) const
{
    return compareTo(other) < 0;
}

int Performance::compareTo(const Performance& other) const
{
    int byDate = date.compare(other.date);

    if (byDate != 0) {
        return byDate;
    }
    else {
        return actName.compare(other.actName);
    }
}

std::string Performance::ToString() const
{
    std::ostringstream os;

    os << date << "  " << std::left << std::setw(18) << actName << std::right
       << std::setw(6) << attendance;

    return os.str();
}

std::string Performance::getActName() const
{
    return actName;
}
std::string Performance::getDate() const
{
    return date;
}
int Performance::getAttendance() const
{
    return attendance;
}
