#include "DJ.h"

#include <stdexcept>

namespace {
const int WATTS_PER_DECK = 300;
const int MONITOR_WATTS = 1500;
} // namespace

DJ::DJ(std::string name, std::string genre, int deckCount)
    : Act(name), genre(genre), deckCount(deckCount)
{
    if (genre.empty()) {
        throw std::invalid_argument("A DJ must have a genre: " + name);
    }
    if (deckCount < 1 || deckCount > 4) {
        throw std::invalid_argument("A DJ uses 1 to 4 decks, not " +
                                    std::to_string(deckCount) + ": " + name);
    }
}

int DJ::getDeckCount() const
{
    return deckCount;
}

std::string DJ::Genre() const
{
    return genre;
}

int DJ::performerCount() const
{
    return 1;
}

int DJ::WattsRequired() const
{
    return MONITOR_WATTS + deckCount * WATTS_PER_DECK;
}

std::string DJ::rigDescribe() const
{
    return getName() + ": " + std::to_string(deckCount) +
           " decks, mixer, booth monitors";
}

std::string DJ::Describe() const
{

    return Act::Describe() + " | " + std::to_string(deckCount) + " decks";
}
