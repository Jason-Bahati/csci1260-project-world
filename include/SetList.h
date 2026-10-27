#ifndef SETLIST_H
#define SETLIST_H
#include <string>

class SetList {
  public:
    SetList(int seq, std::string title, int minutes);
    std::string Describe();

    int getSeq() const;
    std::string getTitle() const;
    int getMinutes() const;

  private:
    int seq;
    std::string title;
    int minutes;
};
#endif // SETLIST_H
