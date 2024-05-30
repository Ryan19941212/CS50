#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompt users for x
    int x = get_int("x: ");

    //Prompt users y
    int y = get_int("y: ");

    //Divide x by y
    float z = (float) x /(float) y;

    //perform addition
    printf("%.50f\n", z);
}