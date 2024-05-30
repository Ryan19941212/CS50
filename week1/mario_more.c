#include <cs50.h>
#include <stdio.h>

void print_row_left(int spaces, int bricks);
void print_row_right(int bricks);

int main(void)
{
    // prompt the user for the pyramid's height
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1);

    // print a pyramid of that height
    for (int i = 0; i < n; i++)
    {
        print_row_left(n - i - 1, i + 1);
        printf("  ");
        print_row_right(i + 1);
    }
}

void print_row_left(int spaces, int bricks)
{
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
}

void print_row_right(int bricks)
{
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }

    printf("\n");
}
