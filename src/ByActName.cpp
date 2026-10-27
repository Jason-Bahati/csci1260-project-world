#include "ByActName.h"

bool ByActName::operator()(const Performance& a, const Performance& b) const
{
    int byName = a.getActName().compare(b.getActName());
    if (byName != 0)
        return byName < 0;

    return a.compareTo(b) < 0;
}
