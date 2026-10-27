#ifndef BYACTNAME_H
#define BYACTNAME_H

#include "Performance.h"

struct ByActName {
    bool operator()(const Performance& a, const Performance& b) const;
};

#endif // BYACTNAME_H
