/******************************************************************************
 * File:    enigma_proj.c
 * Author:  Jake Klinger, Jose (Pillo) Duenas-Lopez, Tyler (T-Dawg) Bruno
 * Version: 0.15 (Mar 18, 2023)

 * Purpose:
 *          A nifty program that encrypts and decrypts messages. This branch
 *          replicates the early analog function of the Enigma machine.
 *
 * To Do List:
 *          *Please read the website by theguardian cited in the references*
 *          []Create a three rotor device with each rotor containing 26 positi-
 *              ons
 *          []Create a switch board function
 *          []Create a decryption method
 *          []Fine tune
 *
 * Notes:
 *          °Currently creating a three rotor device with each rotor equipped
 *          with 26 positions for each letter of the alphabet
 *
 * References:
 *          °https://www.theguardian.com/technology/2014/nov/14/how-did-enigma-machine-work-imitation-game
 *          °https://www.educative.io/answers/how-to-remove-spaces-from-a-string-in-c
 *
 *
 *****************************************************************************/

#include <stdio.h>
//basic i/o functions

#include <string.h>
//strlen function

#include <ctype.h>


//Function to Encrypt message
void string_formatter( char *message);

int main( void )
{
    char message[100];
    //var to get user message

    printf("Message:\n");
    scanf("%[^\n]", &*message);
    //gets user message (had to do the weird %[^\n] thing, because C would stop
    //reading in user input after the first space, when the %s alias was used)

    string_formatter(message);

    printf("Formatted Message:\n%s", message);

    return 0;
}


//Function to format user message: reformats users message to remove all spaces
//numbers and special characters, and to change all lowercase letters uppercase
//. Although this limits the capabilities of the program, it mimics the original
//enigma machine, and makes the program easier to code
void string_formatter(char *message)
{
    int new_total_index = 0;
    //var used to reformat string array, whatever value assigned after the for
    //loop will be the new total number of indices in the string array


    //Removes spaces from user string
    for(int i = 0; message[i] != '\0'; i++)
    {
        if (message[i] != ' ')
        {
            message[new_total_index] = message[i];
            new_total_index++;
        }
    }
    message[new_total_index] = '\0';
    //appends null character to end of reformated string


    //Removes numbers from user string
    new_total_index = 0;
    for(int i = 0; message[i] != '\0'; i++)
    {
        if (0 == isdigit(message[i]))
        {
            message[new_total_index] = message[i];
            new_total_index++;
        }
    }
    message[new_total_index] = '\0';
    //appends null character to end of reformated string


    //Makes all letters uppercase
    for(int i = 0; message[i] != '\0'; i++)
    {
        if (0 == isdigit(message[i]))
        {
            message[i]=toupper(message[i]);
        }
    }
}
