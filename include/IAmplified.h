#ifndef IAMPLIFIED_H
#define IAMPLIFIED_H
#include <string>

class IAmplified {
  public:
    virtual int WattsRequired() const = 0;

    virtual std::string rigDescribe() const = 0;

    virtual ~IAmplified() = default;
};

#endif
