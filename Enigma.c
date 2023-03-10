/******************************************************************************
 * File:    enigma_proj.c
 * Author:  Jake Klinger, Jose (Pillo) Duenas-Lopez, Tyler Bruno
 * Version: 0.1 (Mar 07, 2023)
 *
 * Purpose:
 *          A nifty program that encrypts and decrypts messages
 *
 * To Do List:
 *          []Review how we encrypt our message
 *          []Allow users to set encoding passphrase (currently, the encryptor
 *            function outputs the same encrypted phrase if the user types the
 *            same message)
 *          []Create menu Screen that allows to user to choose to encrypt or
 *            decrypt
 *          []Find a legal way to allow user to type more than 100 char message
 *            without giving too much memory to our code
 *          []Implement file input/output (i/o) to encrypt and decrypt messages
 *            to a text file, which the code (depending on what we decide) can
 *            use as an argument
 *
 * Notes:
 *          °Please add comments that convey your thought process
 *          °Please use standard C coding conventions:
 *               i) snake_case variable and function names
 *              ii) use brackets for "for" loops (even if the code is one line)
 *          °Don't be afraid to make longer variable names to more easily
 *           explain its purpose
 *              Ex. "int length" -> "int message_length"
 *
 * Reffrences:
 *
 *
 *****************************************************************************/

#include <stdio.h>
//basic i/o functions

#include<string.h>
//strlen function

#include <stdlib.h>
#include <time.h>
//to call and seed random function


//Function to Encrypt message
void encryptor(char *message);


int main()
{
    char message[100];
    //var to get user message

    printf("Enter message: ");
    scanf(" %s", message);
    //gets user message

    encryptor(message);
    //encrypts user message

    return 0;
}


//Function to Encrypt message
void encryptor(char *message)
{
    int message_length, random[100];
    //random[100] is for array to randomize 100 positions for message (100 pos-
    //itions)

    srand(1);

    message_length = strlen(message);
    //find string


    for(int i = 0; i < message_length; i++)
    {
        random[i] = (rand()%58+65);
    }
    //for every character in the user message generate a random number between
    //58-123


    for(int i = 0; i < message_length; i++)
    {
        printf("%d ", message[i]);

        if (message[i] >= random[i])
        {
            message[i] = (message[i] - random[i]) + 65;
        }
        else if (message[i] < random[i])
        {
            message[i] = (random[i] - message[i]) + 65;
        }
    }
    //for every character in the user message...Whats going on here? Why not
    //utlilize if statements to set a range of 65-122 (ASCII A-z) in place of
    //comparing the users message ASCII value to a random generated int?

    printf("|| ");

    for(int i = 0; i < message_length; i++)
    {
        printf(" %d ", (random[i]));
    }
    //prints out random array numbers utilized to encrypt user message

    printf("|| ");

    for(int i = 0; i < message_length; i++)
    {
        printf(" %d ", message[i]);
    }
    //prints out encrypted user message (ASCII numbers)

    printf(" %s\n", message);
    //prints out encrypted user message (Alphabet)
}
