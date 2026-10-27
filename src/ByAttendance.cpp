#include "ByAttendance.h"

bool ByAttendance::operator()(const Performance& a, const Performance& b) const
{
    if (a.getAttendance() != b.getAttendance())
        return a.getAttendance() > b.getAttendance();
    return a.compareTo(b) < 0;
}
