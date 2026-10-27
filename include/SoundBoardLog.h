#ifndef SOUNDBOARDLOG_H
#define SOUNDBOARDLOG_H
#include <fstream>
#include <string>

class SoundBoardLog {
  public:
    SoundBoardLog(std::string path);
    SoundBoardLog(const SoundBoardLog&) = delete;
    SoundBoardLog& operator=(const SoundBoardLog&) = delete;

    void write(std::string message);
    void close();

    std::string getPath() const;
    int getCount() const;
    bool getIsClosed() const;

    ~SoundBoardLog();

  private:
    std::string path;
    std::ofstream writer;
    int count;
    bool isClosed;
};
#endif // SOUNDBOARDLOG_H
