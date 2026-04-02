#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

bool is_empty(string text, int len);
int count_letters(string text, int len);
int count_words(string text, int len);
int count_sentences(string text, int len);
void print_result(int points);

int main(void)
{
    string text;
    int len;
    
    // Ask for input until it's not empty
    do
    {
        text = get_string("Text: ");
        len = strlen(text);
    }
    while (is_empty(text, len));

    // Count letters, words and sentences contained in given text
    int letters = count_letters(text, len);
    int words = count_words(text, len);
    int sentences = count_sentences(text, len);

    // Average number of letters per 100 words
    float L = ((float) letters / words) * 100;
    // Average number of sentences per 100 words 
    float S = ((float) sentences / words) * 100; 

    // Calculate result based on Coleman-Liau index
    float coleman_liau_index = 0.0588 * L - 0.296 * S - 15.8;

    print_result(round(coleman_liau_index));
}

// Check if input is empty or if it has only spaces
bool is_empty(string text, int len)
{
    if (len == 0)
        return 1;
    for (int i = 0; i < len; i++)
    {
        if (!isspace(text[i]))
            return 0;
    }
    return 1;
}

// Iterate inside string and check if char is a letter
int count_letters(string text, int len)
{
    int letters = 0;

    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
            letters++;
    }
    return letters;
}

// Iterate inside string and check if char is a space
int count_words(string text, int len)
{
    int words = 0;

    for (int i = 0; i < len; i++)
    {
        if (isspace(text[i]))
            words++;
    }
    return words + 1;
}

// Iterate and count periods, exclamation points and question marks
int count_sentences(string text, int len)
{
    int sentences = 0;

    for (int i = 0; i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            sentences++;
    }
    return sentences;
}

// Print result based on points calculated from Coleman-Liau index
void print_result(int points)
{
    if (points < 1)
        printf("Before Grade 1\n");
    else if (points > 16)
        printf("Grade 16+\n");
    else
        printf("Grade %d\n", points);
}
