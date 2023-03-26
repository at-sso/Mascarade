#ifndef M_CARDS_H
#define M_CARDS_H

#include "m_players.h"

class DEFINE_CARDS
{
public:
    static const char *cardsArray(int i)
    {
        return CARDS_ARRAY[i];
    }

    static const char *randCardsGen()
    {
        return CARDS_ARRAY[funcRand.returnRandInt(0, 10)];
    }

private:
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