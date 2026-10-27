#ifndef BYATTENDANCE_H
#define BYATTENDANCE_H

#include "Performance.h"

// Comparer: biggest crowd first. Ties fall back to the natural order.
struct ByAttendance {
    bool operator()(const Performance& a, const Performance& b) const;
};

#endif // BYATTENDANCE_H
