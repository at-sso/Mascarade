#ifndef M_PLAYERS_H
#define M_PLAYERS_H

static constexpr int COIN_MAX = 13;
#include "m_coins.h"

class PLAYER_HANDLER
{
public:
    PLAYER_HANDLER(const std::string &playerName, size_t playerAge, size_t numPlayers)
        : PLY_NAME(playerName), PLY_AGE(playerAge), NUMOF_PLY(numPlayers)
    {
        if (numPlayers < 2 || numPlayers > COIN_MAX)
        {
            throw std::invalid_argument("PLAYER_HANDLER: Invalid number of players.");
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

    std::string getArray(const int &index)
    {
        return NAMES[index];
    }

    std::string getNameGen(std::vector<std::string> &existingNames)
    {
        return generateNames(existingNames);
    }

    void getAgeGen(std::vector<int> &existingAge)
    {
        return generateAge(existingAge);
    }

    double getAge()
    {
        return PLY_AGE;
    }

    std::string getName()
    {
        return PLY_NAME;
    }

private:
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
        std::string newName;
        do
        {
            newName = NAMES[funcRand.returnRandInt(0, NAMES.size() - 1)];
        } while (std::find(existingNames.begin(), existingNames.end(), newName) != existingNames.end());

        existingNames.push_back(newName);
        return newName;
    }

    void generateAge(std::vector<int> &existingAge) { existingAge.push_back(funcRand.returnRandInt(1, 20)); }
};

class DEFINE_PLAYERS
{
public:
    DEFINE_PLAYERS(const std::string &playerName, size_t playerAge, size_t numPlayers)
        : ply_h(playerName, playerAge, numPlayers), coin_h() {}

    const std::string getPlayerName()
    {
        return ply_h.getName();
    }

    const double getPlayerAge()
    {
        return ply_h.getAge();
    }

    const int getCoins()
    {
        return coin_h.getCoins();
    }

    void addCoins(int amount)
    {
        coin_h.addCoins(amount);
    }

    void delCoins(int amount)
    {
        coin_h.delCoins(amount);
    }

    const bool hasCoins(int amount)
    {
        return coin_h.hasCoins(amount);
    }

private:
    PLAYER_HANDLER ply_h;
    COINS_HANDLER coin_h;
};

#endif // M_PLAYERS_H