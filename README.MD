# OVERVIEW

This is a project created for our Electrical and Computer Engineering 175 course in our freshman year of college.
The premise of the assignment was to create the game "Jacks or Better" in a command line interface using C.
The results are shown below. If you want to try out the game for yourself, look for the instructions below.

# ROUGH OUTLINE OF HOW THE CODE PROGRESSES

- Begin multi-game loop (play games until user quits)
  - Get player name
  - Print game introduction
  - Create deck
  - Shuffle deck
  - Set starting coin value to 100
  - Begin single-game loop (runs until player runs out of coins)
    - If the number of cards is less than or equal to 21
      - Discard remainder of old deck
      - Create new deck
      - Shuffle new deck
    - Deal two hands
    - Print hands (computer with last two cards hidden)
    - Ask player for bet
    - Ask player to hold certain cards
    - Make computer move based on its cards
    - Check the scores of the hands and compare
    - Adjust coins based on result of round
    - if coins is 0
      - Print that the player loses the game, break the single-game loop
    - else
      - start the next round
  - ask if the user wants to play again

# INSTRUCTIONS TO PLAY THIS YOURSELF

_**Note:**_ *These instructions are in order to enable your command line interface to properly display the ASCII characters used for things like the suits of the cards and the borders of the cards.*

1. Download the [main.exe](https://github.com/HeroicosHM/ECE175FinalProject/raw/master/main.exe) file on a windows device.
2. Double click this file.
3. In the command line interface that opens, before starting to play the game, right click anywhere in the white bar at the top.
4. Select "Properties", then select the "Font" tab at the top.
5. In the "Font" box, scroll down and select the "Raster Fonts" option.
6. Click "OK" at the bottom.
7. Enjoy the game!

# TO-DO LIST

- [x] Add Graphics to game
- [x] Make the computer actually play the game
- [ ] Add a two-player mode
- [ ] Add game statistics that record over time
- [x] Add an in-depth tie-breaking system.

# PARTICIPANTS
- [Heroicos_HM](https://github.com/HeroicosHM)
- [Alpha](https://github.com/CamAlpha)
