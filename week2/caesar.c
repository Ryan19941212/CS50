#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Make sure every character in argv[1] is a digit
    else if (argc == 2)
    {
        for (int i = 0, len = strlen(argv[1]); i < len; i++)
            if (isdigit(argv[1][i]) == 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
    }
    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string plain_text = get_string("plaintext:  ");

    // For each character in the plaintext:
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plain_text); i < len; i++)
    {
        // Rotate the character if it's a letter
        if (isdigit(plain_text[i]) == 0)
        {
            if (isupper(plain_text[i]))
            {
                printf("%c", 'A' + ((plain_text[i] + key) - 'A') % 26);
            }
            else if (islower(plain_text[i]))
            {
                printf("%c", 'a' + ((plain_text[i] + key) - 'a') % 26);
            }
            else
            {
                printf("%c", plain_text[i]);
            }
        }
    }
    printf("\n");
}
