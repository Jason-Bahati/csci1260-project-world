#ifndef SOUNDENGINEER_H
#define SOUNDENGINEER_H
#include "IAmplified.h"
#include <string>

class SoundEngineer {
  public:
    SoundEngineer(std::string name, int maxWatts);
    std::string Prepare(IAmplified& act);

    std::string getName() const;
    int getMaxWatts() const;

  private:
    std::string name;
    int maxWatts;
};

#endif // SOUNDENGINEER_H
