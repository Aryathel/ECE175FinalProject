- Begin multi-game loop (play games until user quits) {
  - Get player name
  - Print game introduction
  - Create deck
  - Shuffle deck
  - Set starting coin value to 100
  - Begin single-game loop (runs until player runs out of coins) {
    - If the number of cards is less than or equal to 21 {
      - Discard remainder of old deck
      - Create new deck
      - Shuffle new deck
    }
    - Deal two hands
    - Print hands (computer with last two cards hidden)
    - Ask player for bet
    - Ask player to hold certain cards
    - Make computer move based on its cards
    - Check the scores of the hands and compare
    - Adjust coins based on result of round
    - if coins is 0 {
      - Print that the player loses the game, break the single-game loop
    } else {
      - start the next round
    }
  }
  - ask if the user wants to play again
}
