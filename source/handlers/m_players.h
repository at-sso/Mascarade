#ifndef M_PLAYERS_H
#define M_PLAYERS_H

#include <random>
#include <string>
#include <map>
#include <algorithm>

class PLY_HANDLER
{
public:
    PLY_HANDLER(const std::string &playerName, int numPlayers) : COINS_HANDLE(), PLY_NAME(playerName), NUMOF_PLY(numPlayers)
    {
        if (numPlayers < 2 || numPlayers > GC_MAX)
        {
            throw std::invalid_argument("PLY_HANDLER: Invalid number of players.");
        }

        // Generate names for all players
        std::vector<std::string> existingPlayers;
        existingPlayers.push_back(PLY_NAME);
        for (int i = 1; i < numPlayers; i++)
        {
            std::string newName = generateNames(existingPlayers);
            existingPlayers.push_back(newName);
        }
    }

#include "m_coins.h"

private:
    static const int GC_MAX = 13;
    std::string PLY_NAME;
    int NUMOF_PLY;

    std::vector<std::string> NAMES = {
        "Arvaela", "Sylvard", "Baeloria",
        "Zephyrin", "Quinleth", "Orynthea",
        "Xandrielle", "Kaelith", "Thalindor",
        "Vaelstryn", "Myryndor", "Ylvaine",
        "Rythandria", "Eryndelle", "Zaeloria",
        "Arinthea", "Lyvandria", "Orindale",
        "Faeloria", "Neryndor", "sso"};
    std::string generateNames(const std::vector<std::string> &existingNames)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, NAMES.size() - 1);

        while (true)
        {
            std::string newName = NAMES[dis(gen)];
            if (std::find(existingNames.begin(), existingNames.end(), newName) == existingNames.end())
            {
                return newName;
            }
        }
    }
    std::map<std::string, bool> ANSWER_MAP = {
        {"y", true},
        {"n", false},
    };
};

#endif // M_PLAYERS_H