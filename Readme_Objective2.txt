Console Lane Runner Game (C Project)
This project is a simple console-based lane-runner game.
The player controls a character A that can move between three lanes (left, middle, right) using the arrow keys.
Obstacles (X) fall from the top, and the player must avoid them.
If the obstacle reaches the bottom row and the player is in the same lane, the game ends.

This version includes improvements from the basic/original code.

Features Added / Modifications Explained
1. Score Counter

Added a score variable:

int score = 0;

Every time the obstacle reaches the bottom and resets, the score increases:

score++;

The score is displayed at the top of the console:

printf("|--- --- ---|    Score: %d\n", score);

2. Increasing Game Speed Over Time (Difficulty Increase)

To make the game more challenging, I added a speed variable:

int speed = 120;

Every 5 points of score, the game becomes slightly faster:

if (score % 5 == 0 && speed > 30)
    speed -= 8;

This reduces the sleep time, making obstacles fall quicker.

3. Quit Option Added (Q Key)

The game can now be exited anytime by pressing Q or q:

if (ch == 'q' || ch == 'Q') {
    printf("Quit. Final score: %d\n", score);
    break;
}

This helps during testing or if the player wants to stop.