#ifndef DJ_H
#define DJ_H

#include "Act.h"
#include "IAmplified.h"
#include <string>

class DJ : public Act, public IAmplified {
  private:
    std::string genre_;
    int deckCount_;

  public:
    DJ(const std::string& name, const std::string& genre, int deckCount);

    int getDeckCount() const;

    std::string genre() const override;
    int performerCount() const override;

    int WattsRequired() const override;
    std::string rigDescribe() const override;

    std::string describe() const override;
};

#endif // DJ_H
