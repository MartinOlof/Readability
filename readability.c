#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    // Ask user for a text
    string text = get_string("Text: ");

    int letters = 0;
    int sentences = 0;
    int words = 1;

    // Set text to lowercase
    for (int i = 0; text[i]; i++)
    {
        text[i] = tolower(text[i]);
    }

    // Loop to count letters, words and sentences
    for (int i = 0; text[i]; i++)
    {
        // Use ASCII to check how many letters from a - z
        if (text[i] >= 97 && text[i] <= 122)
        {
            letters++;
        }
        // Counts the amount of spaces + 1
        else if (text[i] == 32)
        {
            words++;
        }
        //Checks for different kinds of punctuation
        else if (text[i] == 33 || text[i] == 63 || text[i] == 46)
        {
            sentences++;
        }
    }

    // Counts the averages for the letters and sentences according to the Coleman-Liau index
    float letterAvg = (letters / (float) words) * 100;
    float sentenceAvg = (sentences / (float) words) * 100;

    // Coleman-Liau Index
    float index = 0.0588 * letterAvg - 0.296 * sentenceAvg - 15.8;

    // Checks what value it is
    if (index < 16 && index >= 1)
    {
        printf("Grade %i\n", (int) round(index));
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }

}
