/* ***********
readability Program
Wolfgang Westphal
March 19 20201

This program will use the  Coleman-Liau index to assign a grade level to a text passage. It does so by counting the number of letters, words and sentences then applying
this formula: index = 0.0588 * L - 0.296 * S - 15.8.

From Wikipedia: 
The Coleman–Liau index is calculated with the following formula:
CLI = 0.0588 * L - 0.296 * S - 15.8
L is the average number of letters per 100 words and S is the average number of sentences per 100 words.
************* */ 

// https://www.tutorialspoint.com/c_standard_library/stdio_h.htm 
// The stdio.h header defines three variable types, several macros, and various functions for performing input and output. We wwill use this to capture stdin / stdout to the user
#include <stdio.h>

// https://github.com/cs50/libcs50/blob/develop/src/cs50.h
// Allows us to use the cs50.io site to develop our c code programs
#include <cs50.h>

// https://www.tutorialspoint.com/c_standard_library/ctype_h.htm
// This librairy helps us to determine the types of the characters we are accpeting on Stdin. Functions like isspace, isalpha etc are critical for us to count the letters
// words and sentencenes
#include <ctype.h>

// https://www.tutorialspoint.com/c_standard_library/string_h.htm
// We are accepting a long string variable as the text so we need this library. 
#include <string.h>


// Variables to capture number of letters, Words, and sentences count
int letters;
int words;
int sentences;


int main(void)
{

// prompt the user to get the text to evalute the reading level.

    string text = get_string("What's the text to determine the grade level using the Coleman–Liau index ?: ");

// set the length of text.

    int n = strlen(text);

// add +1 if the text starts with alphanumeric letter. ctype function. 

    if (isalnum(text[0]))
    {
        words = 1;
    }

// count words.

    for (int i = 0; i < n;  i++)
    {
        // count letters.

        if (isalnum(text[i]))
        {
            letters++;
        }

        // count words by counting / finding the spaces between. 

        if (i < n - 1 && isspace(text[i]) && isalnum(text[i + 1]))
        {
            words++;
        }

        // count sentences looking for periods, question marks and exclamtion points. || is the OR logic. && is the And logic.

        if (i > 0 && (text[i] == '!' || text[i] == '?' || text[i] == '.') && isalnum(text[i - 1]))
        {
            sentences++;
        }

    }

// calculate Coleman-Liau index by declaring grade variable  and applying the formula above. By make grade an Int variable the float is automatically cast to int
// so grade 4.553 = 5
;
    int grade = 0.0588 * (100 * letters / words) - 0.296 * (100 * sentences / words) - 15.8

// Print out the Letters, Words, Sentences to show what the variables were to determine the grade.

    printf("\n Letters: %i\n Words: %i\n Sentences: %i\n\n", letters, words, sentences);

// print the grade
// grade is between lower than grade 1 -- i.e. "Hi Mom!"
    if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }
// use formula to determine grade between 1 and 16
    else if (grade < 16)
    {
        printf("Grade %i\n", grade);
    }
// otherwise the grade is higher the grade 16. 
    else
    {
        printf("Grade 16+\n");
    }
}