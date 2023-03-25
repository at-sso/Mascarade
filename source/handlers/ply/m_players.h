#ifndef M_PLAYERS_H
#define M_PLAYERS_H

#include <random>
#include <string>
#include <algorithm>

class PLY_HANDLER
{
public:
#include "m_coins.h"

    PLY_HANDLER(const std::string &playerName, int playerAge, int numPlayers)
        : PLY_NAME(playerName), PLY_AGE(playerAge), NUMOF_PLY(numPlayers)
    {
        if (numPlayers < 2 || numPlayers > GC_MAX)
        {
            throw std::invalid_argument("PLY_HANDLER: Invalid number of players.");
        }

        std::vector<std::string> existingPlayers;
        std::vector<int> playersAge;
        existingPlayers.push_back(PLY_NAME);
        playersAge.push_back(PLY_AGE);

        for (int i = 1; i < numPlayers; i++)
        {
            std::string newName = generateNames(existingPlayers);
            generateAge(playersAge);
        }
    }

    std::string getNamesArray(int index)
    {
        return NAMES[index];
    }

    std::string getNamesGen(std::vector<std::string> &existingNames)
    {
        return generateNames(existingNames);
    }

    void getAgeGen(std::vector<int> &existingAge)
    {
        return generateAge(existingAge);
    }

private:
    static const int GC_MAX = 13;
    std::string PLY_NAME;
    double PLY_AGE;
    int NUMOF_PLY;

    std::vector<std::string> NAMES = {
        "Arvaela", "Sylvard", "Baeloria",
        "Zephyrin", "Quinleth", "Orynthea",
        "Xandrielle", "Kaelith", "Thalindor",
        "Vaelstryn", "Myryndor", "Ylvaine",
        "Rythandria", "Eryndelle", "Zaeloria",
        "Arinthea", "Lyvandria", "Orindale",
        "Faeloria", "Neryndor", "sso"};

    std::string generateNames(std::vector<std::string> &existingNames)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, NAMES.size() - 1);

        std::string newName;
        do
        {
            newName = NAMES[dis(gen)];
        } while (std::find(existingNames.begin(), existingNames.end(), newName) != existingNames.end());

        existingNames.push_back(newName);
        return newName;
    }

    void generateAge(std::vector<int> &existingAge)
    {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_real_distribution<double> dist(1.0, 20.0);
        existingAge.push_back(dist(mt));
    }
};

#endif // M_PLAYERS_H