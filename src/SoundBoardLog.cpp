#include "SoundBoardLog.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

SoundBoardLog::SoundBoardLog(std::string path) : writer(path)
{
    if (!writer.is_open()) {
        throw std::runtime_error("could not open log file " + path);
    }

    this->path = path;
    writer << "LOG OPENED" << std::endl;
    count = 0;
    isClosed = false;
}

void SoundBoardLog::write(std::string message)
{
    if (!isClosed) {
        count++;
        writer << std::right << std::setw(3) << count << " " << message
               << std::endl;
    }
}

void SoundBoardLog::close()
{
    if (!isClosed) {
        writer << "LOG CLOSED, " << count << " lines written" << std::endl;

        writer.close();

        isClosed = true;
    }
}

SoundBoardLog::~SoundBoardLog()
{
    close();
}

std::string SoundBoardLog::getPath() const
{
    return path;
}
int SoundBoardLog::getCount() const
{
    return count;
}
bool SoundBoardLog::getIsClosed() const
{
    return isClosed;
}
