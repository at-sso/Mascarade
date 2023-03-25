#ifndef M_COINS_H
#define M_COINS_H

class COINS_FIX
{
private:
    static const int GC_MAX = 13;
    int MAIN_COINS;

public:
    COINS_FIX() : MAIN_COINS(6) {}

    // Modifies the GC value.
    int modCoins(int value)
    {
        if (value < 0 || value > GC_MAX)
        {
            throw std::invalid_argument("COINS_HANDLER: Invalid coin value.");
        }
        return MAIN_COINS = value;
    }

    // Returns the GC value.
    int getCoins()
    {
        return MAIN_COINS;
    }

    // Will add more GC.
    void addCoins(int amount)
    {
        if (MAIN_COINS + amount > GC_MAX)
        {
            throw std::overflow_error("COINS_HANDLER: Value over 13.");
        }
        MAIN_COINS += amount;
    }

    // Will remove GC.
    void delCoins(int amount)
    {
        if (MAIN_COINS - amount < 0)
        {
            throw std::underflow_error("COINS_HANDLER: Value under 0.");
        }
        MAIN_COINS -= amount;
    }

    // Verifies if the ply has x amount of coins.
    bool hasCoins(int amount)
    {
        return MAIN_COINS >= amount;
    }
};
COINS_FIX COINS_HANDLE;

#endif