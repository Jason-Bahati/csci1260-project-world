#ifndef ROCKBAND_H
#define ROCKBAND_H
#include "Band.h"
#include "IAmplified.h"

class RockBand : public Band, public IAmplified {
  public:
    RockBand(std::string name, int memberCount, int ampCount);

    int WattsRequired() const override;

    std::string rigDescribe() const override;

    int getAmpCount() const;

    std::string Genre() const override;

    std::string Describe() const override;

  private:
    int ampCount;
};
#endif // ROCKBAND_H
