#ifndef VENUE_H
#define VENUE_H
#include <string>
#include <vector>

#include "Act.h"

class Venue {
   private:
    std::string venueName;
    std::vector<std::shared_ptr<Act>> acts;

   public:
    Venue();

    std::string getVenuName() const { return venueName; }

    bool doubleBook();

    int add();
};
#endif  // VENUE_H
