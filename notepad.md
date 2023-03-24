The goal of the game is to be the first player to accumulate 13 gold coins or to be the only player left in the game.

At the start of the game, each player is dealt a character card face down, which they must keep secret from the other players.<br>
On their turn, a player can either look at their own character card or swap it with another player's card without looking at it.

Throughout the game, players will use their character's abilities to gain gold coins or steal them from other players.
However, due to the nature of the game, players will often claim to have a different character than the one they actually possess,
leading to confusion and deception.

At the end of each round, players will reveal their character cards, <br>
and any player who successfully guesses another player's card gains a gold coin. <br>
Additionally, some characters have special abilities that trigger at the end of the round. <br>

[Coding:]

Now, let's talk about how to code the game. The first step would be to create a data structure to represent the game state, which would include information such as the number of players, the number of gold coins each player has, and the identity of each player's character card.

Next, you would need to create a function to handle the swapping of character cards between players.
This function would take as input the player whose turn it is, the player they want to swap with,
and whether or not they want to look at the card they are swapping for. The function would then update the game state accordingly.

You would also need to create functions to handle the various character abilities. For example, the King character can take two gold
coins from the bank, while the Fool character can gain a gold coin by claiming to be a different character than they actually are.

Finally, you would need to create a function to handle the end of each round. This function would reveal all of the character cards
and update the game state accordingly, awarding gold coins to players who successfully guessed another player's card and triggering any special abilities.
