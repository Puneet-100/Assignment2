#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand((unsigned)time(NULL));

    int x = 1;                   // 0 = left, 1 = mid, 2 = right
    int step = 0;                // vertical position of obstacle (0..9)
    int obstaclePos = rand() % 3;
    int score = 0;
    int speed = 120;             // milliseconds for Sleep()

    while (1) {

        // ---- INPUT (handle extended keys properly) ----
        if (_kbhit()) {
            int ch = getch();            // use int to catch -1/extended prefix
            if (ch == 0 || ch == 224)   // extended key prefix for arrows
                ch = getch();

            if (ch == 75 && x > 0)      // LEFT arrow
                x--;
            else if (ch == 77 && x < 2) // RIGHT arrow
                x++;
            else if (ch == 'q' || ch == 'Q') { // allow quitting
                system("cls");
                printf("Quit. Final score: %d\n", score);
                break;
            }
        }

        // ---- COLLISION CHECK (just before drawing the player row) ----
        if (step == 9 && x == obstaclePos) {
            system("cls");
            printf("|--- --- ---|\n");
            for (int i = 0; i < 10; i++) printf("|           |\n");
            printf("|     A     |\n\n"); // show player at center for clarity
            printf("GAME OVER! Score: %d\n", score);
            break;
        }

        // ---- DRAW ----
        system("cls");
        printf("|--- --- ---|    Score: %d\n", score);

        for (int i = 0; i < 10; i++) {
            if (i == step) {
                if (obstaclePos == 0)      printf("| X         |\n");
                else if (obstaclePos == 1) printf("|     X     |\n");
                else                       printf("|         X |\n");
            }
            else {
                printf("|           |\n");
            }
        }

        // ---- PLAYER ----
        if (x == 0)      printf("| A         |\n");
        else if (x == 1) printf("|     A     |\n");
        else             printf("|         A |\n");

        // ---- FRAME PAUSE ----
        Sleep(speed);

        // Move obstacle down
        step++;

        // Reset when reaches bottom
        if (step > 9) {
            step = 0;
            obstaclePos = rand() % 3; // new lane
            score++;

            // optionally increase speed as score grows (capped)
            if (score % 5 == 0 && speed > 30) speed -= 8;
        }
    }
return 0;
}
