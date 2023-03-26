#ifndef M_PLAYERS_H
#define M_PLAYERS_H

static constexpr int __COIN_MAX = 13;
#include "m_coins.h"

class PLAYER_HANDLER
{
public:
    PLAYER_HANDLER(const std::string &playerName, size_t playerAge, size_t numPlayers)
        : PLY_NAME(playerName), PLY_AGE(playerAge), NUMOF_PLY(numPlayers)
    {
        if (numPlayers < 2 || numPlayers > __COIN_MAX)
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

    std::string getArray(const int &index) { return NAMES[index]; }

    std::string getNameGen(std::vector<std::string> &existingNames) { return generateNames(existingNames); }

    void getAgeGen(std::vector<int> &existingAge) { return generateAge(existingAge); }

    double getAge() { return PLY_AGE; }

    std::string getName() { return PLY_NAME; }

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
        : playerHandler(playerName, playerAge, numPlayers), coinsHandler() {}

    // Getters for player name and age
    const std::string getPlayerName() { return playerHandler.getName(); }
    const double getPlayerAge() { return playerHandler.getAge(); }

    // Coin handling methods
    const int getCoins() { return coinsHandler.getCoins(); }
    void addCoins(int amount) { coinsHandler.addCoins(amount); }
    void delCoins(int amount) { coinsHandler.delCoins(amount); }
    const bool hasCoins(int amount) { return coinsHandler.hasCoins(amount); }

private:
    PLAYER_HANDLER playerHandler;
    COINS_HANDLER coinsHandler;
};

#endif // M_PLAYERS_H