/******************************************************************************
 * File:    enigma_proj.c
 * Author:  Jake Klinger, Jose (Pillo) Duenas-Lopez, Tyler Bruno
 * Version: 0.1 (Mar 07, 2023)
 *
 * Purpose:
 *          A nifty program that encrypts and decrypts messages. This branch
 *          replicates the early analog function of the Enigma machine.
 *
 * To Do List:
 *          *Please read the webpage cited in the reference section*
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
 *
 *
 *****************************************************************************/

#include <stdio.h>
//basic i/o functions

#include<string.h>
//strlen function


//Function to Encrypt message
void string_formatter( char *message);


void string_int_print( char *message )
{
    int message_length = strlen(message);
    for(int i = 0; i < message_length; i++)
    {
        printf(" %d", message[i]);
    }
}


void string_char_print( char *message )
{
    int message_length = strlen(message);
    for(int i = 0; i < message_length; i++)
    {
        printf(" %c", message[i]);
    }
}


int main( void )
{
    char message[100];
    //var to get user message

    printf("Enter message: ");
    scanf("%[^\n]", message);
    //gets user message

    string_formatter(message);
    //encrypts user message
    string_char_print(message);
    string_int_print(message);



    return 0;
}


//Function to Encrypt message
void string_formatter(char *message)
{
    int message_length = strlen(message);

    for(int i = 0; i < message_length; i++)
    {
        if (message[i] >= 97 || message[i] <= 122 )
        {
            message[i] = message[i] - 32;
        }
        else if (message[i] >= 65 || message[i] <= 90 )
        {
            message[i] = message[i] - 32;
        }
        else if (message[i] == 32)
        {
            message[i] = 'a';
        }
    }
    //for every index in the user message check...
    //if the element is a lowercase. If so, change ASCII value to its uppercase
    //if the element is a uppercase. If so, do nothing
    //if the element is not a letter. If so, change value to an underscore
//
//    printf("|| ");
//
//    for(int i = 0; i < message_length; i++)
//    {
//        printf(" %d ", (random[i]));
//    }
//    //prints out random array numbers utilized to encrypt user message
//
//    printf("|| ");
//
//    for(int i = 0; i < message_length; i++)
//    {
//        printf(" %d ", message[i]);
//    }
//    //prints out encrypted user message (ASCII numbers)
//
//    printf(" %s\n", message);
//    //prints out encrypted user message (Alphabet)
}
