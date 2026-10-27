#ifndef JAZZBAND_H
#define JAZZBAND_H

#include "Band.h"
#include <string>

class JazzBand : public Band {
  public:
    JazzBand(std::string name, int memberCount, std::string leadInstrument);

    std::string getLeadInstrument() const;

    std::string Genre() const override;
    std::string Describe() const override;

  private:
    std::string leadInstrument;
};

#endif // JAZZBAND_H
