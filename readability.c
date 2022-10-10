#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    // printf("letters: %i\n", letters);
    int words = count_words(text);
    // printf("Words: %i\n", words);
    int sentences = count_sentences(text);
    // printf("Sentences: %i\n", sentences);

    //calculating
    float L = (letters / (float)words) * 100;
    // printf("%.2f\n", L);
    float S = (sentences / (float)words) * 100;
    //printf("%.2f\n", S);
    float coleman_liau_index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = (int)round(coleman_liau_index);
    if (grade < 1)
    {
        //priny
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        //print
        printf("Grade 16+\n");

    }
    else
    {
        // print
        printf("Grade %i\n", grade);
    }

}

int count_letters(string text)
{
    int lenth = strlen(text);
    int total_words = 0;
    for (int i = 0; i < lenth; i++)
    {
        // getting char
        char letter = text[i];
        if ((letter >= 65 && letter <= 90) || (letter >= 97 && letter <= 122))
        {
            total_words += 1;
        }

    }
    return total_words;

}
int count_words(string text)
{
    // get lenth
    int lenth = strlen(text);
    int total_words = 0;
    for (int i = 0; i < lenth; i++)
    {
        if (text[i] == 32)
        {
            total_words += 1;
        }
    }
    return total_words + 1;

}
int count_sentences(string text)
{
    // get lenth
    int lenth = strlen(text);
    int total_sentences = 0;
    for (int i = 0; i < lenth; i++)
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            //get total
            total_sentences += 1;
        }
    }
    return total_sentences;
}

