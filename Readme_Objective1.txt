# Game Code Explanation

Explaining the logic and flow of the provided C program that creates a small console game.

1. What the Game Does

This is a simple 3-lane runner game in the console.

* The player stays at the bottom of the screen.
* An obstacle falls from the top.
* The player moves left or right using arrow keys.
* If the player is in the same lane as the obstacle when it reaches the bottom, the game ends.

The game also plays background sound and an impact sound when the player loses.

2. Important Header Files Used

#include <stdio.h>

For printing the game on screen using printf().

#include <conio.h>

For keyboard input using _kbhit() and getch().

include <windows.h>

Used for:

* cursor movement (to reduce flicker)
* Sleep() to slow down the game
* console color.

#include <mmsystem.h>

Used for PlaySound() to play background and impact audio.

#include <time.h>

Used to generate random obstacle positions using rand().

3. How Flicker Is Reduced

SetConsoleCursorPosition()

This moves the cursor to the top-left corner, so the screen updates fast and smoothly.

4. How Player Movement Works

The player can be in lanes:

0 = Left
1 = Middle
2 = Right

When you press arrow keys:

* Left arrow → move x--
* Right arrow → move x++

_kbhit() checks if any key was pressed.
getch() reads the key.

5. How the Obstacle Works

The obstacle:

* starts at a random lane (rand() % 3)
* moves down one row every frame
* when it reaches below the screen, it resets again at the top

This is controlled by:

* step → vertical position (row number)
* obstaclePos → lane number

6. Game Display (Drawing)

The screen is drawn every frame:

1. A top border
2. 10 rows for the falling obstacle
3. The player row at the bottom

If the current row matches step, the obstacle is printed in its lane.

If not, an empty line is printed.

Finally, the player is printed on the last line based on the lane x.

7. Collision Detection

Collision happens when:

step == 10  AND  player lane == obstacle lane

This means:

* the obstacle reached the bottom
* the player is in the same lane
  → the game ends

The program stops the background sound and plays the impact sound before showing "GAME OVER".

8. Game Loop

The entire game runs inside a while(1) loop.

Inside the loop:

1. Take input
2. Draw screen
3. Check collision
4. Move the obstacle down
5. Repeat

This keeps the game running continuously until a collision occurs.

9. Use of Random Numbers

rand() % 3 gives values 0, 1 or 2.
This randomly decides which lane the obstacle appears in.

srand(time(0)) ensures different random values every time the game starts.

10. Sounds Used

* PlaySound("bg.wav", ..., SND_LOOP) → background looping music
* PlaySound("impact.wav", ..., SND_ASYNC) → plays on collision

Both .wav files must be in the same folder as the program.

11. Overall Logic Summary

* Game starts → Player is in the middle lane
* Obstacle falls → moves down each frame
* Player moves left/right
* If obstacle reaches bottom and player is in same lane → Game Over
* Otherwise → obstacle resets and game continues

The code is simple, uses loops, conditions, random numbers, and Windows console functions.

