#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    // Counts the number of arguements in the command line
    if (argc == 2)
    {
        // Get key from User
        // Converts index 1 of argv to an int part of standlibrary.h 
        const int KEY = atoi(argv[1]);
        // Stores a boolean to use as an off switch if we dectect a bad input
        bool isKeyValid = true;
        // Stores the length of the the string in index 1 of the argv array
        int len = strlen(argv[1]);
        // Loop that checks each digit to see if it's a number
        for (int i = 0; i < len; i++)
        {
            // If isdigit detects a non-digit it'll set our stored bool to false and end the loop, part of ctype.h libary
            if (isdigit(argv[1][i]) == false)
            {
                isKeyValid = false;
                //Setting i = len breaks us out of the for loop
                i = len;
            }
        }
        // If the loop successfully finishes and the isKeyValid bool stays true then we have a valid key and can proceed
        if (isKeyValid)
        {
            //plaintext is our variable to store the input from the user
            //plaintextlength is the length of the inpur from the user
            string plaintext = get_string("plaintext: ");
            int plaintextLength = strlen(plaintext);
            //for loop to go through the user input plaintext
            for (int i = 0; i < plaintextLength; i++)
            {
                // check to see if upper or lower case using isupper from ctype.h library
                if (isupper(plaintext[i]))
                {
                    if (plaintext[i] + KEY >  'Z')
                    {
                        //keyRemainder stores the wrap around math we need to do when the Key is greater than Z on the Asccii table. Otherwise we would get symbols or lower case letters for upper case letters.
                        int keyRemainder = (plaintext[i] + KEY) - 'Z';
                        //Using Ascii math from the table provided where Z = 90 and A = 65 would return 25 
                        if (keyRemainder > 'Z' - 'A')
                        {
                            while (keyRemainder >= ('Z' - 'A'))
                            // Keep subtracking until we get a number inside the correct Asscii chart
                            {
                                keyRemainder = keyRemainder - ('Z' - 'A');
                            }


                            if (plaintext[i] + keyRemainder > 'Z')
                            {
                                keyRemainder = plaintext[i] + keyRemainder - 'Z';
                                //now we have a keyRemainder that is between the right Ascii decimal range to map to upper case letters -- which is 65 = A and 90 = Z
                                //Make sure to - 1 because we are starting at zero and would miss A
                                plaintext[i] = 'A' + keyRemainder - 1;
                            }
                               // Here KeyReminder is the in right range for us to convert the plaintext letter to the correct Cipher text letter.
                            else
                            {
                                plaintext[i] = 'a' + keyRemainder - 1;
                            }
                        }
                        else
                        // where our keyreminder was never larger the Z to begin with.
                        {
                            plaintext[i] = 'A' + keyRemainder - 1;

                        }
                    }
                    // this is the simplest case were the letter itself can just be added the Key to give us our encyrpted letter.
                    else if (plaintext[i] + KEY <= 'Z')
                    {
                        plaintext[i] = plaintext[i] + KEY;
                    }
                }
                // Now we repeat the logic above but for lower case letters.
                if (islower(plaintext[i]))
                {
                    if (plaintext[i] + KEY >  'z')
                    {
                        // Takes the value of our selected letter and adds total steps then subtracts 'z' to take it down a whole rotation of the letters
                        int keyRemainder = (plaintext[i] + KEY) - ('z');
                        // Checks to see if the left over amount of steps is still greater than the value of the entire length of the alphabet
                        if (keyRemainder >= 'z' - 'a')
                        {
                            // While the keyRemainder is greater than 25 we continue this loop
                            while (keyRemainder >= ('z' - 'a'))
                            {
                                // Each iteration subtracts 26 "length of the alphabet" from the total
                                keyRemainder = keyRemainder - (26);
                            }

                            // If the initial letter value + the new remainder is still greater than z, we do one last wrap a round by taking the difference and adding it to the value of 'a'.
                            if (plaintext[i] + keyRemainder > 'z')
                            {
                                keyRemainder = plaintext[i] + keyRemainder - 'z';
                                plaintext[i] = 'a' + keyRemainder - 1;
                            }
                            // If the keyRemainder + the initial letter value is not greater than 'z' than we take the initial letter value and add the number of steps left in the keyRemainder
                            else
                            {
                                plaintext[i] = 'a' + keyRemainder - 1;
                            }
                        }
                        else
                        {
                                plaintext[i] = 'a' + keyRemainder - 1;
                        }
                    }
                    else if (plaintext[i] + KEY <= 'z')
                    {
                        plaintext[i] = plaintext[i] + KEY;
                    }
                }
            }


            printf("ciphertext: %s\n", plaintext);
        }
        // If we detected an unusable key we ask the user for proper key
        else
        {
            printf("Usage: ./caesar key\n");
            printf("1");
            return (1);
        }

    }
    // If too many arguements were entered then we ask for a proper key
    else if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        printf("1");
        return (1);
    }

}