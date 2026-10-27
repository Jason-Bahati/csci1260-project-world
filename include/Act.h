#ifndef ACT_H
#define ACT_H
#include "SetList.h"
#include <vector>

class Act {
  public:
    Act(std::string name);
    virtual std::string Genre() const = 0;
    virtual int performerCount() const = 0;
    virtual std::string Describe() const = 0;

    std::string ToString();

    bool AddSong(std::string title, int minutes);
    int SetLength() const;
    std::string SetlistLines();

    std::string getName() const;
    int getSongCount() const;

    virtual ~Act() = default;

  private:
    std::string name;
    std::vector<SetList> setlist;
    int nextSeq;
};

#endif // ACT_H
