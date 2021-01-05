# Blackjack (NOT FINISHED)
In casino blackjack, a dealer has a deck of cards, each of which has a *value*.
The possible card values are 2 through 10, Jack, Queen, King, and Ace. Additionally,
each value has a blackjack-specific *point-value*, which is defined as follows:
* For number cards (i.e. 2 through 10), the point-value is the same as the card value
* For face cards (Jack, Queen, King), the point-value is 10
* For Aces, the point-value can be **either 1 or 11**, decided by the player.

The goal of the game is for the player's cards to have a total point-value which is as
close to 21 points as possible, *without exceeding 21*. 

You are given a "deck of cards," represented as an array of chars. All cards are
represented as their corresponding char symbol, except for 10, which is represented
as a '0'. For this problem, we generalize reaching 21 points to being able to 
reach any generic number of points. Determine the total number of ways a player can select
cards from the deck to reach exactly `k` points.

As an example, suppose the deck is ['A', 'J', '4', '0', '5', '4', '7', '3'].
There are 12 ways to reach k = 21 points, shown below:
* 'A', 'J'
* 'A', '0'
* 'A', '7', '3'
* 'A', 'J', '0'
* 'J', '7', '4'
* '0', '7', '4' (we count this one twice, since there are two '4' cards)
* 'A', '0', '7', '3'
* 'A', 'J', '7', '3'
* 'J', '4', '4', '3'
* '0', '4', '4', '3'
* 'A', '4', '4', '5', '7'