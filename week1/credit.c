#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get card number
    long n;
    do
    {
        n = get_long("Number: ");
    }
    while (n < 1);

    // count length
    int i = 0;
    long length = n;
    while (length > 0)
    {
        length = length / 10;
        i++;
    }

    // check length
    if (i != 13 && i != 15 && i != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // calculate checksum
    int sum1 = 0;
    int sum2 = 0;
    int total = 0;
    long x = n;
    int mod1;
    int mod2;
    int d1;
    int d2;

    while (x > 0)
    {
        // remove odd digits and add to sum1
        mod1 = x % 10;
        x = x / 10;
        sum1 = sum1 + mod1;

        // remove even digits and double mod and add digits to sum2
        mod2 = x % 10;
        x = x / 10;
        mod2 = mod2 * 2;
        d1 = mod2 % 10;
        d2 = mod2 / 10;
        sum2 = sum2 + d1 + d2;
    }
    total = sum1 + sum2;

    // next check luhn algorithm
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Get starting digits
    long start = n;
    do
    {
        start = start / 10;
    }
    while (start > 100);

    // Next check starting digits for card type
    if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
    else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7) && (i == 15))
    {
        printf("AMEX\n");
    }
    else if ((start / 10 == 4) && (i == 13 || i == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
