#ifndef BYACTNAME_H
#define BYACTNAME_H

#include "Performance.h"

// Comparer: alphabetical by act name. Each act's shows fall back to the natural
// order (by date).
struct ByActName {
    bool operator()(const Performance& a, const Performance& b) const;
};

#endif // BYACTNAME_H
