/******************************************************************************
 * File:    enigma_proj.c
 * Author:  Jake Klinger, Jose (Pillo) Duenas-Lopez, Tyler (T-Dawg) Bruno
 * Version: 0.15 (Mar 18, 2023)

 * Purpose:
 *          A nifty program that encrypts and decrypts messages. This branch
 *          replicates the early analog function of the Enigma machine.
 *
 * To Do List:
 *          *Please read the website by 101computing and the guardian cited in
 *          the references section
 *
 *          [X]Get user input:
 *              1)  Get user message
 *              2)  Set rotor positions
 *              3)  Set switchboard (skipping for now)
 *
 *          []Create a three rotor function <<< CURRENTLY WORKING ON THIS
 *          []Implement deflector function
 *          []Create a switch board function (up for review)
 *
 *          []Create a decryption method
 *          []Fine tune
 *
 * Notes:
 *          °Finished step 2 on getting user input. Currently there is a bug
 *          that will skip reading in the user
 *
 * References:
 *          How The Enigma Works:
 *          °https://www.101computing.net/enigma/enigma-instructions.html
 *          °https://www.theguardian.com/technology/2014/nov/14/how-did-enigma-machine-work-imitation-game
 *
 *          Code Help:
 *          °https://www.educative.io/answers/how-to-remove-spaces-from-a-string-in-c
 *      
 *          Hard Wire Rotors:
 *          °https://hackaday.com/2017/08/22/the-enigma-enigma-how-the-enigma-machine-worked/
 *
 *          Rotor Sheet:
 *          °https://docs.google.com/spreadsheets/d/e/2PACX-1vRmON5SRXPrnoQghaJSrhbBFFNYLnJjPQOt1hKbfr99q6gwbxfU4B8qUEQg2Z-3A3x3OpXpFWCoSvqL/pubhtml
 *
 *****************************************************************************/

#include <stdio.h>
//basic i/o functions

#include <string.h>
//strlen function

#include <ctype.h>

#include <stdlib.h>
//malloc function


//Function to Encrypt message
void string_formatter( char *message);
char * set_rotor_positions( void );

int main( void )
{
    char message[100];
    char *rotor_positions;
    char r_pos[3];
    //var to get user message along with rotor position

    printf("Message:\n");
    scanf("%[^\n]", &*message);
    //gets user message (had to do the weird %[^\n] thing, because C would stop
    //reading in user input after the first space, when the %s alias was used)

    rotor_positions = set_rotor_positions();
    //gets rotor position (since we are allocating mem, whatever we want to
    //do with the rotor positions has to be sandwich inbetween the command
    //above and "free(rotor_position)"


    string_formatter(message);
    //reformats user message to make it easier to work with

    printf("Formated Message:\n%s\n", message);

    for (int i = 0; i <= 2; i++) {
        printf("Rotor %d is: %d\n", i, rotor_positions[i]);
    }

    free(rotor_positions);
}


//Function to format user message: reformats users message to remove all spaces
//numbers and special characters, and to change all lowercase letters uppercase
//Although this limits the capabilities of the program, it mimics the
//original enigma machine, and makes the program easier to code.
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


//Function to set all three rotor positions based on alphabet
char * set_rotor_positions( void )
{
    char *position=malloc(4);
    for(int i = 0; i <= 2; i++)
    {
        do
        {
        printf("Rotor Position %d:\n", i+1);
        scanf(" %c", &position[i]);
        }
        while(0 == isalpha(position[i]));

        position[i] = toupper(position[i])-65;
    }
    position[3] = '\0';

    return position;
}
