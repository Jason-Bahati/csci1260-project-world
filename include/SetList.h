#ifndef SETLIST_H
#define SETLIST_H
#include <string>

class SetList {
  public:
    SetList(const std::string& title, int minutes);

    std::string toString() const;

    std::string getTitle() const;
    int getMinute() const;

  private:
    std::string title_;
    int minutes_;
};
#endif // SETLIST_H
