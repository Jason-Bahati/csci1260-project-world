#ifndef IAMPLIFIED_H
#define IAMPLIFIED_H

class IAmplified {
   public:
    virtual int WattsRequired() const = 0;

    virtual ~IAmplified() = default;
};

#endif
