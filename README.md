# Mascarade

### **Made by Ian Hylton, aka. sso**

This is a Java program for a card game called "Mascarade". The game involves players taking turns where each player can either choose to swap their card with another card or announce a card they have. The other players can then choose to protest the announcement or not. The game ends when a player wins by meeting a specific condition, such as having 10 or more gold coins.

The program consists of three classes: ***Main***, ***Card***, and ***Player***.

The ***Card*** class represents a card in the game. It has two fields: name and attribute. Name represents the name of the card and attribute represents the description of the card.

The ***Player*** class represents a player in the game. It has three fields: name, selectedCard, and cards. Name represents the name of the player, selectedCard represents the card selected by the player, and cards is an array of three cards that the player has. The Player class also has methods to set and get the selected card, look at the selected card, and check if the player has won the game.

The ***Main*** class represents the game itself. It has methods to shuffle the cards, deal the cards to players, exchange cards between players, and announce cards. The main method of the Main class is where the game logic is implemented. It prompts the user for the number of players and their names, shuffles the cards, deals the cards to players, and starts the game loop. In the game loop, each player takes a turn, and the game ends when a player wins or when the user chooses to quit the game.

Overall, this program provides a basic implementation of the "Mascarade" card game in Java. The code is well-organized and easy to read, making it a good starting point for anyone interested in developing their own card game in Java.
