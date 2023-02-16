## Compilation and Running
```
1. Clone the repository: $ git clone https://github.com/Sameeer12/rock-paper-scissor.git
2. cd rock-paper-scissor
3. use g++ rps.cpp Log.cpp -o game --std=c++14 && ./game'\ to run the program  
4. Enter the user input.
```

## Algorithm
1. The computer will choose a random choice between "Rock", "Paper" and "Scissor". Logic -- We will generate a random number between 0-2; such that for      each  there is a choice such that Rock = 0 --> Computer will choose Rock, Paper = 1 --> Computer will choose Paper, Scissors = 2 --> Computer will          choose Scissor.
2. User Input will be taken mapped accordingly.
3. Input will be compared with computers choice.
4. According to rules, one of them will win.

## Rules:
A player who decides to play rock will beat another player who has chosen scissors ("rock crushes scissors" or sometimes "blunts scissors"), but will lose to one who has played paper ("paper covers rock"); a play of paper will lose to a play of scissors ("scissors cuts paper"). If both players choose the same shape, the game is tied.


