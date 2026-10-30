#ifndef VENUE_H
#define VENUE_H
#include <string>
#include <vector>

#include "Act.h"

class Venue {
  public:
    Venue(std::string name, int capacity);

    bool Add(Act* act);
    Act* Find(std::string name);
    int TotalMinutes();
    void PrintReport();

    std::string getName() const;
    int getCapacity() const;
    int getCount() const;

  private:
    std::string name;
    int capacity;
    std::vector<Act*> acts;
};
#endif // VENUE_H
