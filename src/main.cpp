#include "AllHeaderFiles.h"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_set>
#include <vector>

// CMake passes in the full paths, so the files are found from any folder.
#ifndef DATA_FILE
#define DATA_FILE "data.txt"
#endif
#ifndef LOG_FILE
#define LOG_FILE "soundboard_log.txt"
#endif

std::string tf(bool b)
{
    return b ? "True" : "False";
}

int main()
{
    // Load the past performances first. Section 4 needs them. Each bad line is
    // caught, its message is saved for section 5, and loading carries on with
    // the next line.
    std::vector<Performance> records;
    std::vector<std::string> loadErrors;
    int lineNumber = 0;

    std::ifstream data(DATA_FILE);
    if (!data.is_open()) {
        loadErrors.push_back("could not open data.txt");
    }

    std::string line;
    while (std::getline(data, line)) {
        if (!line.empty() && line[line.size() - 1] == '\r') {
            line.erase(line.size() - 1); // Windows line endings
        }
        if (line.empty()) {
            continue;
        }
        lineNumber++;

        try {
            records.push_back(Performance::FromLine(line));
        }
        catch (std::invalid_argument& ex) {
            loadErrors.push_back("line " + std::to_string(lineNumber) +
                                 " skipped, " + ex.what() + ": " + line);
        }
    }

    std::cout << "=== 1. Classes, UML, and Relationships ===" << std::endl;

    Venue venue("The Echo Room", 2000);

    RockBand* midnightStatic = new RockBand("Midnight Static", 4, 3);
    RockBand* velvetRiot = new RockBand("Velvet Riot", 5, 4);
    JazzBand* blueHour = new JazzBand("Blue Hour Quintet", 5, "trumpet");
    DJ* djLumen = new DJ("DJ Lumen", "House", 2);

    midnightStatic->AddSong("Smoke Signals", 4);
    midnightStatic->AddSong("Overdrive", 5);
    midnightStatic->AddSong("Static Bloom", 6);
    velvetRiot->AddSong("Glass Jaw", 3);
    velvetRiot->AddSong("Neon Funeral", 5);
    blueHour->AddSong("Late Train", 8);
    blueHour->AddSong("Rain on Fourth Street", 11);
    djLumen->AddSong("Opening Mix", 25);
    djLumen->AddSong("Peak Hour Mix", 35);

    if (!velvetRiot->AddSong("Endless Jam", 90)) {
        std::cout << " REJECTED: a 90 minute song for Velvet Riot" << std::endl;
    }

    std::vector<Act*> lineup;
    lineup.push_back(midnightStatic);
    lineup.push_back(velvetRiot);
    lineup.push_back(blueHour);
    lineup.push_back(djLumen);

    for (int i = 0; i < static_cast<int>(lineup.size()); i++) {
        venue.Add(lineup[i]);
    }

    if (!venue.Add(blueHour)) {
        std::cout << " REJECTED: Blue Hour Quintet is already booked"
                  << std::endl;
    }
    std::cout << std::endl;

    venue.PrintReport();
    std::cout << std::endl;

    std::cout << "Composition check" << std::endl;
    std::cout << " " << std::left << std::setw(46)
              << "Songs Midnight Static built and owns:"
              << " " << std::right << std::setw(11)
              << midnightStatic->getSongCount() << std::endl;
    std::cout << midnightStatic->SetlistLines() << std::endl;
    std::cout << std::endl;

    std::cout << "Aggregation check" << std::endl;
    {
        Venue popUp("Rooftop Pop-Up", 300);
        popUp.Add(djLumen);
        std::cout << " " << std::left << std::setw(46)
                  << "Acts booked at the Rooftop Pop-Up:"
                  << " " << std::right << std::setw(11) << popUp.getCount()
                  << std::endl;
    } // popUp is destroyed here, but the act it held is not
    std::cout << " After the pop-up closed: " << djLumen->ToString()
              << std::endl;
    std::cout << std::endl;

    std::cout << "=== 2. Inheritance and Abstraction ===" << std::endl;

    // Act bad("Nobody");   // object of abstract class type "Act" is not
    // allowed Band band("Nobody", 3); // object of abstract class type "Band"
    // is not allowed

    std::cout << " RockBand -> Band -> Act" << std::endl;
    std::cout << "    " << midnightStatic->Describe() << std::endl;
    std::cout << " JazzBand -> Band -> Act" << std::endl;
    std::cout << "    " << blueHour->Describe() << std::endl;
    std::cout << " DJ -> Act" << std::endl;
    std::cout << "    " << djLumen->Describe() << std::endl;
    std::cout << std::endl;

    std::cout << "=== 3. Polymorphism and Interfaces ===" << std::endl;

    std::cout << " Every act, one loop, no type tests:" << std::endl;
    for (int i = 0; i < static_cast<int>(lineup.size()); i++) {
        std::cout << "    " << lineup[i]->Describe() << std::endl;
    }
    std::cout << std::endl;

    SoundEngineer rosa("Rosa", 4000);
    int signedCount = 0;

    std::cout << " Sound check:" << std::endl;
    for (int i = 0; i < static_cast<int>(lineup.size()); i++) {
        IAmplified* amp;
        amp = dynamic_cast<IAmplified*>(lineup[i]);

        if (amp != nullptr) {
            std::cout << "    " << rosa.Prepare(*amp) << std::endl;
            signedCount++;
        }
        else {
            std::cout << "    " << lineup[i]->getName()
                      << " plays acoustic, no PA needed" << std::endl;
        }
    }
    std::cout << " " << std::left << std::setw(46) << "Acts signing IAmplified:"
              << " " << std::right << std::setw(11) << signedCount << std::endl;
    std::cout << std::endl;

    std::cout << "=== 4. Built in Contracts and Collections ===" << std::endl;

    Performance first("Midnight Static", "2026-09-05", 1450);
    Performance corrected("Midnight Static", "2026-09-05", 1460);
    Performance other("Velvet Riot", "2026-09-05", 1450);

    std::cout << "Contract 1: Equals and GetHashCode" << std::endl;
    std::cout << " " << std::left << std::setw(50)
              << "Same act and date, new attendance, equal?" << std::right
              << std::setw(6) << tf(first == corrected) << std::endl;

    std::cout << " " << std::left << std::setw(50)
              << "Same date and attendance, different act, equal?" << std::right
              << std::setw(6) << tf(first == other) << std::endl;

    std::cout << " " << std::left << std::setw(50)
              << "Equal records report equal hash codes?" << std::right
              << std::setw(6)
              << tf(std::hash<Performance>()(first) ==
                    std::hash<Performance>()(corrected))
              << std::endl;

    std::unordered_set<Performance> recordSet;
    for (int i = 0; i < static_cast<int>(records.size()); i++) {
        recordSet.insert(records[i]);
    }
    std::vector<Performance> distinct(recordSet.begin(), recordSet.end());

    std::cout << " " << std::left << std::setw(50)
              << "Records loaded from data.txt:" << std::right << std::setw(6)
              << records.size() << std::endl;
    std::cout << " " << std::left << std::setw(50)
              << "Distinct records in the set:" << std::right << std::setw(6)
              << recordSet.size() << std::endl;
    std::cout << std::endl;

    std::cout << "Contract 2: CompareTo, the natural order (date, then act)"
              << std::endl;
    std::sort(distinct.begin(), distinct.end());
    for (int i = 0; i < static_cast<int>(distinct.size()); i++) {
        std::cout << "  " << distinct[i].ToString() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Contract 3: a comparer, chosen at the call site" << std::endl;
    std::cout << "  ByAttendance" << std::endl;
    std::sort(distinct.begin(), distinct.end(), ByAttendance());
    for (int i = 0; i < static_cast<int>(distinct.size()); i++) {
        std::cout << "    " << distinct[i].ToString() << std::endl;
    }

    std::cout << "  ByActName" << std::endl;
    std::sort(distinct.begin(), distinct.end(), ByActName());
    for (int i = 0; i < static_cast<int>(distinct.size()); i++) {
        std::cout << "    " << distinct[i].ToString() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== 5. Exceptions and Files ===" << std::endl;

    std::cout << " " << std::left << std::setw(50)
              << "Lines read from data.txt:" << std::right << std::setw(6)
              << lineNumber << std::endl;
    std::cout << " " << std::left << std::setw(50)
              << "Lines loaded:" << std::right << std::setw(6) << records.size()
              << std::endl;
    for (int i = 0; i < static_cast<int>(loadErrors.size()); i++) {
        std::cout << "    " << loadErrors[i] << std::endl;
    }
    std::cout << std::endl;

    try {
        RockBand loneWolf("Lone Wolf", 1, 2);
    }
    catch (std::invalid_argument& ex) {
        std::cout << " Caught: " << ex.what() << std::endl;
    }

    try {
        DJ tooManyDecks("DJ Overload", "Techno", 7);
    }
    catch (std::invalid_argument& ex) {
        std::cout << " Caught: " << ex.what() << std::endl;
    }
    std::cout << std::endl;

    // Closing twice must be safe. Try it on a sound check log first.
    bool safeTwice = true;
    {
        SoundBoardLog check(LOG_FILE);
        check.write("sound check");
        try {
            check.close();
            check.close();
        }
        catch (...) {
            safeTwice = false;
        }
    }

    // The show log lives inside the braces of the try block, which is C++'s
    // using block. The throw leaves the block, the destructor runs, and close()
    // writes the last line.
    int linesBeforeFault = 0;
    try {
        SoundBoardLog log(LOG_FILE);
        log.write("doors open at " + venue.getName());
        for (int i = 0; i < static_cast<int>(lineup.size()); i++) {
            log.write(lineup[i]->getName() + " on stage");
        }
        linesBeforeFault = log.getCount();
        throw std::runtime_error("power surge on stage circuit 2");
    }
    catch (std::runtime_error& ex) {
        std::cout << " Caught: " << ex.what() << std::endl;
    }

    std::vector<std::string> logLines;
    std::ifstream in(LOG_FILE);
    while (std::getline(in, line)) {
        logLines.push_back(line);
    }
    bool closedItself =
        !logLines.empty() &&
        logLines[logLines.size() - 1].compare(0, 10, "LOG CLOSED") == 0;

    std::cout << " " << std::left << std::setw(50) << "The log closed itself?"
              << std::right << std::setw(6) << tf(closedItself) << std::endl;
    std::cout << " " << std::left << std::setw(50)
              << "Closing it a second time was safe?" << std::right
              << std::setw(6) << tf(safeTwice) << std::endl;
    std::cout << " " << std::left << std::setw(50)
              << "Lines the log wrote before the fault:" << std::right
              << std::setw(6) << linesBeforeFault << std::endl;

    std::cout << " soundboard_log.txt now says:" << std::endl;
    for (int i = 0; i < static_cast<int>(logLines.size()); i++) {
        std::cout << "    " << logLines[i] << std::endl;
    }

    // main created the acts, so main deletes them. The venue never owned them.
    for (int i = 0; i < static_cast<int>(lineup.size()); i++) {
        delete lineup[i];
    }

    return 0;
}
