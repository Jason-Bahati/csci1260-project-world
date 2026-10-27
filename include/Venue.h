#ifndef VENUE_H
#define VENUE_H
#include <string>
#include <vector>

#include "Act.h"

class Venue {
  private:
    std::string name;
    int capacity;
    std::vector<Act*> acts;

  public:
    Venue(std::string name, int capacity);

    bool Add(Act* act);
    Act* Find(std::string name);
    int TotalMinutes();
    void PrintReport();

    std::string getName() const;
    int getCapacity() const;
    int getCount() const;
};
#endif // VENUE_H
