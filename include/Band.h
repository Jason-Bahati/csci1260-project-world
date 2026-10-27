#ifndef BAND_H
#define BAND_H
#include "Act.h"
#include <string>

class Band : public Act {
  public:
    Band(const std::string& name, int memberCount);

    int performerCount() const override;

    std::string Describe() const override;

    int getMemberCount() const;

  private:
    int memberCount_;
};
#endif // BAND_H
