//
// Created by modco on 2/17/2023.
//

#include <stdio.h>
#include <string.h>

#define SAFETY 2
#define FG 3
#define TD 6
#define TD1 7
#define TD2 8

void scorePermutations(int score)
{
    for (int safety = 0; safety <= score / SAFETY; safety++)
    {
        for (int fg = 0; fg <= score / FG; fg++)
        {
            for (int td2 = 0; td2 <= score / TD2; td2++)
            {
                for (int td1 = 0; td1 <= score / TD1; td1++)
                {
                    for (int td = 0; td <= score / TD; td++)
                    {
                        if (safety*SAFETY + fg*FG + td*TD + td1*TD1 + td2*TD2 == score)
                        {
                            printf("%d safeties, %d field goals, %d touchdowns, %d touchdowns + FG, %d touchdowns + 2pt\n", safety, fg, td, td1, td2);
                        }
                    }
                }
            }
        }
    }
}

// the main function will prompt the user for an NFL score. If the score is <= 1, the program terminates, otherwise the
// program will display all possible combinations of scoring plays that result in that score.
int main() {
    int running = 1;
    while (running)
    {
        printf("Enter an NFL score: ");
        int score;
        scanf("%d", &score);
        if (score <= 1)
        {
            printf("Program terminated.\n");
            return 0;
        }
        else
        {
            scorePermutations(score);
        }
    }
}