#ifndef ACT_H
#define ACT_H
#include "SetList.h"
#include <vector>

class Act {
  public:
    Act(const std::string& name);
    virtual std::string genre() const = 0;
    virtual int performerCount() const = 0;

    virtual std::string describe() const;
    void addSong(const std::string& title, int minute);
    int setLengthMinutes() const;
    std::string setListSummary() const;

    std::string getName();

    virtual ~Act() = default;

  private:
    std::string name_;
    std::vector<SetList> list;
};

#endif // ACT_H
