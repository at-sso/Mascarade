#ifndef M_CARDS_H
#define M_CARDS_H

#include "m_players.h"

class DEFINE_CARDS
{
public:
    std::string generateCard()
    {
        std::string card;
        switch (cardIndex)
        {
        case 0:
            return card = CARDS_ARRAY[0];
        case 1:
            return card = CARDS_ARRAY[1];
        case 2:
            return card = CARDS_ARRAY[2];
        case 3:
            return card = CARDS_ARRAY[3];
        case 4:
            return card = CARDS_ARRAY[4];
        case 5:
            return card = CARDS_ARRAY[5];
        case 6:
            return card = CARDS_ARRAY[6];
        case 7:
            return card = CARDS_ARRAY[7];
        case 8:
            return card = CARDS_ARRAY[8];
        case 9:
            return card = CARDS_ARRAY[9];
        case 10:
            return card = CARDS_ARRAY[10];
        }
    }

    static const char *cardsArray(int i)
    {
        return CARDS_ARRAY[i];
    }

private:
    int cardIndex = funcRand.returnRandInt(0, 11);

    static constexpr const char *CARDS_ARRAY[11] = {
        "Spy", "Bishop", "Fool", "Inquisitor",
        "Judge", "Peasant", "Queen", "King",
        "Witch", "Cheat", "Widow"};
};

class CARD_HANDLER
{
public:
    CARD_HANDLER() {}
    ~CARD_HANDLER() {}

    // Card distribution mechanic.
    void GIVE_CARDS()
    {
    }

    // Card swapping mechanic.
    void SWAP_CARDS()
    {
    }

    // Reveal all cards mechanic.
    void SHOWALL_CARDS()
    {
    }

    // Card trading mechanic.
    void TRADE_CARDS()
    {
    }

    // Coin stealing mechanic.
    void STEAL_COIN()
    {
    }

    // Coin gaining mechanic.
    void OBTAIN_GC()
    {
    }

    // Coin losing mechanic.
    void LOSE_GC()
    {
    }

private:
};

#endif