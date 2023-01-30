/*
Ana and Bogdan invented a new game, which they named Strips. It is a strategy game, but also a memory training game, because it is played on a board that is not visible to the two players during the game.
The game board is a white strip of length N cm, on which positions of length 1 cm are marked. The positions are numbered on the board from 0 to N-1, with position 0 being marked at the beginning of the board (left end) and position N-1 being marked at the end of the board (right end).
At the beginning of the game each player has Nr colored strips, all of the same length L cm. Ana's stripes are red, and Bogdan's stripes are green.
Players move alternately, with Ana being the first to move. On a move, the player whose turn it is chooses a position on the game board and if the position is valid, a strip of that player will be placed on the game board, with the left end in the chosen position. If the position is not valid, the move will not be executed and that player will receive 1 penalty point and lose the lane that should have been placed on the board at that position (it is removed from the game).
A position is considered valid if a tape of length L can be placed on the game board with the left end of the tape fixed at the specified position, so that the tape is integral to the game board without overlapping or touching an area on the lane colored in the opponent's color.
The game ends when players run out of lanes. Each player aims to obtain an area on the tape of the greatest length colored in his color. An area on the tape is made up of consecutive positions, colored with the same color.
Requirement

Write a program that reads the length of the game board, the number of colored strips each player has at the start of the game, the length of the strips, and the positions specified by the players during the game, and solves the following two requirements:

     determine the number of penalty points for each of the two players;
     determines for each player what is the maximum length of an area on the game board colored in his color at the end of the game.

Input data

The input file strips.in contains on the first line a natural number C that represents the requirement to be solved (1 or 2). On the second line there are three natural numbers separated by a space N No L, with the meaning in the statement. The other lines of the input file contain in order the positions specified by the players during the game, one position per line.
Output data

The output file strips.out will contain a single line on which two natural numbers rezA rezB will be written, separated by a single space. If C=1 then rezA is the number of penalty points accumulated by Ana, and rezB the number of penalty points accumulated by Bogdan. If C=2 then rezA is the maximum length of a red zone at the end of the game, and rezB is the maximum length of a green zone at the end of the game.
Restrictions and clarifications

     1 ≤ N ≤ 1,000,000,000
     1 ≤ No ≤ 50,000
     1 ≤ L ≤ 20,000
     It is guaranteed that for the test data, at the end of the game, for each of the two players the number of disjoint areas on the game board colored in that player's color is ≤ 5000.
     Positions are natural numbers smaller than N.
     Since they are beginners, Ana and Bogdan still do not play optimally.
     For tests worth 50 points, the requirement is 1.
     For tests worth 40 points 1 ≤ N ≤ 1,000,000, 1 ≤ L ≤ 1000 and 1 ≤ Nr ≤ 1000.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define MAXN 1000000000
#define MAXL 20000
#define MAXNO 50000
#define MAXC 2


int main()
{
    int N, No, L, C;
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int rezA, rezB;
    int A[MAXNO], B[MAXNO];

    FILE *fin = fopen("strips.in", "r");
    FILE *fout = fopen("strips.out", "w");

    fscanf(fin, "%d", &C);
    fscanf(fin, "%d %d %d", &N, &No, &L);

    for (i = 0; i < No; i++)
    {
        fscanf(fin, "%d", &A[i]);
        B[i] = A[i] + L - 1;
    }

    if (C == 1)
    {
        rezA = 0;
        rezB = 0;
        for (i = 0; i < No; i++)
        {
            for (j = 0; j < No; j++)
            {
                if (i != j)
                {
                    if (A[i] >= A[j] && A[i] <= B[j])
                    {
                        rezA++;
                        break;
                    }
                    if (B[i] >= A[j] && B[i] <= B[j])
                    {
                        rezA++;
                        break;
                    }
                }
            }
        }
        for (i = 0; i < No; i++)
        {
            for (j = 0; j < No; j++)
            {
                if (i != j)
                {
                    if (A[i] >= A[j] && A[i] <= B[j])
                    {
                        rezB++;
                        break;
                    }
                    if (B[i] >= A[j] && B[i] <= B[j])
                    {
                        rezB++;
                        break;
                    }
                }
            }
        }
    }
    else
    {
        rezA = 0;
        rezB = 0;
        for (i = 0; i < No; i++)
        {
            for (j = 0; j < No; j++)
            {
                if (i != j)
                {
                    if (A[i] >= A[j] && A[i] <= B[j])
                    {
                        rezA++;
                        break;
                    }
                    if (B[i] >= A[j] && B[i] <= B[j])
                    {
                        rezA++;
                        break;
                    }
                }
            }
        }
        for (i = 0; i < No; i++)
        {
            for (j = 0; j < No; j++)
            {
                if (i != j)
                {
                    if (A[i] >= A[j] && A[i] <= B[j])
                    {
                        rezB++;
                        break;
                    }
                    if (B[i] >= A[j] && B[i] <= B[j])
                    {
                        rezB++;
                        break;
                    }
                }
            }
        }
    }

    fprintf(fout, "%d %d", rezA, rezB);

    return 0;
}