#ifndef M_CARDS_MECHS_H
#define M_CARDS_MECHS_H

class CARDS_MECHANICS
{
public:
    // Initialize the deck with the default order
    CARDS_MECHANICS() : deck(defCards.cardsArray(), defCards.cardsArray() + CARD_MAX) {}

    // Shuffle the deck
    void shuffleDeck()
    {
        std::random_shuffle(deck.begin(), deck.end());
    }

    // Peek at a card at the top of the deck
    const char *peekTopCard()
    {
        return deck.front();
    }

    // Remove and return the top card from the deck
    const char *dealTopCard()
    {
        const char *topCard = deck.front();
        deck.erase(deck.begin());
        return topCard;
    }

    // Swap the positions of two cards in the deck
    void swapCards(int index1, int index2)
    {
        std::swap(deck[index1], deck[index2]);
    }

    // Print the cards in the deck
    void printDeck()
    {
        printf("Deck: ");
        for (const auto &card : deck)
        {
            printf(card);
        }
    }

private:
    std::vector<const char *> deck;
};

#endif