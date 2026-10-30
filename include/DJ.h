#ifndef DJ_H
#define DJ_H

#include "Act.h"
#include "IAmplified.h"
#include <string>

class DJ : public Act, public IAmplified {
  public:
    DJ(std::string name, std::string genre, int deckCount);

    int getDeckCount() const;

    std::string Genre() const override;
    int performerCount() const override;

    int WattsRequired() const override;
    std::string rigDescribe() const override;

    std::string Describe() const override;

  private:
    std::string genre;
    int deckCount;
};

#endif // DJ_H
