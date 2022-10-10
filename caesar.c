#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // argc
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // convert a string to an int
    int number = atoi(argv[1]);
    if (number < 0 || (argv[1][0] < 48 || argv[1][0] > 57) || ((argv[1][1] < 48 || argv[1][1] > 57) && (argv[1][1] != '\0')))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // get the plaintext
    string text = get_string("plaintext:  ");
    // print cipher text
    printf("ciphertext: ");
    //print lenth
    int lenth = strlen(text);
    for (int i = 0; i < lenth; i++)
    {
        char letter = text[i];
        if ((letter >= 97 && letter <= 122))
        {
            // letter to 0
            letter = 97 + ((letter - 97) + number) % 26;
        }
        if (letter >= 65 && letter <= 90)
        {
            // letter to 0
            letter = 65 + ((letter - 65) + number) % 26;
        }
        printf("%c", letter);
    }
    printf("\n");
    return 0;
}