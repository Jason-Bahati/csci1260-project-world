#ifndef BYATTENDANCE_H
#define BYATTENDANCE_H

#include "Performance.h"

struct ByAttendance {
    bool operator()(const Performance& a, const Performance& b) const;
};

#endif // BYATTENDANCE_H
