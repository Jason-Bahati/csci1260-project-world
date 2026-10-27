#ifndef PERFORMANCE_H
#define PERFORMANCE_H

#include <string>

class Performance {
  public:
    Performance(std::string actName, std::string date, int attendance);

    bool operator==(const Performance& other) const;
    bool operator!=(const Performance& other) const;
    bool operator<(const Performance& other) const;
    int compareTo(const Performance& other) const;

    static Performance FromLine(std::string line);

    std::string ToString() const;

    std::string getActName() const;
    std::string getDate() const;
    int getAttendance() const;

  private:
    std::string actName;
    std::string date;
    int attendance;
};
#endif // PERFORMANCE_H

namespace std {
template <> struct hash<Performance> {
    size_t operator()(const Performance& p) const
    {
        size_t h1 = hash<string>()(p.getActName());
        size_t h2 = hash<string>()(p.getDate());
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};
} // namespace std
