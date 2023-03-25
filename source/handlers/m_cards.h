#ifndef M_CARDS_H
#define M_CARDS_H

#include "m_players.h"

class CARD_HANDLER
{
public:
    CARD_HANDLER() {}
    ~CARD_HANDLER() {}

    // Card swapping mechanic.
    void SWAP_CARDS(PLY_HANDLER &ply1, PLY_HANDLER &ply2)
    {
    }

    // Reveal all cards mechanic.
    void SHOWALL_CARDS(PLY_HANDLER &ply)
    {
    }

    // Card trading mechanic.
    void TRADE_CARDS(PLY_HANDLER &ply1, PLY_HANDLER &ply2)
    {
    }

    // Coin stealing mechanic.
    void STEAL_COIN(PLY_HANDLER &ply1, PLY_HANDLER &ply2, int amount)
    {
    }

    // Coin gaining mechanic.
    void OBTAIN_GC(PLY_HANDLER &ply, int amount)
    {
    }

    // Coin losing mechanic.
    void LOSE_GC(PLY_HANDLER &ply, int amount)
    {
    }

private:
};

#endif