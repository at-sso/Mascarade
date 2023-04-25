import java.util.Scanner;
import java.util.Random;

public class Main {
    public static Scanner scanner = new Scanner(System.in);
    public String name;
    public String attribute;

    public Main(String name, String attribute) {
        this.name = name;
        this.attribute = attribute;
    }

    private static class Functions {
        public void ExchangeCards(int player, Card[] cards) {
            System.out.println("Do you want to change your card? (yes or no)");
            String decision = scanner.next();
            if (decision.equals("yes")) {
                System.out.println("Which card do you want to swap? (Enter card number 1-3)");
                int cardIndex1 = scanner.nextInt() - 1;
                System.out.println("Which card do you want to swap it with? (Enter card number 1-3)");
                int cardIndex2 = scanner.nextInt() - 1;

                // Check if the card indices are valid.
                if (cardIndex1 < 0 || cardIndex1 > 2 || cardIndex2 < 0 || cardIndex2 > 2) {
                    System.out.println("Invalid card number entered. Please try again.");
                    return;
                }

                // Swap the cards.
                Card temp = cards[cardIndex1];
                cards[cardIndex1] = cards[cardIndex2];
                cards[cardIndex2] = temp;

                System.out.println("Cards swapped successfully!");
            } else if (decision.equals("no")) {
                System.out.println("You have chosen not to change your card.");
            }
        }

        public void AnnounceCards(Card card, String playerName, boolean isProtesting) {
            System.out.println(playerName + ", what card do you want to announce?");
            String cardName = scanner.nextLine();
            if (card.getName().equalsIgnoreCase(cardName)) {
                System.out.println(playerName + " has announced the correct card: " + card.getName() + " ("
                        + card.getAttribute() + ")");
            } else if (isProtesting) {
                System.out.println("The card announced by " + playerName + " was incorrect!");
            } else {
                System.out.println(playerName + " has activated their power!");
            }
        }
    } // Functions

    public static Functions fromFunctions = new Functions();

    // MAIN START
    public static void main(String[] args) {
        new Main("Mascarade", "A bluffing card game");

        Card[] cards = {
                new Card("Judge", "The Judge takes all the coins (fines) placed on the Palace of Justice."),
                new Card("Bishop", "The Bishop takes two gold coins from the richest player."),
                new Card("King", "The King gets three gold coins from the Bank."),
                new Card("Queen", "The Queen gets two gold coins from the Bank"),
                new Card("Witch", "The Witch can exchange all her fortune with another player of her choice."),
                new Card("Gambler", "If the Gambler has 10 gold coins or more, he wins the game.")
        };

        int decision;
        boolean TerminateLoop = false;

        while (!TerminateLoop) {
            System.out.println("1. Play game");
            System.out.println("2. Quit");
            decision = scanner.nextInt();
            switch (decision) {
                case 1: {
                    // Shuffle the cards.
                    Card[] shuffledCards = shuffle(cards);

                    // Initialize the players.
                    System.out.println("How many players are there?");
                    int numPlayers = scanner.nextInt();
                    Player[] players = new Player[numPlayers];
                    for (int i = 0; i < numPlayers; i++) {
                        System.out.println("Enter the name of player " + (i + 1) + ":");
                        String playerName = scanner.next();
                        players[i] = new Player(playerName);
                    }

                    // Deal the cards to the players.
                    dealCards(players, shuffledCards);

                    // Each player takes a turn.
                    int currentPlayer = 0;
                    while (true) {
                        Player player = players[currentPlayer];
                        System.out.println("It's " + player.getName() + "'s turn.");
                        player.LookCards();
                        fromFunctions.ExchangeCards(currentPlayer, player.getCards());
                        player.LookCards();

                        // Each player can choose to announce a card or protest another player's
                        // announcement
                        for (int i = 0; i < players.length; i++) {
                            if (i != currentPlayer) {
                                Player otherPlayer = players[i];
                                boolean isProtesting = false;

                                System.out.println(otherPlayer.getName() + " announces a card.");

                                // Each player has the option to protest another player's announcement.
                                for (int j = 0; j < players.length; j++) {
                                    if (j != i) {
                                        Player protestor = players[j];
                                        fromFunctions.AnnounceCards(otherPlayer.getSelectedCard(), protestor.getName(),
                                                true);
                                        isProtesting = true;
                                    }
                                }

                                if (!isProtesting) {
                                    fromFunctions.AnnounceCards(otherPlayer.getSelectedCard(), otherPlayer.getName(),
                                            false);
                                }
                            }
                        }

                        // Check if any player has won.
                        boolean isGameOver = false;
                        for (Player p : players) {
                            if (p.hasWon()) {
                                System.out.println(p.getName() + " has won the game!");
                                isGameOver = true;
                            }
                        }
                        if (isGameOver) {
                            TerminateLoop = true;
                        }

                        // Move on to the next player.
                        currentPlayer = (currentPlayer + 1) % numPlayers;
                    }
                } // case 1
                case 2: {
                    TerminateLoop = true;
                } // case 2
                    break;
                default: {
                    System.out.println("Invalid input. Please try again.");
                }
            } // Switch {...} case.
        } // While loop.
    } // Main ends.

    public static Card[] shuffle(Card[] cards) {
        Random rand = new Random();
        for (int i = 0; i < cards.length; i++) {
            int randomIndexToSwap = rand.nextInt(cards.length);
            Card temp = cards[randomIndexToSwap];
            cards[randomIndexToSwap] = cards[i];
            cards[i] = temp;
        }
        return cards;
    }

    public static void dealCards(Player[] players, Card[] shuffledCards) {
        for (Player player : players) {
            player.setSelectedCard(shuffledCards[0]);
            shuffledCards = removeCard(shuffledCards, 0);
        }
    }

    public static Card[] removeCard(Card[] cards, int index) {
        Card[] newCards = new Card[cards.length - 1];
        for (int i = 0, k = 0; i < cards.length; i++) {
            if (i == index) {
                continue;
            }
            newCards[k++] = cards[i];
        }
        return newCards;
    }
}

// CARDS MECHANIC
class Card {
    private String name;
    private String attribute;

    public Card(String name, String attribute) {
        this.name = name;
        this.attribute = attribute;
    }

    public String getName() {
        return name;
    }

    public String getAttribute() {
        return attribute;
    }
}

// PLAYERS MECHANIC
class Player {
    private String name;
    private Card selectedCard;
    private Card[] cards;

    public Player(String name) {
        this.name = name;
        this.cards = new Card[3];
    }

    public String getName() {
        return name;
    }

    public void setSelectedCard(Card card) {
        selectedCard = card;
    }

    public Card getSelectedCard() {
        return selectedCard;
    }

    public Card[] getCards() {
        return cards;
    }

    public void LookCards() {
        System.out.println("Your card is " + selectedCard.getName() + ". This card has the following attribute: "
                + selectedCard.getAttribute());
    }

    public boolean hasWon() {
        if (selectedCard.getName().equals("Gambler") && Main.scanner.nextInt() >= 10) {
            return true;
        }
        return false;
    }
}
