#ifndef MASC_PLAYERS_H
#define MASC_PLAYERS_H

#include <stdexcept>
#include <string>
#include <map>
#include <algorithm>
#include <random>

class PLY_HANDLER
{
public:
    // Constructor
    PLY_HANDLER(const std::string &playerName, int numPlayers) : coins_h(), PLY_NAME(playerName)
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

private:
    static const int GC_MAX = 13;
    std::string PLY_NAME;
    std::vector<std::string> NAMES = {"Arvaela", "Sylvard", ".sso",
                                      "Zephyrin", "Quinleth", "Orynthea",
                                      "Xandrielle", "Kaelith", "Thalindor",
                                      "Vaelstryn", "Myryndor", "Ylvaine",
                                      "Rythandria", "Eryndelle", "Zaeloria",
                                      "Arinthea", "Lyvandria", "Orindale",
                                      "Faeloria", "Neryndor", "Baeloria"};
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

    class COINS_HANDLER
    {
    public:
        COINS_HANDLER() : GOLDEN_COINS(6)
        {
        }

        // Modifies the GC value.
        int modCoins(int value)
        {
            if (value < 0 || value > GC_MAX)
            {
                throw std::invalid_argument("COINS_HANDLER: Invalid coin value.");
            }
            return GOLDEN_COINS = value;
        }

        // Returns the GC value.
        int getCoins()
        {
            return GOLDEN_COINS;
        }

        // Will add more GC.
        void addCoins(int amount)
        {
            if (GOLDEN_COINS + amount > GC_MAX)
            {
                throw std::overflow_error("COINS_HANDLER: Value over 13.");
            }
            GOLDEN_COINS += amount;
        }

        // Will remove GC.
        void delCoins(int amount)
        {
            if (GOLDEN_COINS - amount < 0)
            {
                throw std::underflow_error("COINS_HANDLER: Value under 0.");
            }
            GOLDEN_COINS -= amount;
        }

        // Verifies if the ply has x amount of coins.
        bool hasCoins(int amount)
        {
            return GOLDEN_COINS >= amount;
        }

    private:
        // Private member variables
        int GOLDEN_COINS;
    };
    COINS_HANDLER coins_h;
};

#endif // MASC_PLAYERS_H