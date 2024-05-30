#include <cs50.h>
#include <stdio.h>

int main(void)
{
    const int MINE = 2
    int points = get_int("How many points did you lose?");

    if (points < MINE)
    {
        printf("You lose fewer points than me.\n");
    }
    else if (points > MINE)
    {
        printf("You lose more points than me.\n");
    }
    else
    {
        printf("You lose the same number points as me.\n");
    }
}
