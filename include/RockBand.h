#ifndef ROCKBAND_H
#define ROCKBAND_H
#include "Band.h"
#include "IAmplified.h"

class RockBand : public Band, public IAmplified {
  public:
    RockBand(const std::string& name, int memberCount, int ampCount);

    int WattsRequired() const override;

    std::string rigDescribe() const override;

    int getAmpCount() const;

    std::string genre() const override;

    std::string describe() const override;

  private:
    int ampCount_;
};
#endif // ROCKBAND_H
