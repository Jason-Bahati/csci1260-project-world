#ifndef JAZZBAND_H
#define JAZZBAND_H

#include "Band.h"

#include "Band.h"
#include <string>

class JazzBand : public Band {
  public:
    JazzBand(const std::string& name, int memeberCount,
             const std::string& leadInstrument);

    std::string getLeadInstrument() const;

    std::string genre() const override;
    std::string describe() const override;

  private:
    std::string leadInstrument_;
};

#endif // JAZZBAND_H
