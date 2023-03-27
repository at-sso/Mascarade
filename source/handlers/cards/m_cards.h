#ifndef M_CARDS_H
#define M_CARDS_H

#include <cstring>

static constexpr int CARD_MAX = 11;

class DEFINE_CARDS
{
public:
    static const char *const *cardsArray()
    {
        return CARDS_ARRAY;
    }

    static const char *cardsArrayAt(int index)
    {
        return CARDS_ARRAY[index];
    }

    static const char *randCardsGen()
    {
        return CARDS_ARRAY[funcRand.returnRandInt(0, 10)];
    }

    static const int verifyCards(const char *_char, int &_int)
    {
        for (int j = 0; j < CARD_MAX; j++)
        {
            if (strcmp(_char, cardsArrayAt(j)) == 0)
            {
                _int = j;
                break;
            }
        }
        return _int;
    }

private:
    static constexpr const char *CARDS_ARRAY[CARD_MAX] = {
        "Spy", "Bishop", "Fool", "Inquisitor",
        "Judge", "Peasant", "Queen", "King",
        "Witch", "Cheat", "Widow"};
};
DEFINE_CARDS defCards;

class EX_TYPE
{
public:
    static void charMustBe(const char *_char, const int &index)
    {
        if (strcmp(_char, DEFINE_CARDS::cardsArrayAt(index)) != 0)
        {
            throw std::logic_error("charMustBe: Prohibited char.");
        }
    }

    static void prohibitedAt(int &_int, const int &exception)
    {
        if (_int == exception)
        {
            throw std::out_of_range("prohibitedAt: Integer value is prohibited.");
        }
    }
};

#include "m_cards_mechs.h"

class CARDS_HANDLER
{
public:
    void ACTION_SWITCH(const char *ID)
    {
        int i = -1;
        defCards.verifyCards(ID, i);
        EX_TYPE::prohibitedAt(i, -1);

        switch (i)
        {
        case 0:
            break;

        default:
            throw std::overflow_error("ACTION_SWITCH: Value is over the case specified.");
        }
    }
};

#endif